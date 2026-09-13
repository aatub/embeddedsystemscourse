// tehävä ei ole vielä valmis, päivittelen myöhemmin, mutta tässä toimiva versio 1p arvoisesta tehtävästä.

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/uart.h>
#include <string.h>

static const struct gpio_dt_spec red = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
static const struct gpio_dt_spec green = GPIO_DT_SPEC_GET(DT_ALIAS(led1), gpios);
static const struct gpio_dt_spec blue = GPIO_DT_SPEC_GET(DT_ALIAS(led2), gpios);

#define UART_DEVICE_NODE DT_CHOSEN(zephyr_shell_uart)
static const struct device *const uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);

K_FIFO_DEFINE(dispatcher_fifo);
K_SEM_DEFINE(task_release_sem, 0, 1);
K_MUTEX_DEFINE(sync_mutex);
K_CONDVAR_DEFINE(red_condvar);
K_CONDVAR_DEFINE(yellow_condvar);
K_CONDVAR_DEFINE(green_condvar);

enum led_signal {
    SIG_NONE = 0,
    SIG_RED,
    SIG_YELLOW,
    SIG_GREEN
};
static enum led_signal current_signal = SIG_NONE;

struct data_t {
    void *fifo_reserved;
    char msg[20];
};

// Thread Initializations
#define STACKSIZE 1024
#define PRIORITY 5

static void uart_task(void *, void *, void *);
static void dispatcher_task(void *, void *, void *);
void red_led_task(void *, void *, void *);
void yellow_led_task(void *, void *, void *);
void green_led_task(void *, void *, void *);
K_THREAD_DEFINE(uart_thread, STACKSIZE, uart_task, NULL, NULL, NULL, PRIORITY, 0, 0);
K_THREAD_DEFINE(dis_thread, STACKSIZE, dispatcher_task, NULL, NULL, NULL, PRIORITY, 0, 0);
K_THREAD_DEFINE(red_thread, STACKSIZE, red_led_task, NULL, NULL, NULL, PRIORITY, 0, 0);
K_THREAD_DEFINE(yellow_thread, STACKSIZE, yellow_led_task, NULL, NULL, NULL, PRIORITY, 0, 0);
K_THREAD_DEFINE(green_thread, STACKSIZE, green_led_task, NULL, NULL, NULL, PRIORITY, 0, 0);

int init_hardware(void) {
    gpio_pin_configure_dt(&red, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&green, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&blue, GPIO_OUTPUT_INACTIVE);

    if (!device_is_ready(uart_dev)) {
        printk("UART initialization failed!\n");
        return -1;
    }
    return 0;
}

int main(void) {
    init_hardware();
    printk("system ready.\n");
    return 0;
}

static void uart_task(void *unused1, void *unused2, void *unused3) {
    char rc = 0;
    char uart_msg[20];
    memset(uart_msg, 0, 20);
    int uart_msg_cnt = 0;

    while (true) {
        if (uart_poll_in(uart_dev, &rc) == 0) {
            if (rc != '\r' && rc != '\n') {
                if (uart_msg_cnt < 19) {
                    uart_msg[uart_msg_cnt++] = rc;
                }
            } else if (uart_msg_cnt > 0) {
                uart_msg[uart_msg_cnt] = '\0';
                printk("UART msg: %s\n", uart_msg);

                struct data_t *buf = k_malloc(sizeof(struct data_t));
                if (buf != NULL) {
                    snprintf(buf->msg, sizeof(buf->msg), "%s", uart_msg);
                    k_fifo_put(&dispatcher_fifo, buf);
                }

                uart_msg_cnt = 0;
                memset(uart_msg, 0, 20);
            }
        }
        k_msleep(10);
    }
}

static void dispatcher_task(void *unused1, void *unused2, void *unused3) {
    while (true) {
        struct data_t *rec_item = k_fifo_get(&dispatcher_fifo, K_FOREVER);
        char sequence[20];
        memcpy(sequence, rec_item->msg, 20);
        k_free(rec_item);

        printk("Dispatcher sequence: %s\n", sequence);
        for (int i = 0; sequence[i] != '\0'; i++) {
            char color = sequence[i];

            k_mutex_lock(&sync_mutex, K_FOREVER);
            if (color == 'R' || color == 'r') {
                current_signal = SIG_RED;
                k_condvar_signal(&red_condvar);
            } else if (color == 'Y' || color == 'y') {
                current_signal = SIG_YELLOW;
                k_condvar_signal(&yellow_condvar);
            } else if (color == 'G' || color == 'g') {
                current_signal = SIG_GREEN;
                k_condvar_signal(&green_condvar);
            } else {
                k_mutex_unlock(&sync_mutex);
                continue;
            }
            k_mutex_unlock(&sync_mutex);
            k_sem_take(&task_release_sem, K_FOREVER);
        }
    }
}
void red_led_task(void *, void *, void *) {
    while (true) {
        k_mutex_lock(&sync_mutex, K_FOREVER);
        while (current_signal != SIG_RED) {
            k_condvar_wait(&red_condvar, &sync_mutex, K_FOREVER);
        }
        current_signal = SIG_NONE;
        k_mutex_unlock(&sync_mutex);
        gpio_pin_set_dt(&red, 1);
        printk("LED: RED ON\n");
        k_msleep(1000);
        gpio_pin_set_dt(&red, 0);
        k_sem_give(&task_release_sem);
    }
}

void yellow_led_task(void *, void *, void *) {
    while (true) {
        k_mutex_lock(&sync_mutex, K_FOREVER);
        while (current_signal != SIG_YELLOW) {
            k_condvar_wait(&yellow_condvar, &sync_mutex, K_FOREVER);
        }
        current_signal = SIG_NONE;
        k_mutex_unlock(&sync_mutex);
        gpio_pin_set_dt(&red, 1);
        gpio_pin_set_dt(&green, 1);
        printk("LED: YELLOW ON\n");
        k_msleep(1000);
        gpio_pin_set_dt(&red, 0);
        gpio_pin_set_dt(&green, 0);
        k_sem_give(&task_release_sem);
    }
}

void green_led_task(void *, void *, void *) {
    while (true) {
        k_mutex_lock(&sync_mutex, K_FOREVER);
        while (current_signal != SIG_GREEN) {
            k_condvar_wait(&green_condvar, &sync_mutex, K_FOREVER);
        }
        current_signal = SIG_NONE;
        k_mutex_unlock(&sync_mutex);
        gpio_pin_set_dt(&green, 1);
        printk("LED: GREEN ON\n");
        k_msleep(1000);
        gpio_pin_set_dt(&green, 0);
        k_sem_give(&task_release_sem);
    }
}
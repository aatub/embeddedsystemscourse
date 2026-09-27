//vielä kesken, jatkan myöhemmin, mutrta 1p arvoisen tehtävä valmis


#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/uart.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

static const struct gpio_dt_spec red = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
#define UART_DEVICE_NODE DT_CHOSEN(zephyr_shell_uart)
static const struct device *const uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);

#define PARSE_SUCCESS           0
#define ERROR_INVALID_FORMAT   -1
#define ERROR_INVALID_HOURS    -2
#define ERROR_INVALID_MINUTES  -3
#define ERROR_INVALID_SECONDS  -4
#define ERROR_NULL_POINTER     -5

int time_parse(const char *time_str) {
    if (time_str == NULL) return ERROR_NULL_POINTER;
    if (strlen(time_str) != 6) return ERROR_INVALID_FORMAT;
    for (int i = 0; i < 6; i++) {
        if (!isdigit((unsigned char)time_str[i])) return ERROR_INVALID_FORMAT;
    }
    char h_str[3] = { time_str[0], time_str[1], '\0' };
    char m_str[3] = { time_str[2], time_str[3], '\0' };
    char s_str[3] = { time_str[4], time_str[5], '\0' };
    int hours = atoi(h_str);
    int minutes = atoi(m_str);
    int seconds = atoi(s_str);
    if (hours < 0 || hours > 23) return ERROR_INVALID_HOURS;
    if (minutes < 0 || minutes > 59) return ERROR_INVALID_MINUTES;
    if (seconds < 0 || seconds > 59) return ERROR_INVALID_SECONDS;
    return (minutes * 60) + seconds;
}

static struct k_timer traffic_timer;

void timer_expiry_handler(struct k_timer *dummy) {
    printk("\n[TIMER INTERRUPT EXPIRED!] RED LED ON for 3s\n");
    gpio_pin_set_dt(&red, 1);
    k_msleep(3000);
    gpio_pin_set_dt(&red, 0);
    printk("[TIMER INTERRUPT COMPLETED] RED LED OFF\n");
}
#define STACKSIZE 1024
#define PRIORITY 5

static void uart_task(void *, void *, void *) {
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
                printk("\nUART time string received: '%s'\n", uart_msg);

                int seconds = time_parse(uart_msg);

                if (seconds >= 0) {
                    printk("Valid time! Starting timer interrupt for %d seconds...\n", seconds);
                    k_timer_start(&traffic_timer, K_SECONDS(seconds), K_NO_WAIT);
                } else {
                    printk("ERROR: Invalid time string (code: %d)\n", seconds);
                }

                uart_msg_cnt = 0;
                memset(uart_msg, 0, 20);
            }
        }
        k_msleep(10);
    }
}
K_THREAD_DEFINE(uart_thread, STACKSIZE, uart_task, NULL, NULL, NULL, PRIORITY, 0, 0);

int main(void) {
    gpio_pin_configure_dt(&red, GPIO_OUTPUT_INACTIVE);
    if (!device_is_ready(uart_dev)) {
        printk("UART device not ready!\n");
        return -1;
    }
    k_timer_init(&traffic_timer, timer_expiry_handler, NULL);
    printk("hw5: Traffic Light with Timer Interrupt ready.\n");
    printk("Send HHMMSS (e.g. '000005') via UART.\n");
    return 0;
}

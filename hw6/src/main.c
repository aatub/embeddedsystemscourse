#include <zephyr/kernel.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/sys/printk.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UART_NODE DT_CHOSEN(zephyr_shell_uart)
static const struct device *const uart_dev = DEVICE_DT_GET(UART_NODE);
#define MSG_SIZE 64
static char rx_buf[MSG_SIZE];
static int rx_buf_pos = 0;

// jos merkkijono virheellinen niin palauttaa -1
int time_parse(const char *str) {
    int len = strlen(str);
    while (len>0 && (str[len - 1] == '\r' || str[len-1] == '\n')) {
        len--;
    }
    if (len!=6) {
        return -1;
    }
    for (int i=0; i<len; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return -1;
        }
    }

    int hours = (str[0] - '0') * 10 + (str[1] - '0');
    int minutes = (str[2] - '0') * 10 + (str[3] - '0');
    int seconds = (str[4] - '0') * 10 + (str[5] - '0');
    if (seconds >= 60 || minutes >= 60) {
        return -1;
    }

    return (hours *3600) + (minutes * 60) + seconds;
}

static void serial_cb(const struct device *dev, void *user_data) {
    uint8_t c;
    if (!uart_irq_update(dev)) {
        return;
    }
    while (uart_irq_rx_ready(dev)) {
        uart_fifo_read(dev, &c, 1);

        if ((c=='\n' || c=='\r') && rx_buf_pos > 0) {
            rx_buf[rx_buf_pos] = '\0';
            int result = time_parse(rx_buf);
            printk("%d\r\n", result);
            rx_buf_pos = 0;
        } else if (rx_buf_pos < MSG_SIZE - 1) {
            if (c != '\n' && c != '\r') {
                rx_buf[rx_buf_pos++] = c;
            }
        }
    }
}

int main(void) {
    if (!device_is_ready(uart_dev)) {
        return 0;
    }

    uart_irq_callback_user_data_set(uart_dev, serial_cb, NULL);
    uart_irq_rx_enable(uart_dev);
    while (1) {
        k_sleep(K_FOREVER);
    }
    return 0;
}
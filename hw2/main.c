// jos arvointi asteikko on 1-5 niin tavoittelen tästä viikkotehtävästä arvosanaa 3, sain
// tehtyä kaikki paitsi viimeisen tehtävän ja koodia olisi voinut siistiä/kommentoida vähän enemmän.
// Eli aika keskinkertainen suoritus.

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/util.h>
#include <inttypes.h>

// Led pin configurations
static const struct gpio_dt_spec red = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
static const struct gpio_dt_spec green = GPIO_DT_SPEC_GET(DT_ALIAS(led1), gpios);
static const struct gpio_dt_spec blue = GPIO_DT_SPEC_GET(DT_ALIAS(led2), gpios);

// Button configurations
#define BUTTON_0 DT_ALIAS(sw0)
static const struct gpio_dt_spec button_0 = GPIO_DT_SPEC_GET_OR(BUTTON_0, gpios, {0});
static struct gpio_callback button_0_data;

volatile int led_state = 0;
volatile int previous_state = 0;

// Thread initializations (all)
#define STACKSIZE 500
#define PRIORITY 5
void red_led_task(void *, void *, void *);
void yellow_led_task(void *, void *, void *);
void green_led_task(void *, void *, void *);
K_THREAD_DEFINE(red_thread, STACKSIZE, red_led_task, NULL, NULL, NULL, PRIORITY, 0, 0);
K_THREAD_DEFINE(yellow_thread, STACKSIZE, yellow_led_task, NULL, NULL, NULL, PRIORITY, 0, 0);
K_THREAD_DEFINE(green_thread, STACKSIZE, green_led_task, NULL, NULL, NULL, PRIORITY, 0, 0);
int init_led(void);
int init_button(void);

void button_0_handler(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    printk("Button pressed\n");

    if (led_state!=4) {
        previous_state = led_state;
        led_state =4;
    } else {
        led_state=previous_state;
    }
}



// Main program
int main(void)
{
    if (init_led() < 0) return 0;
	if (init_button() < 0) return 0;

    while (true) {
        k_msleep(1000);
    }

    return 0;
}

// Initialize leds
int init_led(void) {
    int ret;

    ret = gpio_pin_configure_dt(&red, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) return ret;
    gpio_pin_set_dt(&red, 0);

    ret = gpio_pin_configure_dt(&green, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) return ret;
    gpio_pin_set_dt(&green, 0);

    ret = gpio_pin_configure_dt(&blue, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) return ret;
    gpio_pin_set_dt(&blue, 0);
    printk("Leds ok\n"); //debuggi

    return 0;
}

// Initialize button
int init_button(void) {
    int ret;

    if (!gpio_is_ready_dt(&button_0)) {
        printk("Error: button 0 is not ready\n");
        return -1;
    }
    ret = gpio_pin_configure_dt(&button_0, GPIO_INPUT);
    if (ret!=0) return -1;
    ret = gpio_pin_interrupt_configure_dt(&button_0, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret!=0) return -1;
    gpio_init_callback(&button_0_data, button_0_handler, BIT(button_0.pin));
    gpio_add_callback(button_0.port, &button_0_data);

    return 0;
}

// Task to handle red led
void red_led_task(void *, void *, void *) {
    printk("Red led thread started\n");
    while (true) {
        if (led_state==0) {
            gpio_pin_set_dt(&red, 1);
            printk("Red on\n");
            k_msleep(1000);
            gpio_pin_set_dt(&red, 0);
            printk("Red off\n");
            if (led_state != 4) {
                led_state = 1;
            }
        }
        k_msleep(100);
    }
}


// Task to handle yellow led
void yellow_led_task(void *, void *, void *) {
    printk("Yellow led thread started\n");
    while (true) {
        if (led_state == 1) {
            gpio_pin_set_dt(&red, 1);
            gpio_pin_set_dt(&green, 1);
            printk("Yellow on\n");
            k_msleep(1000);
            gpio_pin_set_dt(&red,0);
            gpio_pin_set_dt(&green,0);
            printk("Yellow off\n");
            if (led_state!=4) {
                led_state =2;
            }
        }
        k_msleep(100);
    }
}

// Task to handle green led
void green_led_task(void *, void *, void *) {
    printk("Green led thread started\n");
    while (true) {
        if (led_state == 2) {
            gpio_pin_set_dt(&green, 1);
            printk("Green on\n");
            k_msleep(1000);
            gpio_pin_set_dt(&green, 0);
            printk("Green off\n");
			if (led_state != 4) {
                led_state= 0;
            }
        }
        k_msleep(100);
    }
}
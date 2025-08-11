/*
 * Ola Task1 - Simple LED blink example using Zephyr GPIO API on nRF52840
 * This program toggles an LED on and off every second and prints the status via UART.
 */
#include <zephyr/kernel.h>       // Zephyr kernel API (e.g., k_msleep)
#include <zephyr/drivers/gpio.h> // GPIO driver API
#include <stdio.h>               // Standard I/O for printf

// Define an alias for the LED node from the device tree
#define LED0_NODE DT_ALIAS(led0)

// Get the GPIO specification (device, pin number, flags) for the LED from device tree
static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
        // Check if the GPIO device controlling the LED is ready
        if (!device_is_ready(led0.port))
        {
                // If device is not ready, return with error code -1
                return -1;
        }

        // Configure the LED pin as an output
        int ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT);

        // Check if the pin configuration was successful
        if (ret < 0)
        {
                // If failed, return the error code
                return ret;
        }

        int toggle_count = 0; // Counter to keep track of how many times LED toggled

        // Infinite loop to toggle LED state on and off
        while (1)
        {
                // Set the LED pin to high (turn LED ON)
                gpio_pin_set_dt(&led0, 1);

                // Print the current LED state and toggle count over UART/console
                printf("LED is now ON (toggle #%d)\n", ++toggle_count);

                // Sleep/delay for 1000 milliseconds (1 second)
                k_msleep(1000);

                // Set the LED pin to low (turn LED OFF)
                gpio_pin_set_dt(&led0, 0);

                // Print the current LED state and toggle count
                printf("LED is now OFF (toggle #%d)\n", toggle_count);

                // Sleep/delay for another 1 second
                k_msleep(1000);
        }

        //  normal termination (never reached in this example)
        return 0;
}

# nRF52840 Blinky Example

This is a simple LED blink project for the Nordic nRF52840 Development Kit using the Zephyr RTOS GPIO API. The program toggles an onboard LED on and off every second and prints the LED state over UART.

## Features

- Configures GPIO pin connected to LED as output
- Toggles LED every 1 second
- Prints LED status messages via UART console

## Requirements

- Nordic nRF52840 Development Kit (DK) or compatible board
- Zephyr SDK and Toolchain installed
- Visual Studio Code with nRF Connect extension (recommended)
- Renode simulator (optional for simulation without hardware)

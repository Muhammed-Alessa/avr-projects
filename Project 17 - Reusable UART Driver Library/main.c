/*
 * Reusable UART Driver Library
 * Board: Arduino Uno R3
 * MCU: ATmega328P
 * Toolchain: AVR-GCC
 *
 * Bare-metal AVR C. No Arduino framework functions are used.
 * Independently rewritten from the concepts studied in "Simply AVR".
 */

#define F_CPU 16000000UL

#include "uart.h"
#include <util/delay.h>

int main(void)
{
    uart_init(9600);

    while (1)
    {
        uart_send_string("UART driver library test\r\n");
        _delay_ms(1000);
    }
}

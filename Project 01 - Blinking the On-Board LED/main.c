/*
 * Blinking the On-Board LED
 * Board: Arduino Uno R3
 * MCU: ATmega328P
 * Toolchain: AVR-GCC
 *
 * Bare-metal AVR C. No Arduino framework functions are used.
 * Independently rewritten from the concepts studied in "Simply AVR".
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1U << DDB5);        // PB5 / Arduino D13 as output

    while (1)
    {
        PORTB ^= (1U << PORTB5); // Toggle the built-in LED
        _delay_ms(1000);
    }
}

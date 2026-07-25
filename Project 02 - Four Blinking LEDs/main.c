/*
 * Four Blinking LEDs
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

#define LED_MASK ((1U << PD2) | (1U << PD3) | (1U << PD4) | (1U << PD5))

int main(void)
{
    DDRD |= LED_MASK;    // Arduino D2-D5 as outputs

    while (1)
    {
        PORTD |= LED_MASK;
        _delay_ms(500);

        PORTD &= (uint8_t)~LED_MASK;
        _delay_ms(500);
    }
}

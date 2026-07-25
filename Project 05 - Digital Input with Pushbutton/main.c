/*
 * Digital Input with Pushbutton
 * Board: Arduino Uno R3
 * MCU: ATmega328P
 * Toolchain: AVR-GCC
 *
 * Bare-metal AVR C. No Arduino framework functions are used.
 * Independently rewritten from the concepts studied in "Simply AVR".
 */

#define F_CPU 16000000UL

#include <avr/io.h>

int main(void)
{
    DDRB |= (1U << DDB5);         // LED output: D13 / PB5
    DDRD &= (uint8_t)~(1U << DDD2); // Button input: D2 / PD2

    while (1)
    {
        if (PIND & (1U << PIND2))
            PORTB |= (1U << PORTB5);
        else
            PORTB &= (uint8_t)~(1U << PORTB5);
    }
}

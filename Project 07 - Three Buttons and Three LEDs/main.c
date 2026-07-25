/*
 * Three Buttons and Three LEDs
 * Board: Arduino Uno R3
 * MCU: ATmega328P
 * Toolchain: AVR-GCC
 *
 * Bare-metal AVR C. No Arduino framework functions are used.
 * Independently rewritten from the concepts studied in "Simply AVR".
 */

#define F_CPU 16000000UL

#include <avr/io.h>

#define BUTTONS ((1U << PD2) | (1U << PD3) | (1U << PD4))
#define LEDS    ((1U << PB0) | (1U << PB1) | (1U << PB2))

int main(void)
{
    DDRD &= (uint8_t)~BUTTONS;
    PORTD |= BUTTONS;  // Internal pull-ups

    DDRB |= LEDS;

    while (1)
    {
        PORTB &= (uint8_t)~LEDS;

        if ((PIND & (1U << PD2)) == 0)
            PORTB |= (1U << PB0);

        if ((PIND & (1U << PD3)) == 0)
            PORTB |= (1U << PB0) | (1U << PB1);

        if ((PIND & (1U << PD4)) == 0)
            PORTB |= LEDS;
    }
}

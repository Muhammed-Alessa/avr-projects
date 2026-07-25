/*
 * Pushbutton with Internal Pull-Up
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
    DDRB |= (1U << DDB5);           // Built-in LED output
    DDRD &= (uint8_t)~(1U << DDD2); // D2 input
    PORTD |= (1U << PORTD2);        // Enable internal pull-up

    while (1)
    {
        if ((PIND & (1U << PIND2)) == 0)
            PORTB |= (1U << PORTB5);
        else
            PORTB &= (uint8_t)~(1U << PORTB5);
    }
}

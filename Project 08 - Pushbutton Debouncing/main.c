/*
 * Pushbutton Debouncing
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
#include <stdint.h>

static uint8_t button_pressed(void)
{
    if ((PIND & (1U << PIND2)) == 0)
    {
        _delay_ms(20);

        if ((PIND & (1U << PIND2)) == 0)
        {
            while ((PIND & (1U << PIND2)) == 0)
            {
                // Wait for release
            }

            _delay_ms(20);
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    DDRB |= (1U << DDB5);

    DDRD &= (uint8_t)~(1U << DDD2);
    PORTD |= (1U << PORTD2);

    while (1)
    {
        if (button_pressed())
            PORTB ^= (1U << PORTB5);
    }
}

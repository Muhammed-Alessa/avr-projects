/*
 * DC Motor On-Off Control
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
    DDRB |= (1U << DDB0); // D8 drives the motor-driver input

    while (1)
    {
        PORTB |= (1U << PORTB0);
        _delay_ms(2000);

        PORTB &= (uint8_t)~(1U << PORTB0);
        _delay_ms(2000);
    }
}

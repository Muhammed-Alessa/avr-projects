/*
 * Using PORTB and PORTD as Outputs
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
    // D2-D7 = PD2-PD7
    DDRD |= 0b11111100;

    // D8-D13 = PB0-PB5
    DDRB |= 0b00111111;

    while (1)
    {
        PORTD = (PORTD & 0b00000011) | 0b10101000;
        PORTB = (PORTB & 0b11000000) | 0b00010101;
        _delay_ms(500);

        PORTD = (PORTD & 0b00000011) | 0b01010100;
        PORTB = (PORTB & 0b11000000) | 0b00101010;
        _delay_ms(500);
    }
}

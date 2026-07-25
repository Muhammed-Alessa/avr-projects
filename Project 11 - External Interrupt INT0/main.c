/*
 * External Interrupt INT0
 * Board: Arduino Uno R3
 * MCU: ATmega328P
 * Toolchain: AVR-GCC
 *
 * Bare-metal AVR C. No Arduino framework functions are used.
 * Independently rewritten from the concepts studied in "Simply AVR".
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect)
{
    PORTB ^= (1U << PORTB0); // Toggle external LED on D8
}

int main(void)
{
    DDRB |= (1U << DDB5) | (1U << DDB0);

    DDRD &= (uint8_t)~(1U << DDD2); // INT0 = PD2 = Arduino D2
    PORTD |= (1U << PORTD2);        // Internal pull-up

    // INT0 on falling edge
    EICRA = (EICRA & (uint8_t)~((1U << ISC00) | (1U << ISC01))) |
            (1U << ISC01);

    EIFR |= (1U << INTF0);  // Clear any pending flag
    EIMSK |= (1U << INT0);  // Enable INT0
    sei();

    while (1)
    {
        PORTB ^= (1U << PORTB5);
        _delay_ms(100);
    }
}

/*
 * External Interrupts INT0 and INT1
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

ISR(INT0_vect)
{
    PORTB ^= (1U << PORTB0);
}

ISR(INT1_vect)
{
    PORTB ^= (1U << PORTB1);
}

int main(void)
{
    DDRB |= (1U << DDB0) | (1U << DDB1);

    DDRD &= (uint8_t)~((1U << DDD2) | (1U << DDD3));
    PORTD |= (1U << PORTD2) | (1U << PORTD3);

    // Falling edge on INT0 and INT1
    EICRA = (1U << ISC01) | (1U << ISC11);

    EIFR |= (1U << INTF0) | (1U << INTF1);
    EIMSK |= (1U << INT0) | (1U << INT1);

    sei();

    while (1)
    {
        // Main program is free for other work.
    }
}

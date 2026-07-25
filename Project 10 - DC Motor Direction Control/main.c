/*
 * DC Motor Direction Control
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

#define IN1 PB0
#define IN2 PB1

static void motor_stop(void)
{
    PORTB &= (uint8_t)~((1U << IN1) | (1U << IN2));
}

static void motor_forward(void)
{
    PORTB |= (1U << IN1);
    PORTB &= (uint8_t)~(1U << IN2);
}

static void motor_reverse(void)
{
    PORTB &= (uint8_t)~(1U << IN1);
    PORTB |= (1U << IN2);
}

int main(void)
{
    DDRB |= (1U << DDB0) | (1U << DDB1);

    while (1)
    {
        motor_forward();
        _delay_ms(2000);

        motor_stop();
        _delay_ms(500);

        motor_reverse();
        _delay_ms(2000);

        motor_stop();
        _delay_ms(2000);
    }
}

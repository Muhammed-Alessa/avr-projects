/*
 * 7-Segment LED Counter
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

/*
 * Segments:
 * a=PB0 (D8), b=PB1 (D9), c=PB2 (D10),
 * d=PB3 (D11), e=PB4 (D12), f=PB5 (D13),
 * g=PD7 (D7)
 *
 * Bit order in table: gfedcba
 */
static const uint8_t digits[10] =
{
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

static void display_digit(uint8_t value)
{
    uint8_t pattern = digits[value];

    PORTB = (PORTB & 0xC0U) | (pattern & 0x3FU);

    if (pattern & (1U << 6))
        PORTD |= (1U << PD7);
    else
        PORTD &= (uint8_t)~(1U << PD7);
}

int main(void)
{
    DDRB |= 0x3FU;
    DDRD |= (1U << DDD7);

    while (1)
    {
        for (uint8_t i = 0; i < 10; ++i)
        {
            display_digit(i);
            _delay_ms(1000);
        }
    }
}

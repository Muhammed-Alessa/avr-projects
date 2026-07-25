/*
 * ADC Potentiometer Reading
 * Board: Arduino Uno R3
 * MCU: ATmega328P
 * Toolchain: AVR-GCC
 *
 * Bare-metal AVR C. No Arduino framework functions are used.
 * Independently rewritten from the concepts studied in "Simply AVR".
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdint.h>

static void adc_init(void)
{
    // AVcc reference, left-adjust result so ADCH contains the upper 8 bits.
    ADMUX = (1U << REFS0) | (1U << ADLAR) | (1U << MUX0); // ADC1 / PC1 / A1

    // ADC enable, prescaler 128 -> 125 kHz ADC clock at 16 MHz.
    ADCSRA = (1U << ADEN) |
             (1U << ADPS2) |
             (1U << ADPS1) |
             (1U << ADPS0);
}

static uint8_t adc_read_8bit(void)
{
    ADCSRA |= (1U << ADSC);

    while (ADCSRA & (1U << ADSC))
    {
    }

    return ADCH;
}

static void leds_write(uint8_t value)
{
    // Value bits 0-5 -> D2-D7 (PD2-PD7)
    PORTD = (PORTD & 0x03U) | ((value & 0x3FU) << 2);

    // Value bits 6-7 -> D8-D9 (PB0-PB1)
    PORTB = (PORTB & 0xFCU) | ((value >> 6) & 0x03U);
}

int main(void)
{
    DDRD |= 0xFCU;
    DDRB |= (1U << DDB0) | (1U << DDB1);

    adc_init();

    while (1)
        leds_write(adc_read_8bit());
}

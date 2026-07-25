/*
 * UART Receiver
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

#define BAUD 9600UL
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1UL)

static void uart_init(void)
{
    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)UBRR_VALUE;

    UCSR0B = (1U << RXEN0) | (1U << TXEN0);
    UCSR0C = (1U << UCSZ01) | (1U << UCSZ00); // 8-N-1
}

static void uart_send_char(char c)
{
    while ((UCSR0A & (1U << UDRE0)) == 0)
    {
    }

    UDR0 = c;
}

static char uart_receive_char(void)
{
    while ((UCSR0A & (1U << RXC0)) == 0)
    {
    }

    return (char)UDR0;
}

int main(void)
{
    DDRB |= (1U << DDB5);
    uart_init();

    while (1)
    {
        char c = uart_receive_char();

        if (c == '1')
            PORTB |= (1U << PORTB5);
        else if (c == '0')
            PORTB &= (uint8_t)~(1U << PORTB5);
    }
}

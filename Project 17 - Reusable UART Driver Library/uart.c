#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdint.h>
#include "uart.h"

void uart_init(uint32_t baud)
{
    uint16_t ubrr = (uint16_t)((F_CPU / (16UL * baud)) - 1UL);

    UBRR0H = (uint8_t)(ubrr >> 8);
    UBRR0L = (uint8_t)ubrr;

    UCSR0B = (1U << RXEN0) | (1U << TXEN0);
    UCSR0C = (1U << UCSZ01) | (1U << UCSZ00);
}

void uart_send_char(char c)
{
    while ((UCSR0A & (1U << UDRE0)) == 0)
    {
    }

    UDR0 = c;
}

char uart_receive_char(void)
{
    while ((UCSR0A & (1U << RXC0)) == 0)
    {
    }

    return (char)UDR0;
}

void uart_send_string(const char *text)
{
    while (*text != '\0')
        uart_send_char(*text++);
}

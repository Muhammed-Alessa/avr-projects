#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init(uint32_t baud);
void uart_send_char(char c);
char uart_receive_char(void);
void uart_send_string(const char *text);

#endif

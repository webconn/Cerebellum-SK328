#ifndef SK328_UART
#define SK328_UART

#include <avr/io.h>
#include <inttypes.h>
#include <sk328/delay.h>
#include <stdio.h>

#define BAUD 9600
#define UBRR F_CPU/16/BAUD-1

void uart_init(unsigned int ubrr);
void uart_write(unsigned char data);
unsigned char uart_read(void);

#endif
#include <sk328/uart.h>

FILE usart0_str = FDEV_SETUP_STREAM(uart_write, NULL, _FDEV_SETUP_WRITE);

void uart_init(unsigned int ubrr)
{
  UBRR0H = (unsigned char)(ubrr>>8);
  UBRR0L = (unsigned char)ubrr;
  UCSR0B = (1<<RXEN0) | (1<<TXEN0);
  UCSR0C = (1<<USBS0) | (3<<UCSZ00);
  stdout=&usart0_str;
}
void uart_write(unsigned char data)
{
  while (!(UCSR0A & (1<<UDRE0)));
  UDR0 = data;
}
unsigned char uart_read(void)
{
  while (!(UCSR0A & (1<<RXC0)));
  return UDR0;
}

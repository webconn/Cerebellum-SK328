#include <sk328/delay.h>

void delay(unsigned int time) {
  while(time--) {
    _delay_ms(1);
  }
} 
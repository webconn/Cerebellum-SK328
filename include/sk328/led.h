#ifndef SK328_LED
#define SK328_LED

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h> 
#include <sk328/delay.h>
void led_init();
void toggle_led();
void blink_led(int delay);

#endif
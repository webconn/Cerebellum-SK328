#include <sk328/led.h>

int toggle = 0;
void led_init()
{
  DDRD=1<<6; 
}
void toggle_led()
{
  if(toggle == 0) { toggle = 1; PORTD=1<<6; }
  else { toggle = 0; PORTD^=1<<6; }
}
void blink_led(int delay_time)
{
  toggle_led();
  delay(delay_time);
  toggle_led();
  delay(delay_time); 
}
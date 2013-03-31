#include <arch/antares.h> 
#include <avr/io.h> 
#include <util/delay.h> 
#include <stdio.h> 
#include <stdint.h> 
#include <sk328/uart.h>
#include <sk328/led.h>
#include <sk328/delay.h>
#include <sk328/xthread.h>
#include <sk328/init.h>
#include <sk328/adc.h>


int main(void)
{
   initall(1); //main initialisation; not to comment
   // ---------------testing space------------------
   adc_test();
   // ---------------end of testing-----------------
   xthread_refexec(1000, 1);
   //while(1) blink_led(100);
   return 0;
}


#include <sk328/xthread.h>
#include <sk328/delay.h>
#include <sk328/led.h>
#include <stdio.h>
#include <sk328/odetect.h>

void xthread_refexec(int stime, int ctime) //main process exectuion (startup time, cycle time)
{
  printf("Skipping stime\n\r");  
  delay(stime);
  printf("OK!\n\r");  
  while(1)
  {
    main_xthread(ctime);
  }
}
void main_xthread(ctime) //main process (cycle time) 
{
  unsigned char data;
  data=uart_read();
  //    if(data=='h')
  blink_led(10);
  //printf("odetect_process();\n\r");
  odetect_process();
  delay(ctime);	
}

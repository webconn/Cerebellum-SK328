#ifndef SK328_XTHREAD
#define SK328_XTHREAD
#include <util/delay.h> 
#include <avr/io.h>
#include <inttypes.h>
#include <sk328/uart.h>

void xthread_refexec(int stime, int ctime); //main process exectuion (startup time, cycle time)
void main_xthread(int ctime); //main process (cycle time) 

#endif
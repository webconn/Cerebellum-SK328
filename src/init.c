#include <sk328/init.h>

void initall(int verbose) //main initialisation
{
    //asset MCU UART to standart out
   uart_init(UBRR);    //init MCU UART
   led_init();
   if(verbose) //do some dbg info
   {
    printf("Loading\n\r");     
    printf("Hello world\n\r");
    printf("Odetect pre-alpha v3.01\n\r");  
    printf("running antares 1.0\n\r"); 
    printf("d for debug (0-1, r, s)\n\r");
    printf("h - odetect_process();\n\r");
   }
}

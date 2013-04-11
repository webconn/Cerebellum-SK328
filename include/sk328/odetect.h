#ifndef SK328_ODETECT_H
#define SK328_ODETECT_H

#include <avr/io.h>
#include <sk328/uart.h>
#include <sk328/adc.h>

void odetect_init(void);
void odetect_process(void);

#endif

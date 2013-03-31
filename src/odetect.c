#include <avr/io.h>
#include <sk328/uart.h>
#include <sk328/delay.h>
#include <sk328/adc.h>

#define CH0_EN 1
#define CH1_EN 1
#define CH2_EN 1
#define CH3_EN 1
#define CH4_EN 1
#define CH5_EN 1
#define CH6_EN 1
#define CH7_EN 1

void odetect_init()
{
	adc_init();
	if(CH0_EN) adc_set(0);
	if(CH1_EN) adc_set(1);
	if(CH2_EN) adc_set(2);
	if(CH3_EN) adc_set(3);
	
}

#include <avr/io.h>
#include <avr/interrupt.h>
#include <sk328/uart.h>
#include <sk328/delay.h>

void tim0_init(void);
void tim0_start(void);
void tim0_stop(void);
void adc_init();
void adc_ch_set(uint8_t ADCchannel);
void adc_start(void);
void adc_disable(void);
void adc_test();

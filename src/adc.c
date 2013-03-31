#include <sk328/adc.h>

uint8_t adc_result = 0;
int i;

void tim0_init(void)
{
	TCNT0=0;
	OCR0A=99;
	TCCR0A |=(1<<COM0A0)|(1<<WGM01);
}

void tim0_start(void)
{
	TCCR0B |=(1<<CS01);
}

void tim0_stop(void)
{
	TCCR0B &=~(1<<CS01);
	TIMSK0 &=~(1<<OCIE0A);
}

void adc_init()
{
	ADMUX |= (1<<REFS0)|(1<<ADLAR);
	ADCSRA |= (1<<ADPS2)|(1<<ADPS0)|(1<<ADATE)|(1<<ADIE)|(1<<ADEN);
	ADCSRB |= (1<<ADTS1)|(1<<ADTS0);
}

void adc_ch_set(uint8_t ADCchannel)
{
	ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);
}

void adc_start(void)
{
	ADCSRA |= (1<<ADSC);
}
void adc_disable(void)
{
	ADCSRA &= ~((1<<ADEN)|(1<<ADIE));
}

ISR(ADC_vect)
{
	TIFR0=(1<<OCF0A);
}

void adc_test()
{
	adc_init();
	tim0_init();
	tim0_start();
	adc_start();
	sei();
	while(1)
	{
		  printf("ADC Values");		  
		  adc_ch_set(0);
		  printf(" [%u] ", ADCH);
		  adc_ch_set(1);
		  printf(" [%u] ", ADCH);
		  adc_ch_set(2);
		  printf(" [%u] ", ADCH);
		  adc_ch_set(3);
		  printf(" [%u] ", ADCH);
		  adc_ch_set(4);
		  printf(" [%u] ", ADCH);
		  adc_ch_set(5);
		  printf(" [%u] ", ADCH);
		  adc_ch_set(6);
		  printf(" [%u] ", ADCH);
		  adc_ch_set(7);
		  printf(" [%u] ", ADCH);
		  printf("  done reading\r\n");		  
	}
}


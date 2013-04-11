#include <sk328/odetect.h>

#define CH0_EN 1
#define CH1_EN 1
#define CH2_EN 1
#define CH3_EN 1
#define CH4_EN 1
#define CH5_EN 1
#define CH6_EN 1
#define CH7_EN 1

void odetect_init(void)
{
	adc_init();
	tim0_init();
	tim0_start();
	adc_start();
}

void odetect_process(void)
{
    uint8_t to_uart = 0; // in this variable we will store bits

    // 1. Get data from all rangefinders

    // 1.7. Rear center
    adc_ch_set(7);
    uint8_t front_center = ADCH;
    // 1.6. Rear right
    adc_ch_set(0);
    uint8_t rear_right = ADCH;
    // 1.1. Left front
    adc_ch_set(1);
    uint8_t front_left = ADCH;
    // 1.2. Right front
    adc_ch_set(2);
    uint8_t front_right = ADCH;
    // 1.4. Right
    adc_ch_set(3);
    uint8_t right = ADCH;
    // 1.3. Left
    adc_ch_set(4);
    uint8_t left = ADCH;
    // 1.5. Rear left
    adc_ch_set(6);
    uint8_t rear_left = ADCH;


    // 2. Compare data with reference limits
    // and fill in output byte
    
    // 2.1. Front (bit 3)
    if(front_left >= CONFIG_FRONT_LEFT_REF || front_right >= CONFIG_FRONT_RIGHT_REF || front_center >= CONFIG_FRONT_CENTER_REF)
        to_uart |= (1<<3);

    // 2.2. Rear (bit 2)
    if(rear_left >= CONFIG_REAR_LEFT_REF || rear_right >= CONFIG_REAR_RIGHT_REF)
        to_uart |= (1<<2);

    // 2.3. Left (bit 1)
    if(left >= CONFIG_LEFT_REF)
        to_uart |= (1<<1);

    // 2.4. Right (bit 0)
    if(right >= CONFIG_RIGHT_REF)
        to_uart |= 1;

    uart_write(to_uart);
}

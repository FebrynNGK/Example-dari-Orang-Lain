#include "my_pin.h"
#include "my_process.h"
#include "my_kirim.h"

extern adcsample_t adc_val;
extern adcsample_t adc_val2;
extern adcsample_t adc_val3;
extern adcsample_t adc_val4;
extern adcsample_t adc_val5;
extern adcsample_t adc_val6;
extern adcsample_t adc_val7;
extern adcsample_t adc_val8;
extern adcsample_t adc_val9;
extern adcsample_t adc_val10;
extern adcsample_t adc_val11;
extern adcsample_t adc_val12;
extern adcsample_t adc_val13;
extern adcsample_t adc_val14;
extern adcsample_t adc_val15;
extern adcsample_t adc_val16;
extern adcsample_t adc_val17;
extern adcsample_t adc_val18;
extern adcsample_t adc_val19;
extern adcsample_t adc_val20;


extern float current1;
extern float current2;
extern float current3;
extern float voltage1;
extern float voltage2;
extern float voltage3;
extern float energy1_wh;
extern float energy2_wh;
extern float energy3_wh;
extern float daya1;
extern float daya2;
extern float daya3;



void kirim_setup(void){

sdStart(&SD2,NULL);  
  palSetPadMode(GPIOB,3, PAL_MODE_ALTERNATE(7)); //TX
  palSetPadMode(GPIOB,4, PAL_MODE_ALTERNATE(7)); //RX

  sdStart(&SD1,NULL);
    palSetPadMode(GPIOA,9, PAL_MODE_ALTERNATE(7)); //TX
    palSetPadMode(GPIOA,10, PAL_MODE_ALTERNATE(7)); //RX

    sdStart(&SD3,NULL);
      palSetPadMode(GPIOB,10, PAL_MODE_ALTERNATE(7)); //TX
      palSetPadMode(GPIOE,15, PAL_MODE_ALTERNATE(7)); //RX
};



void kirim_data_usart1(void){
    voltage_sensor();
    current_sensor();
    //chprintf((BaseSequentialStream*)&SD1,"%f,%f,%f\n",voltage1,voltage2,voltage3);
     //chprintf((BaseSequentialStream*)&SD1,"%i,%i,%i,%i,%i,%i\n",current1,current2,current3,voltage1,voltage2,voltage3);
};



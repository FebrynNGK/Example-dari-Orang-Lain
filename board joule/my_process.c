#include "my_process.h"
#include "my_pin.h"
#include <math.h>


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


static int current1_adc_10mstick=0;
static int current2_adc_10mstick=0;
static int current3_adc_10mstick=0;
static int voltage1_adc_10mstick=0;
static int voltage2_adc_10mstick=0;
static int voltage3_adc_10mstick=0;


float current1=0;
float current2=0;
float current3=0;
float voltage1=0;
float voltage2=0;
float voltage3=0;
float daya1=0;
float daya2=0;
float daya3=0;
float energy1_wh=0;
float energy2_wh=0;
float energy3_wh=0;
float energy1_kwh=0;
float energy2_kwh=0;
float energy3_kwh=0;

int current1_adc_rata;
int current2_adc_rata;
int current3_adc_rata;
int voltage1_adc_rata;
int voltage2_adc_rata;
int voltage3_adc_rata;

int current1_adc_total;
int current2_adc_total;
int current3_adc_total;
int voltage1_adc_total;
int voltage2_adc_total;
int voltage3_adc_total;

int milidetik,detik,menit,jam;



static WORKING_AREA(wa_jouleThread, 256);
static msg_t jouleThread(void *arg) {
  (void)arg;
 while (TRUE) {
     daya();
     energy();
      milidetik++;
      if(milidetik==10){
    detik++;
    milidetik=0;
      }
      if(detik==60){
    menit++;
    detik=0;
      }
      if(menit==60){
         jam++;
      }
      chThdSleepMilliseconds(100);
  }
  return 0;
}


static WORKING_AREA(wa_milisecThread, 256);
static msg_t milisecThread(void *arg) {
  (void)arg;
 while (TRUE) {
     fungsi_rata2();
      chThdSleepMilliseconds(1);
  }
  return 0;
}

void fungsi_rata2(void){
    current1_adc_10mstick++;
    current2_adc_10mstick++;
    current3_adc_10mstick++;
    voltage1_adc_10mstick++;
    voltage2_adc_10mstick++;
    voltage3_adc_10mstick++;


      if (current1_adc_10mstick==30) {
         current1_adc_10mstick=0;
        current1_adc_rata = current1_adc_total/30;
        current1_adc_total=0;
      }

      current1_adc_total += adc_val;

      if (current2_adc_10mstick==30) {
         current2_adc_10mstick=0;
        current2_adc_rata = current2_adc_total/30;
        current2_adc_total=0;
      }

      current2_adc_total += adc_val3;

      if (current3_adc_10mstick==30) {
         current3_adc_10mstick=0;
        current3_adc_rata = current3_adc_total/30;
        current3_adc_total=0;
      }

      current3_adc_total += adc_val4;

      if (voltage1_adc_10mstick==30) {
         voltage1_adc_10mstick=0;
        voltage1_adc_rata = voltage1_adc_total/30;
        voltage1_adc_total=0;
      }

      voltage1_adc_total += adc_val12;


      if (voltage2_adc_10mstick==30) {
         voltage2_adc_10mstick=0;
        voltage2_adc_rata = voltage2_adc_total/30;
        voltage2_adc_total=0;
      }

      voltage2_adc_total += adc_val11;

      if (voltage3_adc_10mstick==30) {
         voltage3_adc_10mstick=0;
        voltage3_adc_rata = voltage3_adc_total/30;
        voltage3_adc_total=0;
      }

      voltage3_adc_total += adc_val13;

}

void current_sensor(void){

current1 = (((float)current1_adc_rata-2049)/16.67);
current2 = (((float)current2_adc_rata-2062)/15.8);
current3 = (((float)current3_adc_rata-2025)/15.91);

}
void voltage_sensor(void){
    voltage1 = (((float)voltage1_adc_rata)/25.14);
    voltage2 = (((float)voltage2_adc_rata)/24.95);
    voltage3 = (((float)voltage3_adc_rata)/25.14);

}

void daya(void){
    daya1 = ((float)daya1+(current1*voltage1));
    daya2 = ((float)daya2+(current2*voltage2));
    daya3 = ((float)daya3+(current3*voltage3));
}

void energy(void){
    energy1_wh = (daya1/3600);
    energy2_wh = (daya2/3600);
    energy3_wh = (daya3/3600);
}

void process_running (void){
   chThdCreateStatic(wa_milisecThread, sizeof(wa_milisecThread), NORMALPRIO, milisecThread, NULL);
   chThdCreateStatic(wa_jouleThread, sizeof(wa_jouleThread), NORMALPRIO, jouleThread, NULL);
}




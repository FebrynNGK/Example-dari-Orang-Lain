#include "adc_it.h"

#define ADC_GRP_NUM_CHANNELS   9
#define ADC_GRP_BUF_DEPTH      10

#define ADC_GRP3_NUM_CHANNELS   11
#define ADC_GRP3_BUF_DEPTH      10

static adcsample_t samples[ADC_GRP_NUM_CHANNELS * ADC_GRP_BUF_DEPTH];
adcsample_t adc_val;
adcsample_t adc_val2;
adcsample_t adc_val3;
adcsample_t adc_val4;
adcsample_t adc_val5;
adcsample_t adc_val6;
adcsample_t adc_val7;
adcsample_t adc_val8;
adcsample_t adc_val9;

static adcsample_t samples3[ADC_GRP3_NUM_CHANNELS * ADC_GRP3_BUF_DEPTH];

adcsample_t adc_val10;
adcsample_t adc_val11;
adcsample_t adc_val12;
adcsample_t adc_val13;
adcsample_t adc_val14;
adcsample_t adc_val15;
adcsample_t adc_val16;
adcsample_t adc_val17;
adcsample_t adc_val18;
adcsample_t adc_val19;
adcsample_t adc_val20;


uint32_t adc_buff;
uint32_t adc_buff2;
uint32_t adc_buff3;
uint32_t adc_buff4;
uint32_t adc_buff5;
uint32_t adc_buff6;
uint32_t adc_buff7;
uint32_t adc_buff8;
uint32_t adc_buff9;
uint32_t adc_buff10;
uint32_t adc_buff11;
uint32_t adc_buff12;
uint32_t adc_buff13;
uint32_t adc_buff14;
uint32_t adc_buff15;
uint32_t adc_buff16;
uint32_t adc_buff17;
uint32_t adc_buff18;
uint32_t adc_buff19;
uint32_t adc_buff20;



static void adccallback(ADCDriver *adcp, adcsample_t *buffer, size_t n) {

  (void)buffer;
  (void)n;
  
  int i;
  
  if (adcp->state == ADC_COMPLETE){
    
    adc_buff=0;
    adc_buff2=0;
    adc_buff3=0;
    adc_buff4=0;
    adc_buff5=0;
    adc_buff6=0;
    adc_buff7=0;
    adc_buff8=0;
    adc_buff9=0;
    
    adc_buff10=0;
    adc_buff11=0;
    adc_buff12=0;
    adc_buff13=0;
    adc_buff14=0;
    adc_buff15=0;
    adc_buff16=0;
    adc_buff17=0;
    adc_buff18=0;
    adc_buff19=0;
    adc_buff20=0;
       
    for(i=0;i<10;i++){
    adc_buff=adc_buff+samples[0+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff2=adc_buff2+samples[1+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff3=adc_buff3+samples[2+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff4=adc_buff4+samples[3+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff5=adc_buff5+samples[4+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff6=adc_buff6+samples[5+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff7=adc_buff7+samples[6+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff8=adc_buff8+samples[7+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff9=adc_buff9+samples[8+(ADC_GRP_NUM_CHANNELS*i)];
    
    adc_buff10=adc_buff10+samples3[0+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff11=adc_buff11+samples3[1+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff12=adc_buff12+samples3[2+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff13=adc_buff13+samples3[3+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff14=adc_buff14+samples3[4+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff15=adc_buff15+samples3[5+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff16=adc_buff16+samples3[6+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff17=adc_buff17+samples3[7+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff18=adc_buff18+samples3[8+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff19=adc_buff19+samples3[9+(ADC_GRP3_NUM_CHANNELS*i)];
    adc_buff20=adc_buff20+samples3[10+(ADC_GRP3_NUM_CHANNELS*i)];
       
    };  
    adc_val= adc_buff/10;
    adc_val2= adc_buff2/10;
    adc_val3= adc_buff3/10;
    adc_val4= adc_buff4/10;
    adc_val5= adc_buff5/10;
    adc_val6= adc_buff6/10;
    adc_val7= adc_buff7/10;
    adc_val8= adc_buff8/10;
    adc_val9= adc_buff9/10;
    
    
    adc_val10= adc_buff10/10;
    adc_val11= adc_buff11/10;
    adc_val12= adc_buff12/10;
    adc_val13= adc_buff13/10;
    adc_val14= adc_buff14/10;
    adc_val15= adc_buff15/10;
    adc_val16= adc_buff16/10;
    adc_val17= adc_buff17/10;
    adc_val18= adc_buff18/10;
    adc_val19= adc_buff19/10;
    adc_val20= adc_buff20/10;
    
  }
}

static const ADCConversionGroup adcgrpcfg = {
  FALSE,
  ADC_GRP_NUM_CHANNELS,
  adccallback,
  NULL,
  0,                        /* CFGR    */
  ADC_TR(0, 4095),          /* TR1     */
  0,                        /* CCR     */
  {                         /* SMPR[2] */
    ADC_SMPR1_SMP_AN2(ADC_SMPR_SMP_19P5) | ADC_SMPR1_SMP_AN3(ADC_SMPR_SMP_19P5) | \
    ADC_SMPR1_SMP_AN4(ADC_SMPR_SMP_19P5) | ADC_SMPR1_SMP_AN5(ADC_SMPR_SMP_19P5) | \
    ADC_SMPR1_SMP_AN6(ADC_SMPR_SMP_19P5) | ADC_SMPR1_SMP_AN7(ADC_SMPR_SMP_19P5) | \
    ADC_SMPR1_SMP_AN8(ADC_SMPR_SMP_19P5) | ADC_SMPR1_SMP_AN9(ADC_SMPR_SMP_19P5),
    0,
  },
  {                         /* SQR[4]  */
    ADC_SQR1_SQ1_N(ADC_CHANNEL_IN2) | ADC_SQR1_SQ2_N(ADC_CHANNEL_IN3) | \
    ADC_SQR1_SQ3_N(ADC_CHANNEL_IN4) | ADC_SQR1_SQ4_N(ADC_CHANNEL_IN5),
    ADC_SQR2_SQ5_N(ADC_CHANNEL_IN6) | ADC_SQR2_SQ6_N(ADC_CHANNEL_IN7) | \
    ADC_SQR2_SQ7_N(ADC_CHANNEL_IN8) | ADC_SQR2_SQ8_N(ADC_CHANNEL_IN9) | ADC_SQR2_SQ9_N(ADC_CHANNEL_IN10),
    0,
    0
  }
};

static const ADCConversionGroup adcgrpcfg3 = {
  FALSE,
  ADC_GRP3_NUM_CHANNELS,
  adccallback,
  NULL,
  0,                        /* CFGR    */
  ADC_TR(0, 4095),          /* TR1     */
  0,                        /* CCR     */
  {                         /* SMPR[2] */
    ADC_SMPR1_SMP_AN1(ADC_SMPR_SMP_19P5) | ADC_SMPR1_SMP_AN2(ADC_SMPR_SMP_19P5) | \
    ADC_SMPR1_SMP_AN5(ADC_SMPR_SMP_19P5) | ADC_SMPR1_SMP_AN6(ADC_SMPR_SMP_19P5) | \
    ADC_SMPR1_SMP_AN7(ADC_SMPR_SMP_19P5) | ADC_SMPR1_SMP_AN8(ADC_SMPR_SMP_19P5) | \
    ADC_SMPR1_SMP_AN9(ADC_SMPR_SMP_19P5),
    ADC_SMPR2_SMP_AN10(ADC_SMPR_SMP_19P5) | ADC_SMPR2_SMP_AN11(ADC_SMPR_SMP_19P5) | \
    ADC_SMPR2_SMP_AN12(ADC_SMPR_SMP_19P5) | ADC_SMPR2_SMP_AN13(ADC_SMPR_SMP_19P5),
  },
  {                         /* SQR[4]  */
    ADC_SQR1_SQ1_N(ADC_CHANNEL_IN1) | ADC_SQR1_SQ2_N(ADC_CHANNEL_IN2) | \
    ADC_SQR1_SQ3_N(ADC_CHANNEL_IN13) | ADC_SQR1_SQ4_N(ADC_CHANNEL_IN5),
    ADC_SQR2_SQ5_N(ADC_CHANNEL_IN6) | ADC_SQR2_SQ6_N(ADC_CHANNEL_IN7) | \
    ADC_SQR2_SQ7_N(ADC_CHANNEL_IN8) | ADC_SQR2_SQ8_N(ADC_CHANNEL_IN9) | \
    ADC_SQR2_SQ9_N(ADC_CHANNEL_IN10), ADC_SQR3_SQ10_N(ADC_CHANNEL_IN11) | ADC_SQR3_SQ11_N(ADC_CHANNEL_IN12),
    0
  }
};

static WORKING_AREA(wa_adcThread, 128);
static msg_t adcThread(void *arg) {
  (void)arg;
  while (TRUE) {
    chThdSleepMilliseconds(200);
    adcStartConversion(&ADCD1, &adcgrpcfg, samples, ADC_GRP_BUF_DEPTH);
    adcStartConversion(&ADCD3, &adcgrpcfg3, samples3, ADC_GRP3_BUF_DEPTH);    
  }
  return 0;
}

void Adc_Init(void){
  palSetPadMode(GPIOA,1,PAL_MODE_INPUT_ANALOG);      //current1
  palSetPadMode(GPIOA,2,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOA,3,PAL_MODE_INPUT_ANALOG);      //current2
  palSetPadMode(GPIOF,4,PAL_MODE_INPUT_ANALOG);      //current3
  palSetPadMode(GPIOC,0,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOC,1,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOC,2,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOC,3,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOF,2,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOB,1,PAL_MODE_INPUT_ANALOG);
  
  palSetPadMode(GPIOE,9,PAL_MODE_INPUT_ANALOG);     //voltage 2
  palSetPadMode(GPIOE,7,PAL_MODE_INPUT_ANALOG);     //voltage 1
  palSetPadMode(GPIOB,13,PAL_MODE_INPUT_ANALOG);    //voltage 3
  palSetPadMode(GPIOE,8,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOD,10,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOD,11,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOD,12,PAL_MODE_INPUT_ANALOG);
  palSetPadMode(GPIOD,14,PAL_MODE_INPUT_ANALOG);
  adcStart(&ADCD1, NULL);
  adcStart(&ADCD3, NULL);
  chThdCreateStatic(wa_adcThread, sizeof(wa_adcThread), NORMALPRIO, adcThread, NULL);
}

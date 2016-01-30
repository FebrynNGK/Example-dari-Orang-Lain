//memasukkan header file
#include "main.h"
/*
//thread kirim joule
static WORKING_AREA(waThreadkirimjoule, 1024);
static msg_t Threadkirimjoule(void *arg) {

  (void)arg;
  chRegSetThreadName("kirimJoule");
  while (TRUE) {
	  
	arus1=current1*100;
	arus2=current2*100; 
	arus3=current3*100;
	volt1=voltage1*100;
	volt2=voltage2*100;
	volt3=voltage3*100;
	watt1=daya1*100;
	watt2=daya2*100;
	watt3=daya3*100;
	joule1=energy1_wh*100;
	joule2=energy2_wh*100;
	joule3=energy3_wh*100;
	
	   
	TxMessage.Data[0] = arus1>>8;
	TxMessage.Data[1] = arus1 & 0x00FF ;
	TxMessage.Data[2] = arus2>>8;
	TxMessage.Data[3] = arus2 & 0x00FF ;
	TxMessage.Data[4] = arus3>>8;
	TxMessage.Data[5] = arus3 & 0x00FF ;
	TxMessage.Data[6] =	volt1>>8;
	TxMessage.Data[7] = volt1 & 0x00FF ;
	
	TxMessage2.Data[0] = volt2>>8;
	TxMessage2.Data[1] = volt2 & 0x00FF ;
	TxMessage2.Data[2] = volt3>>8;
	TxMessage2.Data[3] = volt3 & 0x00FF ;
	TxMessage2.Data[4] = watt1>>8;
	TxMessage2.Data[5] = watt1 & 0x00FF ;
	TxMessage2.Data[6] = watt2>>8;
	TxMessage2.Data[7] = watt2 & 0x00FF ;
	
	TxMessage3.Data[0] = watt3>>8;
	TxMessage3.Data[1] = watt3 & 0x00FF ;
	TxMessage3.Data[2] = joule1>>8;
	TxMessage3.Data[3] = joule1 & 0x00FF ;
	TxMessage3.Data[4] = joule2>>8;
	TxMessage3.Data[5] = joule2 & 0x00FF ;
	TxMessage3.Data[6] = joule3>>8;
	TxMessage3.Data[7] = joule3 & 0x00FF ;
	
	CAN_Transmit(CANx, &TxMessage);
	CAN_Transmit(CANx, &TxMessage2);
	CAN_Transmit(CANx, &TxMessage3);
	
	palSetPad(GPIOE, GPIOE_LED9_BLUE);
    chThdSleepMilliseconds(60);
    palClearPad(GPIOE, GPIOE_LED9_BLUE);
    chThdSleepMilliseconds(60);
	
  }
  return 0;
}
*/
/*static WORKING_AREA(waThreadkirimjoule2, 512);
static msg_t Threadkirimjoule2(void *arg) {

  (void)arg;
  chRegSetThreadName("kirimJoule2");
  while (TRUE) {
	   
	TxMessage4.Data[0] = milidetik>>8;
	TxMessage4.Data[1] = milidetik & 0x00FF ;
	TxMessage4.Data[2] = detik>>8;
	TxMessage4.Data[3] = detik & 0x00FF ;
	TxMessage4.Data[4] = menit>>8;
	TxMessage4.Data[5] = menit & 0x00FF ;
	TxMessage4.Data[6] = jam>>8;
	TxMessage4.Data[7] = jam & 0x00FF ;
	
	CAN_Transmit(CANx, &TxMessage4);
	
	palSetPad(GPIOE, GPIOE_LED5_ORANGE);
    chThdSleepMilliseconds(40);
    palClearPad(GPIOE, GPIOE_LED5_ORANGE);
    chThdSleepMilliseconds(40);
	
  }
  return 0;
}
*/
//thread baca tegangan
static WORKING_AREA(waBacavolt, 1024);
static msg_t Bacavolt(void *arg) {

  (void)arg;
  chRegSetThreadName("dataTegangan");
  while (TRUE) {
  
  //data tegangan ID 0x33
  voltMPPT1_1		= RxMessage33.Data[0];
  voltMPPT1_2		= RxMessage33.Data[1];
  voltMPPT1			= (voltMPPT1_1<<8) | (voltMPPT1_2);
  voltMPPT2_1		= RxMessage33.Data[2];
  voltMPPT2_2		= RxMessage33.Data[3];
  voltMPPT2			= (voltMPPT2_1<<8) | (voltMPPT2_2);
  voltMPPT3_1		= RxMessage33.Data[4];
  voltMPPT3_2		= RxMessage33.Data[5];
  voltMPPT3			= (voltMPPT3_1<<8) | (voltMPPT3_2);
  voltMPPT4_1		= RxMessage33.Data[6];
  voltMPPT4_2		= RxMessage33.Data[7];
  voltMPPT4			= (voltMPPT4_1<<8) | (voltMPPT4_2);
  
  //data tegangan ID 0x44
  voltMPPT5_1		= RxMessage44.Data[0];
  voltMPPT5_2		= RxMessage44.Data[1];
  voltMPPT5			= (voltMPPT5_1<<8) | (voltMPPT5_2);
  voltMPPT6_1		= RxMessage44.Data[2];
  voltMPPT6_2		= RxMessage44.Data[3];
  voltMPPT6			= (voltMPPT6_1<<8) | (voltMPPT6_2);
  voltMPPT7_1		= RxMessage44.Data[4];
  voltMPPT7_2		= RxMessage44.Data[5];
  voltMPPT7			= (voltMPPT7_1<<8) | (voltMPPT7_2);
  voltMPPT8_1		= RxMessage44.Data[6];
  voltMPPT8_2		= RxMessage44.Data[7];
  voltMPPT8			= (voltMPPT8_1<<8) | (voltMPPT8_2);
  
  //data tegangan ID 0x55
  voltMPPT9_1		= RxMessage55.Data[0];
  voltMPPT9_2		= RxMessage55.Data[1];
  voltMPPT9			= (voltMPPT9_1<<8) | (voltMPPT9_2);
  voltMPPT10_1		= RxMessage55.Data[2];
  voltMPPT10_2		= RxMessage55.Data[3];
  voltMPPT10		= (voltMPPT10_1<<8) | (voltMPPT10_2);
  voltMPPT11_1		= RxMessage55.Data[4];
  voltMPPT11_2		= RxMessage55.Data[5];
  voltMPPT11		= (voltMPPT11_1<<8) | (voltMPPT11_2);
  voltMPPT12_1		= RxMessage55.Data[6];
  voltMPPT12_2		= RxMessage55.Data[7];
  voltMPPT12		= (voltMPPT12_1<<8) | (voltMPPT12_2);
  
  //data tegangan ID 0x66
  voltMPPT13_1		= RxMessage66.Data[0];
  voltMPPT13_2		= RxMessage66.Data[1];
  voltMPPT13		= (voltMPPT13_1<<8) | (voltMPPT13_2);
  voltMPPT15_1		= RxMessage66.Data[2];
  voltMPPT15_2		= RxMessage66.Data[3];
  voltMPPT15		= (voltMPPT15_1<<8) | (voltMPPT15_2);
  voltMPPT16_1		= RxMessage66.Data[4];
  voltMPPT16_2		= RxMessage66.Data[5];
  voltMPPT16		= (voltMPPT16_1<<8) | (voltMPPT16_2);
  
  //proses perhitungan
  mppt1_v = ((float)voltMPPT1*0.03775);
  mppt2_v = ((float)voltMPPT2*0.03775);
  mppt3_v = ((float)voltMPPT3*0.03775);
  mppt4_v = ((float)voltMPPT4*0.03775);
  mppt5_v = ((float)voltMPPT5*0.03775);
  mppt6_v = ((float)voltMPPT6*0.03775);
  mppt7_v = ((float)voltMPPT7*0.03775);
  mppt8_v = ((float)voltMPPT8*0.03775);
  mppt9_v = ((float)voltMPPT9*0.03775);
  mppt10_v = ((float)voltMPPT10*0.03775);
  mppt11_v = ((float)voltMPPT11*0.03775);
  mppt12_v = ((float)voltMPPT12*0.03775);
  mppt13_v = ((float)voltMPPT13*0.03775);
  mppt15_v = ((float)voltMPPT15*0.03775);
  mppt16_v = ((float)voltMPPT16*0.03775);
  
  chThdSleepMilliseconds(50);
    
  }
  return 0;
}

//thread baca arus
static WORKING_AREA(waBacacurrent, 1024);
static msg_t Bacacurrent(void *arg) {

  (void)arg;
  chRegSetThreadName("dataArus");
  while (TRUE) {
  
  //data arus ID 0x77
  currentMPPT1_1		= RxMessage77.Data[0];
  currentMPPT1_2		= RxMessage77.Data[1];
  currentMPPT1			= (currentMPPT1_1<<8) | (currentMPPT1_2);
  currentMPPT2_1		= RxMessage77.Data[2];
  currentMPPT2_2		= RxMessage77.Data[3];
  currentMPPT2			= (currentMPPT2_1<<8) | (currentMPPT2_2);
  currentMPPT3_1		= RxMessage77.Data[4];
  currentMPPT3_2		= RxMessage77.Data[5];
  currentMPPT3			= (currentMPPT3_1<<8) | (currentMPPT3_2);
  currentMPPT4_1		= RxMessage77.Data[6];
  currentMPPT4_2		= RxMessage77.Data[7];
  currentMPPT4			= (currentMPPT4_1<<8) | (currentMPPT4_2);
  
  //data arus ID 0x88
  currentMPPT5_1		= RxMessage88.Data[0];
  currentMPPT5_2		= RxMessage88.Data[1];
  currentMPPT5			= (currentMPPT5_1<<8) | (currentMPPT5_2);
  currentMPPT6_1		= RxMessage88.Data[2];
  currentMPPT6_2		= RxMessage88.Data[3];
  currentMPPT6			= (currentMPPT6_1<<8) | (currentMPPT6_2);
  currentMPPT7_1		= RxMessage88.Data[4];
  currentMPPT7_2		= RxMessage88.Data[5];
  currentMPPT7			= (currentMPPT7_1<<8) | (currentMPPT7_2);
  currentMPPT8_1		= RxMessage88.Data[6];
  currentMPPT8_2		= RxMessage88.Data[7];
  currentMPPT8			= (currentMPPT8_1<<8) | (currentMPPT8_2);
  
  //data arus ID 0x99
  currentMPPT9_1		= RxMessage99.Data[0];
  currentMPPT9_2		= RxMessage99.Data[1];
  currentMPPT9			= (currentMPPT9_1<<8) | (currentMPPT9_2);
  currentMPPT10_1		= RxMessage99.Data[2];
  currentMPPT10_2		= RxMessage99.Data[3];
  currentMPPT10			= (currentMPPT10_1<<8) | (currentMPPT10_2);
  currentMPPT11_1		= RxMessage99.Data[4];
  currentMPPT11_2		= RxMessage99.Data[5];
  currentMPPT11			= (currentMPPT11_1<<8) | (currentMPPT11_2);
  currentMPPT12_1		= RxMessage99.Data[6];
  currentMPPT12_2		= RxMessage99.Data[7];
  currentMPPT12			= (currentMPPT12_1<<8) | (currentMPPT12_2);
  
  //data arus ID 0x11
  currentMPPT13_1		= RxMessage11.Data[0];
  currentMPPT13_2		= RxMessage11.Data[1];
  currentMPPT13			= (currentMPPT13_1<<8) | (currentMPPT13_2);
  currentMPPT14_1		= RxMessage11.Data[2];
  currentMPPT14_2		= RxMessage11.Data[3];
  currentMPPT14			= (currentMPPT14_1<<8) | (currentMPPT14_2);
  currentMPPT15_1		= RxMessage11.Data[4];
  currentMPPT15_2		= RxMessage11.Data[5];
  currentMPPT15			= (currentMPPT15_1<<8) | (currentMPPT15_2);
  
  //proses perhitungan
  mppt1_i = (((float)currentMPPT1-2198)/34.17);
  mppt2_i = (((float)currentMPPT2-2268)/33.35);
  mppt3_i = (((float)currentMPPT3-2173)/32.42);
  mppt4_i = (((float)currentMPPT4-2212)/35.57);
  mppt5_i = (((float)currentMPPT5-2235)/36.07);
  mppt6_i = (((float)currentMPPT6-2211)/30.42);
  mppt7_i = (((float)currentMPPT7-2194)/32.07);
  mppt8_i = (((float)currentMPPT8-2200)/33.92);
  mppt9_i = (((float)currentMPPT9-2208)/31.35);
  mppt10_i = (((float)currentMPPT10-2162)/35.57);
  mppt11_i = (((float)currentMPPT11-2217)/32.92);
  mppt12_i = (((float)currentMPPT12-2226)/33.42);
  mppt13_i = ((float)currentMPPT13-2225)/33.42;
  mppt14_i = ((float)currentMPPT14-2242)/33.85;
  mppt15_i = ((float)currentMPPT15-2244)/34;
  
  chThdSleepMilliseconds(50);
    
  }
  return 0;
}

//thread baca BMS
static WORKING_AREA(waThreadBMS, 1024);
static msg_t ThreadBMS(void *arg) {

  (void)arg;
  chRegSetThreadName("dataBMS");
  while (TRUE) {
	  
  //ID 0x1B
  avgtemp  		= RxMessage1B.Data[0];
  lowvolt1	 	= RxMessage1B.Data[2];
  lowvolt2	 	= RxMessage1B.Data[3];
  highvolt1	 	= RxMessage1B.Data[4];
  highvolt2	 	= RxMessage1B.Data[5];
  amphours1		= RxMessage1B.Data[6];
  amphours2		= RxMessage1B.Data[7];
  
  //ID 0x6B2
  packsocraw    = RxMessage6B2.Data[1];
  packvolt1		= RxMessage6B2.Data[4];
  packvolt2		= RxMessage6B2.Data[5];
  
  //ID 0x3B
  packcurrent1	= RxMessage3B.Data[0];
  packcurrent2	= RxMessage3B.Data[1];
  supply12vraw	= RxMessage3B.Data[4];
  packDODraw	= RxMessage3B.Data[5];
  avgcellvolt1	= RxMessage3B.Data[6];
  avgcellvolt2	= RxMessage3B.Data[7];
  
  //ID 0x3CB
  packDCL		= RxMessage3CB.Data[0];
  packCCL		= RxMessage3CB.Data[1]; //data Charge Current Limit (CCL)
  hightemp 		= RxMessage3CB.Data[4]; //data Discharge Current Limit (DCL)
  lowtemp  		= RxMessage3CB.Data[5]; //data suhu baterai
  
  //proses perhitungan
  avgcellvoltraw= (avgcellvolt1<<8) | (avgcellvolt2);
  packvoltraw	= (packvolt1<<8) | (packvolt2);
  lowvolt   	= (lowvolt1<<8) | (lowvolt2);
  highvolt   	= (highvolt1<<8) | (highvolt2); 
  avgcellvolt	= avgcellvoltraw * 0.0001;
  lowvoltcell 	= lowvolt * 0.0001; //tegangan cell baterai minimum
  highvoltcell	= highvolt * 0.0001; //tegangan cell baterai maksimum
  packvolt		= packvoltraw; //tegangan total baterai
  deltacellvolt = highvoltcell - lowvoltcell;
  supply12v		= supply12vraw * 0.1; //data supply 12 V
  packcurrentraw = (packcurrent1<<8) | (packcurrent2);
  packcurrent	= (packcurrentraw * 0.1)-6553; //data arus
  amphoursraw	= (amphours1<<8) | (amphours2);
  amphours		= amphoursraw * 0.1; //data amphours
  packsoc		= packsocraw; //data SoC
  packDOD		= packDODraw; //data Depth of Discharge (DOD)
  
  chThdSleepMilliseconds(50);
  

}
return 0;

}

//fungsi utama
int main (void) {
	
	//inisialisasi HAL (Hardware Abstraction Layer)
	halInit();
	
	//inisialisasi kernel
	chSysInit();
	
	Adc_Init();
	
	process_running();
	
	//inisialisasi CAN
	CAN_Config();
	
	// serial
	sdStart(&SD2,NULL);  
    palSetPadMode(GPIOB,3, PAL_MODE_ALTERNATE(7)); //TX
    palSetPadMode(GPIOB,4, PAL_MODE_ALTERNATE(7)); //RX

    sdStart(&SD1,NULL);
    palSetPadMode(GPIOA,9, PAL_MODE_ALTERNATE(7)); //TX
    palSetPadMode(GPIOA,10, PAL_MODE_ALTERNATE(7)); //RX

    sdStart(&SD3,NULL);
    palSetPadMode(GPIOB,10, PAL_MODE_ALTERNATE(7)); //TX
    palSetPadMode(GPIOE,15, PAL_MODE_ALTERNATE(7)); //RX
    
	//inisialisasi USB
	sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);
    
    //aktifasi USB
    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(200);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);
	
	//thread 1
	chThdCreateStatic(waBacavolt, sizeof(waBacavolt), NORMALPRIO, Bacavolt, NULL);
	chThdCreateStatic(waBacacurrent, sizeof(waBacacurrent), NORMALPRIO, Bacacurrent, NULL);
	chThdCreateStatic(waThreadBMS, sizeof(waThreadBMS), NORMALPRIO, ThreadBMS, NULL);
	//chThdCreateStatic(waThreadkirimjoule, sizeof(waThreadkirimjoule), NORMALPRIO, Threadkirimjoule, NULL);
	//chThdCreateStatic(waThreadkirimjoule2, sizeof(waThreadkirimjoule2), NORMALPRIO, Threadkirimjoule2, NULL);


while(TRUE) {
	kirim_data_usart1();
    chprintf((BaseSequentialStream *)&SD1,"%d,%f,%d,%d,%f,%f,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%d,%d,%d \n",avgtemp,packsoc,packDCL,packCCL,lowvoltcell,highvoltcell,hightemp,lowtemp,packcurrent,packvolt,amphours,supply12v, deltacellvolt,avgcellvolt,mppt1_v,mppt2_v,mppt3_v,mppt4_v,mppt5_v,mppt6_v,mppt7_v,mppt8_v,mppt9_v,mppt10_v,mppt11_v,mppt12_v,mppt13_v,mppt15_v,mppt16_v, mppt1_i, mppt2_i, mppt3_i, mppt4_i, mppt5_i, mppt6_i, mppt7_i,mppt8_i, mppt9_i, mppt10_i, mppt11_i, mppt12_i, mppt13_i, mppt14_i, mppt15_i,current1,current2,current3,voltage1,voltage2,voltage3,milidetik,detik,menit,jam);
    //chprintf((BaseSequentialStream *)&SDU1,"%d,%f,%d,%d,%f,%f,%d,%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f \n",avgtemp,packsoc,packDCL,packCCL,lowvoltcell,highvoltcell,hightemp,lowtemp,packcurrent,packvolt,amphours,supply12v, deltacellvolt,avgcellvolt,mppt1_v,mppt2_v,mppt3_v,mppt4_v,mppt5_v,mppt6_v,mppt7_v,mppt8_v,mppt9_v,mppt10_v,mppt11_v,mppt12_v,mppt13_v,mppt15_v,mppt16_v, mppt1_i, mppt2_i, mppt3_i, mppt4_i, mppt5_i, mppt6_i, mppt7_i,mppt8_i, mppt9_i, mppt10_i, mppt11_i, mppt12_i, mppt13_i, mppt14_i, mppt15_i);
    //chprintf((BaseSequentialStream *)&SDU1,"%x %x %x %x %x %x %x %x \n",RxMessage33.StdId, RxMessage44.StdId, RxMessage55.StdId, RxMessage66.StdId, RxMessage77.StdId, RxMessage88.StdId, RxMessage99.StdId, RxMessage11.StdId); 
    //chprintf((BaseSequentialStream *)&SD1,"tes \n");
    chThdSleepMilliseconds(500);
}
   return 0 ;
}	

CH_IRQ_HANDLER(STM32_CAN1_RX0_HANDLER) {

  CH_IRQ_PROLOGUE();
  GPIO_E->ODR ^= (1<<9);  
  CAN_Receive(CAN1, CAN_FIFO0, &RawMessage);
  
  switch (RawMessage.StdId){
	  case 0x33:
	  RxMessage33=RawMessage;
	  break;
	  case 0x44:
	  RxMessage44=RawMessage;
	  break;
	  case 0x55:
	  RxMessage55=RawMessage;
	  break;
	  case 0x66:
	  RxMessage66=RawMessage;
	  break;
	  case 0x77:
	  RxMessage77=RawMessage;
	  break;
	  case 0x88:
	  RxMessage88=RawMessage;
	  break;
	  case 0x99:
	  RxMessage99=RawMessage;
	  break;
	  case 0x11:
	  RxMessage11=RawMessage;
	  break;
	  case 0x01B:
	  RxMessage1B=RawMessage;
	  break;
	  case 0x6B2:
	  RxMessage6B2=RawMessage;
	  break;
	  case 0x3CB:
	  RxMessage3CB=RawMessage;
	  break;
	  case 0x03B:
	  RxMessage3B=RawMessage;
	  break;
  }    
  CH_IRQ_EPILOGUE();
}

//fungsi inisialisasi CAN (Controller Area Network)
static void CAN_Config(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  //NVIC_InitTypeDef  NVIC_InitStructure;
  CAN_InitTypeDef        CAN_InitStructure;
  CAN_FilterInitTypeDef  CAN_FilterInitStructure;
    
  /* CAN GPIOs configuration **************************************************/

  /* Connect CAN pins to AF7 */
  GPIO_PinAFConfig(CAN_GPIO_PORT, CAN_RX_SOURCE, CAN_AF_PORT);
  GPIO_PinAFConfig(CAN_GPIO_PORT, CAN_TX_SOURCE, CAN_AF_PORT); 
  
  /* Configure CAN RX and TX pins */
  GPIO_InitStructure.GPIO_Pin = CAN_RX_PIN | CAN_TX_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(CAN_GPIO_PORT, &GPIO_InitStructure);

  /* NVIC configuration *******************************************************/
  nvicEnableVector(STM32_CAN1_RX0_NUMBER, 
                   CORTEX_PRIORITY_MASK(STM32_CAN_CAN1_IRQ_PRIORITY));
  
  /* CAN configuration ********************************************************/  
  /* Enable CAN clock */
  rccEnableAPB1(RCC_APB1ENR_CAN1EN, 2); //alamat header --> os/hal/platforms/
  
  
  /* CAN register init */
  //CAN_DeInit(CANx);
  CAN_StructInit(&CAN_InitStructure);

  /* CAN cell init */
  CAN_InitStructure.CAN_TTCM = DISABLE;
  CAN_InitStructure.CAN_ABOM = DISABLE;
  CAN_InitStructure.CAN_AWUM = DISABLE;
  CAN_InitStructure.CAN_NART = DISABLE;
  CAN_InitStructure.CAN_RFLM = DISABLE;
  CAN_InitStructure.CAN_TXFP = DISABLE;
  CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
  CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    
  /* CAN Baudrate = 1MBps (CAN clocked at 36 MHz) */
  CAN_InitStructure.CAN_BS1 = CAN_BS1_9tq;
  CAN_InitStructure.CAN_BS2 = CAN_BS2_8tq;
  CAN_InitStructure.CAN_Prescaler = 2;
  CAN_Init(CANx, &CAN_InitStructure);

  /* CAN filter init */
  CAN_FilterInitStructure.CAN_FilterNumber = 0;
  CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
  CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 0;
  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
  CAN_FilterInit(&CAN_FilterInitStructure); 
  
  /*TxMessage.StdId = 0x111;
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 8;
  
  TxMessage2.StdId = 0x222;
  TxMessage2.RTR = CAN_RTR_DATA;
  TxMessage2.IDE = CAN_ID_STD;
  TxMessage2.DLC = 8;
  
  TxMessage3.StdId = 0x333;
  TxMessage3.RTR = CAN_RTR_DATA;
  TxMessage3.IDE = CAN_ID_STD;
  TxMessage3.DLC = 8;
  
  TxMessage3.StdId = 0x444;
  TxMessage3.RTR = CAN_RTR_DATA;
  TxMessage3.IDE = CAN_ID_STD;
  TxMessage3.DLC = 8;
  */
  /* Mengaktifkan FIFO 0 message pending Interrupt */
  CAN_ITConfig(CANx, CAN_IT_FMP0, ENABLE);
  
}



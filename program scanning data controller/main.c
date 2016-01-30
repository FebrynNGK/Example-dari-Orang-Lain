//memasukkan header file
#include "main.h"

SerialUSBDriver SDU1;
BaseSequentialStream* chp =(BaseSequentialStream*) &SDU1;
#define usb_lld_connect_bus(usbp)
#define usb_lld_disconnect_bus(usbp)

int usb_flag=0;

void printCAN(void);
static void CAN_Config(void);



//Shell comand  (perintah lewat serial terminal)
void sendCan(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argc;
  (void)argv;
  /*if (argc != 2) {
    chprintf(chp, "pwm -pulsewidth- -period-\r\n");
    return;
  }
  //duty_cycle = atoi(argv[0]);
  //period_motorDC = atoi(argv[1]);
  //chprintf((BaseSequentialStream *)&SDU1, "duty_cycle=%d\r\n", duty_cycle);
  */
  //chprintf((BaseSequentialStream *)&SDU1, "test...");
  printCAN();
}

void send_data(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argc;
  (void)argv;
  //chprintf((BaseSequentialStream *)&SD1, "[180,15,38,1,1,1,1,1,1,1]\r\n");
  //chprintf((BaseSequentialStream *)&SD1, "[%d,%d,%d,%d,%d,%d,%d,%d]\r\n",kanan,kiri,jauh,dekat,kota,rem,rpm,velocity);
}

#define SHELL_WA_SIZE   THD_WA_SIZE(2048)
static const ShellCommand commands[] = {
  {"c", sendCan},
  {"x", send_data},
  {NULL, NULL}
};
static const ShellConfig shell_cfg1 = {
  (BaseSequentialStream *)&SDU1,
  commands
};
static const ShellConfig shell_sd1 = {
  (BaseSequentialStream *)&SD1,
  commands
};

//fungsi utama
int main (void) {
	Thread *shelltp = NULL;//deklarasi thread shell comand
	//inisialisasi HAL (Hardware Abstraction Layer)
	halInit();
	
	//inisialisasi kernel
	chSysInit();
	
	 sdStart(&SD1, NULL);
     sdStart(&SD2, NULL);
     static WORKING_AREA(waShellsd1, 2048);
     shellCreateStatic(&shell_sd1, waShellsd1, sizeof(waShellsd1), NORMALPRIO);
	
	//inisialisasi CAN
	CAN_Config();

	//inisialisasi USB
	sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);
    
    //aktifasi USB
    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(200);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);
    
    shellInit();

while(TRUE) {
	
	  CAN_Transmit(CANx, &TxMessage);
	//khusus USB Comand
    if (!shelltp && (SDU1.config->usbp->state == USB_ACTIVE))
    	{
    		shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO);//mengaktifkan shell comand
		usb_flag=1;
    	}
    	
    else if (chThdTerminated(shelltp))
    	{
			chThdRelease(shelltp);    /* Recovers memory of the previous shell.   */
			shelltp = NULL;           /* Triggers spawning of a new shell.        */
        }
    GPIO_E->ODR ^= (1<<13);
    chThdSleepMilliseconds(500);//delay looping main thread
    rpm += 1;
    if (rpm==255)rpm=0;
      
  }
  return 0;	
}

void printCAN(void)
{
  
  int i=0;
  chprintf((BaseSequentialStream *)&SDU1, "<%X,", RxMessage.StdId);
  chprintf((BaseSequentialStream *)&SDU1, "%d,", RxMessage.DLC);
  for(i=0;i<RxMessage.DLC ;i++)
    chprintf((BaseSequentialStream *)&SDU1, "%X,",RxMessage.Data[i]);
  if(RxMessage.DLC<8){
    for(i=0;i<(8-RxMessage.DLC) ;i++)
    chprintf((BaseSequentialStream *)&SDU1, "0,");
  }
  //chprintf((BaseSequentialStream *)&SDU1, ">,", RxMessage.StdId);
}


CH_IRQ_HANDLER(STM32_CAN1_RX0_HANDLER) {

  CH_IRQ_PROLOGUE();
  GPIO_E->ODR ^= (1<<9);  
  CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);
  
  /*switch(RawMessage.StdId){
	  
  case 0x12D://motor
  RxMessage12D = RawMessage;
  rpm = RawMessage.Data[0];
  break;
  */   
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
  
  /* Mengaktifkan FIFO 0 message pending Interrupt */
  CAN_ITConfig(CANx, CAN_IT_FMP0, ENABLE);
  
}



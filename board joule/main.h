/**
  ******************************************************************************
  * @file    CAN/CAN_FIFOExtension/main.h 
  * @author  MCD Application Team
  * @version V1.1.1
  * @date    31-October-2014
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "ch.h"
#include "hal.h"
#include <string.h>
#include "stm32f30x.h"
#include "usbcfg.h"
#include "chprintf.h"
#include "adc_it.h"
#include "my_kirim.h"
#include "my_process.h"
#include "my_pin.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

#define CANx                       CAN1
#define CAN_CLK                    RCC_APB1Periph_CAN1
#define CAN_RX_PIN                 GPIO_Pin_0
#define CAN_TX_PIN                 GPIO_Pin_1
#define CAN_GPIO_PORT              GPIO_D
#define CAN_GPIO_CLK               RCC_AHBPeriph_GPIOD
#define CAN_AF_PORT                GPIO_AF_7
#define CAN_RX_SOURCE              GPIO_PinSource0
#define CAN_TX_SOURCE              GPIO_PinSource1

//struktur komunikasi serial melalui USB
SerialUSBDriver SDU1;
BaseSequentialStream* chp =(BaseSequentialStream*) &SDU1;
#define usb_lld_connect_bus(usbp)
#define usb_lld_disconnect_bus(usbp)

//definisi CAN Transmit
CanTxMsg TxMessage 		= {0};
CanTxMsg TxMessage2		= {0};
CanTxMsg TxMessage3		= {0};
CanTxMsg TxMessage4		= {0};

CanRxMsg RawMessage 	= {0};
CanRxMsg RxMessage 		= {0};

//definisi CAN Receive
//ID Tegangan
CanRxMsg RxMessage33 	= {0};
CanRxMsg RxMessage44 	= {0};
CanRxMsg RxMessage55 	= {0};
CanRxMsg RxMessage66 	= {0};

//ID Arus
CanRxMsg RxMessage77	= {0};
CanRxMsg RxMessage88	= {0};
CanRxMsg RxMessage99	= {0};
CanRxMsg RxMessage11	= {0};

//ID BMS
CanRxMsg RxMessage1B 	= {0};
CanRxMsg RxMessage3B 	= {0};
CanRxMsg RxMessage6B2 	= {0};
CanRxMsg RxMessage3CB 	= {0};


int lowvolt1		= 0;
int lowvolt2		= 0;
int highvolt1		= 0;
int highvolt2		= 0;
int packvolt1		= 0;
int packvolt2		= 0;
int packcurrent1	= 0;
int packcurrent2	= 0;
int amphours1		= 0;
int amphours2		= 0;
int packDODraw	    = 0;
int avgcellvolt1	= 0;
int avgcellvolt2	= 0;

int avgcellvoltraw	= 0;
int supply12vraw	= 0;
int amphoursraw		= 0;
int packcurrentraw	= 0;
int packsocraw		= 0;
int packvoltraw		= 0;
int lowvolt			= 0;
int highvolt		= 0;

float avgcellvolt	= 0.0000;
float deltacellvolt	= 0.0;
float packDOD		= 0.0;
float supply12v		= 0.0;
float amphours 		= 0.0;
float packcurrent	= 0.0;
float packvolt		= 0.0;
float lowvoltcell   = 0.0000;
float highvoltcell  = 0.0000;
float packsoc   	= 0.0;
int avgtemp			= 0;
int hightemp		= 0;
int lowtemp			= 0;
int packDCL			= 0;
int packCCL			= 0;

//definisi data tegangan
int voltMPPT1_1		= 0;
int voltMPPT1_2		= 0;
int voltMPPT2_1		= 0;
int voltMPPT2_2		= 0;
int voltMPPT3_1		= 0;
int voltMPPT3_2		= 0;
int voltMPPT4_1		= 0;
int voltMPPT4_2		= 0;
int voltMPPT5_1		= 0;
int voltMPPT5_2		= 0;
int voltMPPT6_1		= 0;
int voltMPPT6_2		= 0;
int voltMPPT7_1		= 0;
int voltMPPT7_2		= 0;
int voltMPPT8_1		= 0;
int voltMPPT8_2		= 0;
int voltMPPT9_1		= 0;
int voltMPPT9_2		= 0;
int voltMPPT10_1    = 0;
int voltMPPT10_2	= 0;
int voltMPPT11_1	= 0;
int voltMPPT11_2	= 0;
int voltMPPT12_1	= 0;
int voltMPPT12_2	= 0;
int voltMPPT13_1	= 0;
int voltMPPT13_2	= 0;
int voltMPPT15_1	= 0;
int voltMPPT15_2	= 0;
int voltMPPT16_1	= 0;
int voltMPPT16_2	= 0;

int voltMPPT1		= 0;
int voltMPPT2		= 0;
int voltMPPT3		= 0;
int voltMPPT4		= 0;
int voltMPPT5		= 0;
int voltMPPT6		= 0;
int voltMPPT7		= 0;
int voltMPPT8		= 0;
int voltMPPT9		= 0;
int voltMPPT10		= 0;
int voltMPPT11		= 0;
int voltMPPT12		= 0;
int voltMPPT13		= 0;
int voltMPPT15		= 0;
int voltMPPT16		= 0;

  float mppt1_v ;
  float mppt2_v ;
  float mppt3_v ;
  float mppt4_v ;
  float mppt5_v ;
  float mppt6_v ;
  float mppt7_v ;
  float mppt8_v ;
  float mppt9_v ;
  float mppt10_v ;
  float mppt11_v ;
  float mppt12_v ;
  float mppt13_v ;
  float mppt15_v ;
  float mppt16_v ;
  
//definisi data arus  
int currentMPPT1_1		= 0;
int currentMPPT1_2		= 0;
int currentMPPT2_1		= 0;
int currentMPPT2_2		= 0;
int currentMPPT3_1		= 0;
int currentMPPT3_2		= 0;
int currentMPPT4_1		= 0;
int currentMPPT4_2		= 0;
int currentMPPT5_1		= 0;
int currentMPPT5_2		= 0;
int currentMPPT6_1		= 0;
int currentMPPT6_2		= 0;
int currentMPPT7_1		= 0;
int currentMPPT7_2		= 0;
int currentMPPT8_1		= 0;
int currentMPPT8_2		= 0;
int currentMPPT9_1		= 0;
int currentMPPT9_2		= 0;
int currentMPPT10_1     = 0;
int currentMPPT10_2		= 0;
int currentMPPT11_1		= 0;
int currentMPPT11_2		= 0;
int currentMPPT12_1		= 0;
int currentMPPT12_2		= 0;
int currentMPPT13_1		= 0;
int currentMPPT13_2		= 0;
int currentMPPT14_1		= 0;
int currentMPPT14_2		= 0;
int currentMPPT15_1		= 0;
int currentMPPT15_2		= 0;

int currentMPPT1		= 0;
int currentMPPT2		= 0;
int currentMPPT3		= 0;
int currentMPPT4		= 0;
int currentMPPT5		= 0;
int currentMPPT6		= 0;
int currentMPPT7		= 0;
int currentMPPT8		= 0;
int currentMPPT9		= 0;
int currentMPPT10		= 0;
int currentMPPT11		= 0;
int currentMPPT12		= 0;
int currentMPPT13		= 0;
int currentMPPT14		= 0;
int currentMPPT15		= 0;

  float mppt1_i ;
  float mppt2_i ;
  float mppt3_i ;
  float mppt4_i ;
  float mppt5_i ;
  float mppt6_i ;
  float mppt7_i ;
  float mppt8_i ;
  float mppt9_i ;
  float mppt10_i ;
  float mppt11_i ;
  float mppt12_i ;
  float mppt13_i ;
  float mppt14_i ;
  float mppt15_i ;


extern float current1;
extern float current2;
extern float current3;
extern float voltage1;
extern float voltage2;
extern float voltage3;
extern float daya1;
extern float daya2;
extern float daya3;
extern float energy1_wh;
extern float energy2_wh;
extern float energy3_wh;

int arus1;
int arus2;
int arus3;
int volt1;
int volt2;
int volt3;
int watt1;
int watt2;
int watt3;
int joule1;
int joule2;
int joule3;

extern int milidetik,detik,menit,jam;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
static void CAN_Config(void);

#endif /* __MAIN_H */


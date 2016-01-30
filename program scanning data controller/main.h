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
#include "shell.h"
#include <string.h>
#include "stm32f30x.h"
#include "usbcfg.h"
#include "chprintf.h"

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


//definisi CAN Transmit
CanTxMsg TxMessage 		= {0};
CanRxMsg RxMessage 		= {0};
CanRxMsg RawMessage 	= {0};

CanRxMsg RxMessage12D	= {0};
CanRxMsg RxMessage137	= {0};

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
CanRxMsg RxMessage36	= {0};

//ID Joule
CanRxMsg RxMessage111 	= {0};
CanRxMsg RxMessage222 	= {0};
CanRxMsg RxMessage333 	= {0};
CanRxMsg RxMessage444 	= {0};

int rpm = 0;

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
int speed			= 0;

//brodcast cell voltage
int cellvolt0_1		= 0;
int cellvolt0_2		= 0;
int cellvolt1_1		= 0;
int cellvolt1_2		= 0;
int cellvolt2_1		= 0;
int cellvolt2_2		= 0;
int cellvolt3_1		= 0;
int cellvolt3_2		= 0;
int cellvolt4_1		= 0;
int cellvolt4_2		= 0;
int cellvolt5_1		= 0;
int cellvolt5_2		= 0;
int cellvolt6_1		= 0;
int cellvolt6_2		= 0;
int cellvolt7_1		= 0;
int cellvolt7_2		= 0;
int cellvolt8_1		= 0;
int cellvolt8_2		= 0;
int cellvolt9_1		= 0;
int cellvolt9_2		= 0;
int cellvolt10_1		= 0;
int cellvolt10_2		= 0;

int cellvolt11_1		= 0;
int cellvolt11_2		= 0;
int cellvolt12_1		= 0;
int cellvolt12_2		= 0;
int cellvolt13_1		= 0;
int cellvolt13_2		= 0;
int cellvolt14_1		= 0;
int cellvolt14_2		= 0;
int cellvolt15_1		= 0;
int cellvolt15_2		= 0;
int cellvolt16_1		= 0;
int cellvolt16_2		= 0;
int cellvolt17_1		= 0;
int cellvolt17_2		= 0;
int cellvolt18_1		= 0;
int cellvolt18_2		= 0;
int cellvolt19_1		= 0;
int cellvolt19_2		= 0;
int cellvolt20_1		= 0;
int cellvolt20_2		= 0;

int cellvolt21_1		= 0;
int cellvolt21_2		= 0;
int cellvolt22_1		= 0;
int cellvolt22_2		= 0;
int cellvolt23_1		= 0;
int cellvolt23_2		= 0;
int cellvolt24_1		= 0;
int cellvolt24_2		= 0;
int cellvolt25_1		= 0;
int cellvolt25_2		= 0;
int cellvolt26_1		= 0;
int cellvolt26_2		= 0;
int cellvolt27_1		= 0;
int cellvolt27_2		= 0;
int cellvolt28_1		= 0;
int cellvolt28_2		= 0;
int cellvolt29_1		= 0;
int cellvolt29_2		= 0;
int cellvolt30_1		= 0;
int cellvolt30_2		= 0;
int cellvolt31_1		= 0;
int cellvolt31_2		= 0;
int cellvolt32_1		= 0;
int cellvolt32_2		= 0;
int cellvolt33_1		= 0;
int cellvolt33_2		= 0;

int cellvolt1raw		= 0;
int cellvolt2raw		= 0;
int cellvolt3raw		= 0;
int cellvolt4raw		= 0;
int cellvolt5raw		= 0;
int cellvolt6raw		= 0;
int cellvolt7raw		= 0;
int cellvolt8raw		= 0;
int cellvolt9raw		= 0;
int cellvolt10raw		= 0; //tidak ada data
int cellvolt11raw		= 0; //tidak ada data
int cellvolt12raw		= 0; //tidak ada data
int cellvolt13raw		= 0;
int cellvolt14raw		= 0;
int cellvolt15raw		= 0;
int cellvolt16raw		= 0;
int cellvolt17raw		= 0;
int cellvolt18raw		= 0;
int cellvolt19raw		= 0;
int cellvolt20raw		= 0;
int cellvolt21raw		= 0;
int cellvolt22raw		= 0; //tidak ada data
int cellvolt23raw		= 0; //tidak ada data
int cellvolt24raw		= 0; //tidak ada data
int cellvolt25raw		= 0;
int cellvolt26raw		= 0;
int cellvolt27raw		= 0;
int cellvolt28raw		= 0;
int cellvolt29raw		= 0;
int cellvolt30raw		= 0;
int cellvolt31raw		= 0;
int cellvolt32raw		= 0;
int cellvolt33raw		= 0;


float cellvolt1		= 0.000;
float cellvolt2		= 0.000;
float cellvolt3		= 0.000;
float cellvolt4		= 0.000;
float cellvolt5		= 0.000;
float cellvolt6		= 0.000;
float cellvolt7		= 0.000;
float cellvolt8		= 0.000;
float cellvolt9		= 0.000;
float cellvolt10    = 0.000; //tidak ada data
float cellvolt11		= 0.000; //tidak ada data
float cellvolt12		= 0.000; //tidak ada data
float cellvolt13		= 0.000;
float cellvolt14		= 0.000;
float cellvolt15		= 0.000;
float cellvolt16		= 0.000;
float cellvolt17		= 0.000;
float cellvolt18		= 0.000;
float cellvolt19		= 0.000;
float cellvolt20		= 0.000;
float cellvolt21		= 0.000;
float cellvolt22		= 0.000; //tidak ada data
float cellvolt23		= 0.000; //tidak ada data
float cellvolt24		= 0.000; //tidak ada data
float cellvolt25		= 0.000;
float cellvolt26		= 0.000;
float cellvolt27		= 0.000;
float cellvolt28		= 0.000;
float cellvolt29		= 0.000;
float cellvolt30		= 0.000;
float cellvolt31		= 0.000;
float cellvolt32		= 0.000;
float cellvolt33		= 0.000;

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

int currentjoule1		= 0;
int currentjoule2		= 0;
int currentjoule3		= 0;
int voltjoule1			= 0;
int voltjoule2			= 0;
int voltjoule3			= 0;
int wattjoule1			= 0;
int wattjoule2			= 0;
int wattjoule3			= 0;
int energijoule1		= 0;
int energijoule2		= 0;
int energijoule3		= 0;
int milidetik			= 0;
int detik				= 0;
int menit				= 0;
int jam					= 0;

int currentjoule1_1		= 0;
int currentjoule1_2		= 0;
int currentjoule2_1		= 0;
int currentjoule2_2		= 0;
int currentjoule3_1		= 0;
int currentjoule3_2		= 0;
int voltjoule1_1		= 0;
int voltjoule1_2		= 0;
int voltjoule2_1		= 0;
int voltjoule2_2		= 0;
int voltjoule3_1		= 0;
int voltjoule3_2		= 0;
int wattjoule1_1		= 0;
int wattjoule1_2		= 0;
int wattjoule2_1		= 0;
int wattjoule2_2		= 0;
int wattjoule3_1		= 0;
int wattjoule3_2		= 0;
int energijoule1_1		= 0;
int energijoule1_2		= 0;
int energijoule2_1		= 0;
int energijoule2_2		= 0;
int energijoule3_1		= 0;
int energijoule3_2		= 0;
int milidetik_1			= 0;
int milidetik_2			= 0;
int detik_1				= 0;
int detik_2				= 0;
int menit_1				= 0;
int menit_2				= 0;
int jam_1				= 0;
int jam_2				= 0;

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

int arus1=0;
int arus2=0;
int arus3=0;
int volt1=0;
int volt2=0;
int volt3=0;
int watt1=0;
int watt2=0;
int watt3=0;
int joule1=0;
int joule2=0;
int joule3=0;

float current1;
float current2;
float current3;
float voltage1;
float voltage2;
float voltage3;
float daya1;
float daya2;
float daya3;
float energy1_wh;
float energy2_wh;
float energy3_wh;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */


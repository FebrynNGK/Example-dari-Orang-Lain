#include "my_pin.h"

#include "my_process.h"


static WORKING_AREA(wa_pininThread, 128);
static msg_t pininThread(void *arg) {
  (void)arg;
 while (TRUE) {
      


  }
  return 0;
}

static WORKING_AREA(wa_pinoutThread, 128);
static msg_t pinoutThread(void *arg) {
  (void)arg;
 while (TRUE) {
     riting_kanan();
     riting_kiri();
     hazard();

  }
  return 0;
}

void Pin_Setup(void){
  palSetPadMode(GPIOE,1,PAL_MODE_INPUT_PULLDOWN);
        palSetPadMode(GPIOE,6,PAL_MODE_INPUT_PULLDOWN); //i1
        palSetPadMode(GPIOB,8,PAL_MODE_INPUT_PULLDOWN); //i2

        palSetPadMode(GPIOC,11,PAL_MODE_INPUT_PULLDOWN);//i4

        palSetPadMode(GPIOB,2,PAL_MODE_OUTPUT_PUSHPULL);  //o1
        palSetPadMode(GPIOE,12,PAL_MODE_OUTPUT_PUSHPULL); //o2
        palSetPadMode(GPIOE,14,PAL_MODE_OUTPUT_PUSHPULL); //o3
        palSetPadMode(GPIOB,0,PAL_MODE_OUTPUT_PUSHPULL);  //o4

}

void input_output_test(void){

    palSetPad(GPIOB,2);
    palSetPad(GPIOE,12);
    palSetPad(GPIOE,14);
    palSetPad(GPIOB,0);

    chThdSleepMilliseconds(500);

    palClearPad(GPIOE,12);
    palClearPad(GPIOB,2);
    palClearPad(GPIOE,14);
    palClearPad(GPIOB,0);

        chThdSleepMilliseconds(500);
    }

void riting_kiri(void){
    if(palReadPad(GPIOB,8)==PAL_LOW){

        palSetPad(GPIOE,12);
        palSetPad(GPIOB,2);
        chThdSleepMilliseconds(500);
        palClearPad(GPIOE,12);
        palClearPad(GPIOB,2);
        chThdSleepMilliseconds(500);
}

        if(palReadPad(GPIOF,9)==PAL_LOW){

            palSetPad(GPIOE,14);
            palSetPad(GPIOB,0);
            chThdSleepMilliseconds(500);
            palClearPad(GPIOE,14);
            palClearPad(GPIOB,0);
            chThdSleepMilliseconds(500);


        }
            if(palReadPad(GPIOC,13)==PAL_LOW){
                palSetPad(GPIOE,14);
                 palSetPad(GPIOE,12);
                 palSetPad(GPIOB,2);
                 palSetPad(GPIOB,0);
                chThdSleepMilliseconds(500);
                palClearPad(GPIOE,14);
                 palClearPad(GPIOE,12);
                 palClearPad(GPIOB,0);
                 palClearPad(GPIOB,2);
                chThdSleepMilliseconds(500);
      }

}

void riting_kanan(void){


}

void hazard(void){


}

void input_output_running(void){
    Pin_Setup();
    chThdCreateStatic(wa_pininThread, sizeof(wa_pininThread), NORMALPRIO, pininThread, NULL);
        chThdCreateStatic(wa_pinoutThread, sizeof(wa_pinoutThread), NORMALPRIO, pinoutThread, NULL);
}






#ifndef PIN_H
#define PIN_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "memstreams.h"
#include "evtimer.h"

void Pin_Setup(void);
void input_output_test(void);
void input_output_running(void);
void riting_kiri(void);
void riting_kanan(void);
void hazard(void);

#endif

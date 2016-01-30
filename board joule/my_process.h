#ifndef PROCESS_H
#define PROCESS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "memstreams.h"
#include "evtimer.h"

void current_sensor(void);
void voltage_sensor(void);
void daya(void);
void energy(void);
void fungsi_rata2(void);
void process_running(void);

#endif

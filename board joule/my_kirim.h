#ifndef KIRIM_H
#define KIRIM_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "memstreams.h"
#include "evtimer.h"

void kirim_setup(void);
void kirim_data_usart1(void);

#endif

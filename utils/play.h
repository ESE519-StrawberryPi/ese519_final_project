//
// Created by Haoze Wu on 12/3/22.
//

#include "../config.h"
#include "pwm_utils.h"

#ifndef FINAL_PROJECT_PLAY_H
#define FINAL_PROJECT_PLAY_H

void play_mode(PIO pio, uint sm,uint8_t *data, int dataLen);
void record_music(int charArrLen);
void load_music(int charArrLen, PIO pio, uint sm, uint32_t period);

#endif //FINAL_PROJECT_PLAY_H

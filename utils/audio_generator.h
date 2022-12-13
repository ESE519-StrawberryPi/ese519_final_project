//
// Created by Haoze Wu on 12/3/22.
//

#ifndef FINAL_PROJECT_AUDIO_GENERATOR_H
#define FINAL_PROJECT_AUDIO_GENERATOR_H

#include "pwm_utils.h"

void free_mode(PIO pio, uint sm);
void play_a_note(PIO pio, uint sm, uint32_t period, char c);

#endif //FINAL_PROJECT_AUDIO_GENERATOR_H

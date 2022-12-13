//
// Created by Haoze Wu on 12/3/22.
//

#include "../config.h"
#include "pwm_utils.h"


#ifndef FINAL_PROJECT_PLAY_H
#define FINAL_PROJECT_PLAY_H

/// Play a pre-defined music.
/// \param pio PIO to be used
/// \param sm State machine to be used
/// \param data Pre-defined music data
/// \param dataLen Length of the music data
void play_mode(PIO pio, uint sm,uint8_t *data, int dataLen);

/// Record music sample from keypad input
/// \param charArrLen Length of the input
/// \param pio PIO to be used
/// \param sm State machine to be used
void record_music(int charArrLen,PIO pio, uint sm);

/// Loaded recorded music sample
/// \param charArrLen Length of the music sample
/// \param pio PIO to be used
/// \param sm State machine to be used
/// \param period  PWM period of sample
void load_music(int charArrLen, PIO pio, uint sm, uint32_t period);

/// A hardcoded version play mode for multicore usage in gaming mode
void play_mode_no_param();

/// Callback of hardcoded play mode function
void core1_entry();

#endif //FINAL_PROJECT_PLAY_H

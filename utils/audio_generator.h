//
// Created by Haoze Wu on 12/3/22.
//

#ifndef FINAL_PROJECT_AUDIO_GENERATOR_H
#define FINAL_PROJECT_AUDIO_GENERATOR_H

#include "pwm_utils.h"

/// Free play mode
/// \param pio PIO to be used
/// \param sm State machine to be used
void free_mode(PIO pio, uint sm);

/// Function  to be utilized in free mode. Playing single notes, i.e. single keypad input.
/// \param pio PIO to be used
/// \param sm State machine to be used
/// \param period Period of PWM signal
/// \param c Notes to be played, ranging from 1 to 7
void play_a_note(PIO pio, uint sm, uint32_t period, char c);

#endif //FINAL_PROJECT_AUDIO_GENERATOR_H

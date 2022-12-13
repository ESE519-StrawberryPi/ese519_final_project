//
// Created by Haoze Wu on 12/3/22.
//

#include "../config.h"

#ifndef FINAL_PROJECT_PWM_UTILS_H
#define FINAL_PROJECT_PWM_UTILS_H

/// Set PWM period for the PWM PIO module
/// \param pio PIO instance
/// \param sm State machine index
/// \param period PWM period
void pio_pwm_set_period(PIO pio, uint sm, uint32_t period);

/// Set PWM duty cycle for the PWM PIO module
/// \param pio PIO instance
/// \param sm State machine index
/// \param level Duty cycle, i.e. the number of high level pulses, representing the music notes
void pio_pwm_set_level(PIO pio, uint sm, uint32_t level);

#endif //FINAL_PROJECT_PWM_UTILS_H

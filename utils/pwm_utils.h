//
// Created by Haoze Wu on 12/3/22.
//

#include "../config.h"

#ifndef FINAL_PROJECT_PWM_UTILS_H
#define FINAL_PROJECT_PWM_UTILS_H

void pio_pwm_set_period(PIO pio, uint sm, uint32_t period);

void pio_pwm_set_level(PIO pio, uint sm, uint32_t level);

#endif //FINAL_PROJECT_PWM_UTILS_H

//
// Created by Haoze Wu on 12/9/22.
//

#include <stdio.h>
#include "pico/stdlib.h"

#ifndef FINAL_PROJECT_ZRX543_DRIVER_H
#define FINAL_PROJECT_ZRX543_DRIVER_H

/// Get single key input from keypad
/// \return Key pressed in Char format
char getKey();

/// Initialize the keypad hardcoded GPIO pins
void init_gpio();

#endif //FINAL_PROJECT_ZRX543_DRIVER_H

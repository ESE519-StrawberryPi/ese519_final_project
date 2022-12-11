//
// Created by Haoze Wu on 12/11/22.
//
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"

#ifndef FINAL_PROJECT_GAME_MODE_H
#define FINAL_PROJECT_GAME_MODE_H

void display_score(int score);
int judge(uint16_t x_idx,uint16_t y_idx, int flag, char key, uint16_t speed);
int display_games(uint16_t *note_queue, int length);
void show(int y);
void game_mode_test();

#endif //FINAL_PROJECT_GAME_MODE_H

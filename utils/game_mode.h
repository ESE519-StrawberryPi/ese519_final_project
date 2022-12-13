//
// Created by Haoze Wu on 12/11/22.
//

#include "../config.h"
#include "../st7735_driver/st7735_driver.h"

#ifndef FINAL_PROJECT_GAME_MODE_H
#define FINAL_PROJECT_GAME_MODE_H

/// Clear gaming screen and display the score
/// \param score Score to be displayed
void display_score(int score);

/// Judge whether a keypad input at a certain position is correct or not
/// \param x_idx x-axis position
/// \param y_idx y-axis position
/// \param flag previous judgement result of a same block
/// \param key keypad input
/// \param speed speed of fallen blocks
/// \return result of judgement
int judge(uint16_t x_idx,uint16_t y_idx, int flag, char key, uint16_t speed);

///
/// \param note_queue  positions in x-axis of fallen blocks
/// \param length length of the notes queue
/// \return score after finish the game
int display_games(uint16_t *note_queue, int length);

/// Callback for game mode
void game_mode_test();

#endif //FINAL_PROJECT_GAME_MODE_H

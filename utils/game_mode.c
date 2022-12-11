//
// Created by Haoze Wu on 12/11/22.
//

#include "game_mode.h"

#include "../st7735_driver/st7735_driver.h"
#include <pico/stdlib.h>
#include "sl_utils.h"
#include "../zrx_543_driver/zrx543_driver.h"

const uint16_t width = 80;
const uint16_t height = 160;


const uint16_t block_width = 20;
const uint16_t block_height = 10;
const uint16_t block_speed = 20;

const uint16_t bar_x = 0;
const uint16_t bar_y = 148;
const uint16_t bar_height = 2;
const uint16_t bar_width = 80;

const uint16_t correct_range_upper = height - 3 * block_height;
const uint16_t correct_range_bottom = height;

const char index_arr[] ={'1','2','3','A'};

const int prefect_score = 100;

void display_score(int score){
    int x = 5;
    int y = 70;
    ST7735_WriteString(x, y,"Score  ",Font_7x10,ST7735_BLACK,ST7735_GREEN);
    char score_str[10];
    sprintf(score_str,"%d",score);
    printf("score_str: %d", score);


    ST7735_WriteString(x + 43, y,score_str,Font_7x10,ST7735_BLACK,ST7735_GREEN);
    ST7735_WriteString(x,y + 10,"         ",Font_7x10,ST7735_BLACK,ST7735_GREEN);
    ST7735_WriteString(x,y + 20,"Press #  ",Font_7x10,ST7735_BLACK,ST7735_GREEN);
    ST7735_WriteString(x,y + 30,"to quit  ",Font_7x10,ST7735_BLACK,ST7735_GREEN);
}

int judge(uint16_t x_idx, uint16_t y_idx, int flag, char key, uint16_t speed) {
    printf("Begin Judge\n");
    if(flag == 2) return 2;
    if(flag == 1) return 1;

//    char key = get_key_timeout_us(250 * 1000);
    printf("%c\n",key);
    if(key == 'm'){
        printf("No Click Detected\n");
        return 0;
    }
    // Check the index of x-axis is correct or not
    if (index_arr[x_idx] != key) {
        printf("Wrong Axis Click\n");
        return 2;
    } else {
        // if y is correct
        int absolute_height = y_idx *  speed;
        if (absolute_height >= correct_range_upper && absolute_height <= correct_range_bottom) {
            printf("Perfect Click\n");
            return 1;
        }else{
            printf("Correct Axis but wrong timing\n");
            return 2;
        }
    }
}
/*
 * Game display, according to the notes queue.
 */
int display_games(uint16_t *note_queue, int length) {
    uint16_t speed = rand()%10 + block_speed;
    int index = 0;
    int max_step_height = 160 / speed;
    int score = 0;


    while(index < length) {
        sleep_ms(100);
        // Draw a rectangular with left upper bound at (x,y), and a width of 1/4 of the width of the screen,
        // 1/16 of the height of the screen
        int count = 0;
        int x_position_index = note_queue[index];
        int flag = 0; // 0: exist; 1:correct; 2: wrong;

        while(count < max_step_height + 1) {
            printf("Count :%d\n",count);
            sleep_ms(100);
            ST7735_FillRectangle(0, 0, 80, 160, ST7735_BLACK);
            ST7735_FillRectangle(bar_x, bar_y,bar_width, bar_height, ST7735_WHITE);
            char key = get_key_timeout_us(250* 1000);
//            int key = getchar_timeout_us(5*1000*1000);
            printf("key: %c\n", key);
            // bottom-left position (index) of brick
            flag = judge(x_position_index, count, flag, key, speed);

            printf("flag: %d\n", flag);

            // Move the rectangular down each iteration, each time move down 1/8 of the height of the screen.
            if(flag == 0){
                ST7735_FillRectangle(block_width * x_position_index, speed*count,block_width,block_height,
                                     ST7735_GREEN);
            }else if(flag == 1){
                ST7735_FillRectangle(block_width * x_position_index, speed*count,block_width,block_height,
                                     ST7735_YELLOW);
            }else if(flag == 2){
                ST7735_FillRectangle(block_width * x_position_index, speed * count, block_width, block_height,
                                     ST7735_RED);
            }
            count++;
        }
        printf("Index :%d\n",index);
        if(flag == 1){
            score += prefect_score;
        }
        index++;

        // After moving the rectangular down to the bottom of the screen, continue generating new rectangular
        // with respect to the new notes in queue

    }

    return score;

}

void show(int y){
    int x = 0;
    ST7735_WriteString(x, y,"A:Record",Font_7x10,ST7735_BLACK,ST7735_GREEN);
    ST7735_WriteString(x,y+10,"B:Play",Font_7x10,ST7735_BLACK,ST7735_GREEN);
    ST7735_WriteString(x,y+20,"C:Free Mode",Font_7x10,ST7735_BLACK,ST7735_GREEN);
    ST7735_WriteString(x,y+30,"D:Load",Font_7x10,ST7735_BLACK,ST7735_GREEN);
    ST7735_WriteString(x,y+40,"#:Quit",Font_7x10,ST7735_BLACK,ST7735_GREEN);

}


void game_mode_test(){
    ST7735_Init();
    init_gpio();
    uint16_t index[]={0,1,2,3, 1, 2, 2, 3, 1, 0, 0};
    int length=sizeof(index)/sizeof(index[0]);
    int score=display_games(index,length);
    ST7735_FillRectangle(0, 0, width, height, ST7735_BLACK);
    while(true){
        display_score(score);
        char key = get_key_timeout_us(2000 * 1000);
        if(key == '#' || key == '0'){
            break;
        }
        sleep_ms(100);
    }
    ST7735_FillRectangle(0, 0, 80, 160, ST7735_BLACK);
}

//#include "DEV_Config.h"
//#include "st7735_driver.h"
//#include "music_pictures.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include "../utils/sl_utils.h"
//
//const uint16_t width = 80;
//const uint16_t height = 160;
//
//
//const uint16_t block_width = 20;
//const uint16_t block_height = 10;
//const uint16_t block_speed = 10;
//
//const uint16_t bar_x = 0;
//const uint16_t bar_y = 148;
//const uint16_t bar_height = 2;
//const uint16_t bar_width = 80;
//
//
//const uint16_t correct_range_upper = height - 3 * block_height;
//const uint16_t correct_range_bottom = height;
//
//const char index_arr[] ={'1','2','3','A'};
//
//const int prefect_score = 100;
//const int good_score = 50;
//const int bad_score = 0;
//
//void display_score(int score){
//    int x = 80;
//    int y = 80;
//    ST7735_WriteString(x,y,"Score:",Font_7x10,ST7735_BLACK,ST7735_GREEN);
//    char score_str[10];
//    sprintf(score_str,"%d",score);
//    ST7735_WriteString(x+30,y,score_str,Font_7x10,ST7735_BLACK,ST7735_GREEN);
//    ST7735_WriteString(x,y+10,"Press # to quit",Font_7x10,ST7735_BLACK,ST7735_GREEN);
//}
//
//void judge(uint16_t x_idx,uint16_t y_idx, int* flag) {
//    if(*flag == 2 || *flag == 3) return;
//
//    char key = get_key_timeout_us(250 * 1000);
//    if(key == 'm'){
//        *flag = 0;
//        return;
//    }
//    // Check the index of x-axis is correct or not
//    if (index_arr[x_idx] != key) {
//        *flag = 2;
//        return;
//    } else {
//        // if y is correct
//        int absolute_height = y_idx * block_height;
//        if (absolute_height == correct_range_upper) {
//            *flag = 1;
//            return;
//        }else if(absolute_height > correct_range_upper && absolute_height <= correct_range_bottom){
//            *flag = 2;
//            return;
//        }
//        else{
//            *flag = 3;
//            return;
//        }
//    }
//}
///*
// * Game display, according to the notes queue.
// */
//int display_games(uint16_t *note_queue, int length) {
//
//    int index = 0;
//    int max_step_height = 160 / block_speed;
//    int score = 0;
//
//    while(index < length) {
//        sleep_ms(100);
//        // Draw a rectangular with left upper bound at (x,y), and a width of 1/4 of the width of the screen,
//        // 1/16 of the height of the screen
//        int count = 0;
//        int x_position_index = note_queue[index];
//        while(count < max_step_height) {
//            ST7735_FillRectangle(0, 0, 80, 160, 0xff);
//            ST7735_FillRectangle(bar_x, bar_y,bar_width,bar_height,0x00);
//
//            int *flag; // 0: exist; 1: prefect click; 2: good click 3: missed;
//            *flag = 0;
//
//            // bottom-left position (index) of brick
//            judge(x_position_index, count, flag);
//
//            // Move the rectangular down each iteration, each time move down 1/8 of the height of the screen.
//            if(*flag == 0){
//                ST7735_FillRectangle(block_width * x_position_index, block_speed*count,block_width,block_height, 0x00);
//            }else if(*flag == 1){
//                ST7735_FillRectangle(block_width * x_position_index, block_speed*count,block_width,block_height, 0x0f);
//                score = score + prefect_score;
//            }else if(*flag == 2){
//                score = score + good_score;
//            }else if(*flag == 3){
//                score = score + bad_score;
//            }
//            count++;
//        }
//        index++;
//
//        // After moving the rectangular down to the bottom of the screen, continue generating new rectangular
//        // with respect to the new notes in queue
//
//    }
//
//    return score;
//
//}
//
//void show(int y){
//    int x = 0;
//    ST7735_WriteString(x,y,"A:Record",Font_7x10,ST7735_BLACK,ST7735_GREEN);
//    ST7735_WriteString(x,y+10,"B:Play",Font_7x10,ST7735_BLACK,ST7735_GREEN);
//    ST7735_WriteString(x,y+20,"C:Free Mode",Font_7x10,ST7735_BLACK,ST7735_GREEN);
//    ST7735_WriteString(x,y+30,"D:Load",Font_7x10,ST7735_BLACK,ST7735_GREEN);
//    ST7735_WriteString(x,y+40,"#:Quit",Font_7x10,ST7735_BLACK,ST7735_GREEN);
//
//}
//
//
///*
// * TODO:
// * Finish the scoring rules
// * test the judgement function
// */
//
//
//int main(){
//    ST7735_Init();
////    int i = 0;
////    while(true){
////    if(i==22){
////        i=0;
////    }
////    ST7735_DrawImage(0, 0, 80, 160, dou[i]);
////    i++;
////    sleep_ms(100);
////    }
//    uint16_t index[]={0,1,2,3};
//    int length=sizeof(index)/sizeof(index[0]);
//    int score=display_games(index,length);
//    ST7735_FillRectangle(0, 0, 80, 160, ST7735_BLACK);
//    while(true){
//        display_score(score);
//        char key = get_key_timeout_us(250 * 1000);
//        if(key == '#'){
//            break;
//        }
//    }
//    ST7735_FillRectangle(0, 0, 80, 160, ST7735_BLACK);
//}

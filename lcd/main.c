#include "DEV_Config.h"
#include "st7735_driver.h"
#include "music_pictures.h"
#include <stdio.h>
#include <stdlib.h>

const uint16_t width = 80;
const uint16_t height = 160;


const uint16_t block_width = 20;
const uint16_t block_height = 10;

//enum brickPos_x = {
//    ZERO = 0,
//    FIRST = 20,
//    SECOND = 40,
//    THIRD = 60,
//}

/*
 * Game display, according to the notes queue.
 */
void display_games(uint16_t *note_queue, int length) {

    int index = 0;
    int max_step_height = 160 / 10;

    while(index < length) {
        sleep_ms(100);
        // Draw a rectangular with left upper bound at (x,y), and a width of 1/4 of the width of the screen,
        // 1/16 of the height of the screen
        int count =0;
        int x_position_index = note_queue[index];
        while(count < max_step_height) {
            ST7735_FillRectangle(0, 0, 80, 160, 0xff);
            ST7735_FillRectangle(0, 148,80,2,0x00);
            // Move the rectangular down each iteration, each time move down 1/8 of the height of the screen.
            ST7735_FillRectangle(block_width * x_position_index, block_height*count,block_width,block_height, 0x00);

            //Judge the pressing is on time or not
            count++;
        }
        index++;




        // After moving the rectangular down to the bottom of the screen, continue generating new rectangular
        // with respect to the new notes in queue

    }
    ST7735_FillRectangle(0, 0, 80, 160, 0xff);


    return;

}

int main(){
    ST7735_Init();
//    int i = 0;
//    while(true){
//    if(i==22){
//        i=0;
//    }
//    ST7735_DrawImage(0, 0, 80, 160, dou[i]);
//    i++;
//    sleep_ms(100);
//    }
    uint16_t index[]={0,1,2,3};
    int length=sizeof(index)/sizeof(index[0]);
    display_games(index,length);
}

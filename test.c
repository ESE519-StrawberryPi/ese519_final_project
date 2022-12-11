//////
////// Created by Haoze Wu on 12/10/22.
////
//
//#include "utils/play.h"
//#include "utils/audio_generator.h"
//#include "zrx_543_driver/zrx543_driver.h"
//#include "st7735_driver/st7735_driver.h"
//#include "utils/sl_utils.h"
//#include "game_mode.h"
//
//
//#include "resources/audio.h"
//
//
//int main(){
//    stdio_init_all();
//    ST7735_Init();
////    init_gpio();
//    sleep_ms(10000);
//    printf("\nWelcome To Games!\n");
//    ST7735_FillRectangle(0, 0, 80, 160, ST7735_BLACK);
//    while(true){
//        display_score(500);
//        char key = get_key_timeout_us(2000 * 1000);
//        if(key == '#'){
//            break;
//        }
//        sleep_ms(100);
//    }
//    ST7735_FillRectangle(0, 0, 80, 160, ST7735_BLACK);
//
//
//}
////
//// Created by Haoze Wu on 12/14/22.
////
//
//#include "utils/play.h"
//#include "utils/audio_generator.h"
//#include "utils/sl_utils.h"
//#include "utils/game_mode.h"
//#include "zrx_543_driver/zrx543_driver.h"
//
//#include "resources/audio.h"
//
//void debug_mode(){
//    stdio_init_all();
//    sleep_ms(5000);
//
//    // Set up PIO
//    PIO pio = pio0;
//    uint sm = 0;
//    uint offset = pio_add_program(pio, &pwm_program);
//    pwm_program_init(pio, sm, offset,AUDIO_PIN);
//
//    uint32_t period = 64934;
//
//    // Fine-tuning the clock so that the frequency of the music is normal
//    uint32_t clk = 125000;
//    set_sys_clock_khz(clk, true);
//    play_a_note(pio, sm, period, '1');
//}
//
//int main(){
//    debug_mode();
//}
//

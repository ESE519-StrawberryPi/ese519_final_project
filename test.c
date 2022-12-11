////
//// Created by Haoze Wu on 12/10/22.
////
//
//#include "utils/play.h"
//#include "utils/audio_generator.h"
//#include "zrx_543_driver/zrx543_driver.h"
//
//
//#include "resources/audio.h"
//
//static int get_key_until(absolute_time_t until) {
//    char current='m';
//    do {
//        // todo round robin might be nice on each call, but then again hopefully
//        //  no source will starve the others
//        int read = getKey();
//        if(read != 'm'){
//            current=read;
//        }
//        if (read == 'm' && current != 'm') {
//            return current;
//        }
//        if (time_reached(until)) {
//            return current;
//            return PICO_ERROR_TIMEOUT;
//        }
//        // we sleep here in case the in_chars methods acquire mutexes or disable IRQs and
//        // potentially starve out what they are waiting on (have seen this with USB)
//        busy_wait_us(1);
//    } while (true);
//}
//
//int get_key_timeout_us(uint32_t timeout_us) {
////    char buf[1];
//    return get_key_until(make_timeout_time_us(timeout_us));
////    if (rc < 0) return rc;
////    assert(rc);
////    return rc;
////    return rc;
//}
//
//int main(){
////    init_gpio();
////    uint gpio=0;
//    stdio_init_all();
//    sleep_ms(10000);
//    init_gpio();
//    while(true){
//        char c = get_key_timeout_us(4*1000*1000);
//        printf("%c",c);
//    }
//
//}
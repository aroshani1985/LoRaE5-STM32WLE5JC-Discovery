#ifndef __LEDAPP_H
#define __LEDAPP_H
//////////////////////////////////
#ifdef __cplusplus
 extern "C" {
#endif 
/////////////////////////////////////////////
#include "gpio.h"
////////////////////////////
#define LED_G_PERIOD_MS                    1000  
///////////////////////////////   
void app_led_init();
void app_led_deinit();
void app_led_exe();
///////////////////////////////////////////////
#ifdef __cplusplus
}
#endif

#endif /* __LEDAPP_H */
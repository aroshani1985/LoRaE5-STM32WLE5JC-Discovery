#include "ledapp.h"
#include "gpio.h"
#include "usart.h"
///////////////////////////
#include "utilities_def.h"
#include "stm32_seq.h"
#include "stm32_timer.h"
#include "timer_if.h"
////////////////////////////////////
static UTIL_TIMER_Object_t timerLed_G;
////////////////////////////////////////
static void On_LED_G_Event(void *context)
{
   UTIL_SEQ_SetTask((1 << CFG_SEQ_Task_LED_Blink), CFG_SEQ_Prio_0);
}
////////////////////////////////////////
void app_led_init()
{
  UTIL_SEQ_RegTask((1 << CFG_SEQ_Task_LED_Blink), UTIL_SEQ_RFU, app_led_exe);
  ////////////////////////////////////////////////////////////////////////////
  UTIL_SEQ_SetTask((1 << CFG_SEQ_Task_LED_Blink), CFG_SEQ_Prio_0);
  ///////////////////////////////////////////////////////////////////
  UTIL_TIMER_Create(&timerLed_G, LED_G_PERIOD_MS, UTIL_TIMER_PERIODIC, On_LED_G_Event, NULL);
  UTIL_TIMER_Start(&timerLed_G);
  /////////////////////////////////////////////
  u1_print_str_rtc(">app led init.\n");
  ///////////////////////////////////////////////
}
//////////////////////
void app_led_deinit()
{
  u1_print_str_rtc(">app led deinit.\n");
}
///////////////////////////////////////////////////////////
void app_led_exe()
{
  led_g_ctrl(2);
  
  //i2c2_read_dev(ADXL345_ALT_ADD_LIB, 0, 1);
  //i2c2_read_dev(LM75_ADD_LIB, 0, 2);
  //u1_print_str_u32_rtc("Data: ", i2c_rec_buff[0], 1);
  //print_dt();
  //u1_print_str_rtc(">app led running.\n");
}




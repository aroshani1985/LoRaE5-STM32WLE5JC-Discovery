#include "app.h"
#include "os.h"
///////////////////
#include "ledapp.h"
#include "winapp.h"
////////////////////
void app_register()
{
  os_task_register(APP_LED_ID, app_led_init , app_led_exe, app_led_deinit);
  //os_task_register(APP_WAPP_ID, app_winapp_init , app_winapp_exe, app_winapp_deinit);
  ///////////////////////////////////////////////////////////////////////////////////
  //os_task_start(APP_WAPP_ID);
  os_task_start(APP_LED_ID);
  //os_task_event_cfg(APP_LWAN_ID, TEV_2, true); 
}

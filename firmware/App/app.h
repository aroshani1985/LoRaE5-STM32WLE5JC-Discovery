#ifndef __APP_H
#define __APP_H
///////////////////////////
#ifdef __cplusplus
 extern "C" {
#endif 
//////////////////////////////////////

/////////////////////////////////
#define  APP_LED_ID            0
#define  APP_WAPP_ID           1
#define  APP_LWAN_ID           2
#define  APP_MNG_ID            3
//////////////////////////////////////
#define  APP_NONE_ID           0xFF
///////////////////////////////////
void app_register();
/////////////////////
#ifdef __cplusplus
}
#endif

#endif /* __APP_H */
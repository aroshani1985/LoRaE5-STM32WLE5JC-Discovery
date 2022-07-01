#ifndef __LRAPP_H
#define __LRAPP_H
//////////////////////////////////
#ifdef __cplusplus
 extern "C" {
#endif 
/////////////////////////////////////////////
#define RX_TIMEOUT_VALUE              3000
#define TX_TIMEOUT_VALUE              3000

#define MAX_APP_BUFFER_SIZE          255
///////////////////////////////   
void app_lora_tx_init();
void app_lora_tx_enable();
void app_lora_tx_exe();
void app_lora_rx_init();
void app_lora_rx_enable();
void app_lora_rx_exe();
///////////////////////////////////////////////
#ifdef __cplusplus
}
#endif

#endif /* __LRAPP_H */
#include "lrapp.h"
#include "usart.h"
///////////////////////////
#include "stm32_timer.h"
#include "timer_if.h"
#include "stm32_seq.h"
#include "utilities_def.h"
#include "subghz_phy_app.h"
#include "radio.h"
/////////////////////////////////////////
static uint8_t BufferRx[MAX_APP_BUFFER_SIZE];
static uint8_t BufferTx[MAX_APP_BUFFER_SIZE];
////////////////////////////////////
void app_lora_tx_init()
{
  //SubghzApp_Init();
  Radio.SetPublicNetwork(true);
  UTIL_SEQ_RegTask((1 << CFG_SEQ_Task_LoRa_TX), UTIL_SEQ_RFU, app_lora_tx_exe);
}
void app_lora_tx_enable()
{
  UTIL_SEQ_SetTask((1 << CFG_SEQ_Task_LoRa_TX), CFG_SEQ_Prio_0);
}
void app_lora_tx_exe()
{
  u1_print_str_rtc("Satrt To Send Data ...\n");
  /* Radio Set frequency */
  Radio.SetChannel(RF_FREQUENCY);
  Radio.SetTxConfig(MODEM_LORA,
                    TX_OUTPUT_POWER, 
                    0,
                    LORA_BANDWIDTH,
                    LORA_SPREADING_FACTOR,
                    LORA_CODINGRATE,
                    LORA_PREAMBLE_LENGTH,
                    LORA_FIX_LENGTH_PAYLOAD_ON,
                    0, //crc
                    0,
                    0,
                    false, //LORA_IQ_INVERSION_ON
                    TX_TIMEOUT_VALUE);
  Radio.SetMaxPayloadLength(MODEM_LORA, MAX_APP_BUFFER_SIZE);
  memset(BufferTx, 0x0, MAX_APP_BUFFER_SIZE);
  memcpy(BufferTx, "Lora-IOT", 8);
  Radio.Send(BufferTx, PAYLOAD_LEN);
}

//////////////////////////////////////////////////////////////
void app_lora_rx_init()
{
  //SubghzApp_Init();
   UTIL_SEQ_RegTask((1 << CFG_SEQ_Task_LoRa_RX), UTIL_SEQ_RFU, app_lora_rx_exe);
}
void app_lora_rx_enable()
{
  UTIL_SEQ_SetTask((1 << CFG_SEQ_Task_LoRa_RX), CFG_SEQ_Prio_0);
}
void app_lora_rx_exe()
{
  u1_print_str_rtc("Satrt To Receive:\n");
  /* Radio Set frequency */
  Radio.SetChannel(RF_FREQUENCY);
  Radio.SetRxConfig(MODEM_LORA,
                    LORA_BANDWIDTH,
                    LORA_SPREADING_FACTOR,
                    LORA_CODINGRATE,
                    0,
                    LORA_PREAMBLE_LENGTH,
                    LORA_SYMBOL_TIMEOUT,
                    LORA_FIX_LENGTH_PAYLOAD_ON,
                    0,
                    true,
                    0,
                    0, 
                    LORA_IQ_INVERSION_ON,
                    true);

  Radio.SetMaxPayloadLength(MODEM_LORA, MAX_APP_BUFFER_SIZE); 
  memset(BufferRx, 0x0, MAX_APP_BUFFER_SIZE);
  Radio.Rx(0); //
}

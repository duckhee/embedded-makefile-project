#ifndef __ESP_8266_TCP_H__
#define __ESP_8266_TCP_H__

#include "esp8266.h"

/** Connection Mult or single TypeDef */
typedef enum _AT_MUX{
    SINGLE = 0,
    MULT = 1
} AT_MUXTypeDef;

typedef enum _AT_Transmit{
    NORMAL = 0,
    UART_WIFI = 1,

}AT_Transmit_TypeDef;

#ifdef ESP_TCP_LOCAL
#define ESP_TCP_DEF             extern
#else
#define ESP_TCP_DEF
#endif

ESP_TCP_DEF bool TCP_Stat(void);
ESP_TCP_DEF bool SetMultCon(AT_MUXTypeDef mult);
ESP_TCP_DEF bool TCP_Start();
ESP_TCP_DEF bool TCP_SendData();
ESP_TCP_DEF bool TCP_Close();
ESP_TCP_DEF bool SetTransmitMode(AT_Transmit_TypeDef mode);
/** AP Mode Function */
ESP_TCP_DEF bool CreateServer(bool Flag);
ESP_TCP_DEF bool SetTimeOut(uint8_t time);
ESP_TCP_DEF bool GetTimeOut(void);
/** Test Function  */
ESP_TCP_DEF bool PingTest(uint8_t *url);
#endif
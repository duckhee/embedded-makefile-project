#ifndef __ESP_8266_H__
#define __ESP_8266_H__

#include "esp_conf.h"
#include "string.h"
#include "stdint.h"
/** define Command State */
#define ESP_OK              "OK"
#define ESP_ERROR           "ERROR"
#define ESP_READY           "ready"
#define ESP_WIFI_DISCON     "WIFI DISCONNECT"
#define ESP_WIFI_CON        "WIFI CONNECTED"
#define ESP_SENDING         "busy s... "
#define ESP_PROSESSING      "busy p..."
#define RECEIVE_DATA        "+IPD"

///////////////////////////////
// Command Response Timeouts //
///////////////////////////////
#define COMMAND_RESPONSE_TIMEOUT    1000
#define COMMAND_PING_TIMEOUT        3000
#define WIFI_CONNECT_TIMEOUT        30000
#define COMMAND_RESET_TIMEOUT       5000
#define CLIENT_CONNECT_TIMEOUT      5000
#define AP_SEARCH_TIMEOUT           10000
/**  ESP BUFFER Size */
#define ESPBUF_MAXSIZE       1000

/** AT CWMODE enum TypeDef */
typedef enum _AT_CWMODE{
    STATION = 1,
    AP = 2,
    AP_STATION = 3
}AT_CWMODE;


/** Encryption Enum TypeDef */
typedef enum _AT_Encryption{
    OPEN = 0,
    WPA_PSK = 2,
    WPA2_PSK = 3,
    WPA_WPA2_PSK = 4
} AT_Encryption;
typedef struct _AP_Init{
    uint8_t *ssid;
    uint8_t *pw;
    uint8_t ch; //default use 5
    AT_Encryption mode;
}AP_InitTypeDef;

typedef struct _AP_Network{
    uint8_t *ip;
    uint8_t *gateway;
    uint8_t *netmask;
} AP_NetworkInitTypeDef;

/** bool Type */
typedef enum _bool {
    FALSE = 0,
    TRUE = 1
} bool;

typedef enum _smartConfig{
    ESP_TOUCH = 1,
    AIRKISS = 2,
    ESP_TOUCH_AIRKISS = 3
} SmartConfigTypeDef;

// TODO 
/** Using Hal CMSIS */
#ifdef USE_STDPERIPH_DRIVER
typedef struct _ESP_Init{
    USART_TypeDef *uart;
    uint32_t UART_TxPin;
    uint32_t UART_RxPin;
    void (*UART_Config)();
    void (* ESP_Transmit)(USART_TypeDef *uart, data);
    uint16_t (* ESP_Receive)(USART_TypeDef *uart);
}ESP_InitTypeDef;
/** Using Hal Driver */
#elif USE_HAL_DRIVER
typedef struct _ESP_Init{
    UART_HandleTypeDef *uart;
    uint32_t UART_TxPin;
    uint32_t UART_RxPin;
    void (*UART_Config)();
    int (*HAL_UART_Transmit)(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
    int (*HAL_UART_Receive)(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
    
}ESP_InitTypeDef;
#endif


#ifdef ESP_LOCAL
#define ESP_DEF         extern
#else
#define ESP_DEF
#endif

/** ESP8266 AT Command Control function */
ESP_DEF void ESP_Init(ESP_InitTypeDef *eps_InitStruct);
ESP_DEF bool ESP_SendCommandResponse(uint8_t *Command, const char *msg, unsigned int TimeOut);
ESP_DEF uint8_t *ESP_GetData(void);
ESP_DEF bool ESP_Reset(void);
ESP_DEF bool ESP_FactoryReset(void);
ESP_DEF bool ESP_SetAutoCon(bool flag);
/** mode setting */
ESP_DEF bool AT_SetCWMode(AT_CWMODE mode);
ESP_DEF uint8_t *AT_GetCWMode(void);


/** Smart Config */
ESP_DEF bool StartSmartConfig(SmartConfigTypeDef mode);
ESP_DEF bool StopSmartConfig(void);

/**
 * Station Mode is connect AP
 * AP Mode is bridge Mode
 */

/** Station Mode Function */
ESP_DEF bool GetWiFiList(void);
ESP_DEF bool GetApList(void);
/** return Wifi AP Number */
ESP_DEF uint8_t WiFiList(uint8_t *AP_List, uint8_t *NameTemp[]);
ESP_DEF uint8_t ApInfoList(uint8_t *AP_List, uint8_t *NameTemp[]);
ESP_DEF uint8_t ApSearchList(uint8_t max, uint8_t *NameTemp[]);
ESP_DEF bool APConnect(uint8_t *ssid, uint8_t *password);
ESP_DEF bool APDisConnect(void);
/** AP Mode Function */
ESP_DEF bool SetAP(AP_InitTypeDef *APx);
ESP_DEF bool SetAPNetwork(AP_NetworkInitTypeDef *AP_Netx);
/** Test Function */
ESP_DEF bool AT_Test();
ESP_DEF bool AT_Version(void);


#endif
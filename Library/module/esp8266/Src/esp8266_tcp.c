#define ESP_TCP_LOCAL

#include "esp8266_tcp.h"

ESP_TCP_DEF bool TCP_Stat(void){
    if(ESP_SendCommandResponse("AT+CIPSTATUS\r\n", ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_TCP_DEF bool SetMultCon(AT_MUXTypeDef mult){

}

ESP_TCP_DEF bool SetTransmitMode(AT_Transmit_TypeDef mode){
    uint8_t temp[40];
    memset(temp, '\0', sizeof(temp));
    sprintf(temp, "AT+CIPMODE=%d\r\n", mode);
    if(ESP_SendCommandResponse(temp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

/** need to multi connection */
ESP_TCP_DEF bool CreateServer(bool Flag, uint8_t port){
    uint8_t temp[50];
    memset(temp, '\0', sizeof(temp));
    if(port > 0){
        sprintf(temp, "AT+CIPSERVER=%d,%d\r\n", Flag, port);
    }else{
        sprintf(temp, "AT+CIPSERVER=%d\r\n",Flag);
    }
    if(ESP_SendCommandResponse(temp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_TCP_DEF bool SetTimeOut(uint8_t time){
    uint8_t temp[40];
    memset(temp, '\0', sizeof(temp));
    sprintf(temp, "AT+CIPSTO=%d\r\n", time);
    if(ESP_SendCommandResponse(temp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_TCP_DEF bool GetTimeOut(void){
    if(ESP_SendCommandResponse("AT+CIPSTO?\r\n", ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_TCP_DEF bool PingTest(uint8_t *url){
    uint8_t temp[40];
    bzero(temp, sizeof(temp));
    sprintf(temp, "AT+PING=\"%s\"\r\n", url);
    if(ESP_SendCommandResponse(temp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}
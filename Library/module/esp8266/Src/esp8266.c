#include "esp8266.h"




uint8_t ESP_Buf[ESPBUF_MAXSIZE];
uint32_t ESP_HeadPoint;
uint32_t ESP_TailPoint;

/** ESP Struct */
ESP_InitTypeDef _Init;

/** Buffer function */
bool IsEmpty();
void BufferClean();
void IncreatePointer(uint32_t *pointer);
void EnQueue(uint8_t data);
uint8_t DeQueue();

/** esp low function */
bool ESP_ResponseAvabile();
bool ESP_ReadForResponse(const char *msg, unsigned int nTime);
bool ESP_GetState(const char *msg);

/** ESP Function */
ESP_DEF void ESP_Init(ESP_InitTypeDef *eps_InitStruct);
ESP_DEF void ESP_SendCommand(uint8_t *Command);
ESP_DEF bool ESP_SendCommandResponse(uint8_t *Command, const char *msg, unsigned int TimeOut);
ESP_DEF bool ESP_Reset();
ESP_DEF bool ESP_FactoryReset();
ESP_DEF uint8_t *ESP_GetData();

/** Test Function */
ESP_DEF bool AT_Test();

/** ESP Init Function */
ESP_DEF void ESP_Init(ESP_InitTypeDef *esp_InitStruct){
    _Init = &esp_InitStruct;
    BufferClean();
}


ESP_DEF void ESP_SendCommand(uint8_t *Command){

#ifdef USE_STDPERIPH_DRIVER
    _Init->CMSIS_Transmit(_Init->uart, Command);
#elif USE_HAL_DRIVER
    _Init->HAL_UART_Transmit(_Init->uart, Command, sizeof(Command)/sizeof(char), 1000);
#endif

}

ESP_DEF bool ESP_SendCommandResponse(uint8_t *Command, const char *msg, unsigned int TimeOut){
    ESP_SendCommand(Command);
    if(ESP_ReadForResponse(msg, TimeOut)){
        return TRUE;
    }else{
        return FALSE;
    }
}

/** Reset ESP */
ESP_DEF bool ESP_Reset(){
    if(ESP_SendCommandResponse("AT+RST\r\n", ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

/** Factory RESET ESP */
ESP_DEF bool ESP_FactoryReset(){
    if(ESP_SendCommandResponse("AT+RESTORE\r\n", ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF bool ESP_SetAutoCon(bool flag){
    uint8_t temp[40];
    memset(temp, '\0', strlen(temp));
    sprintf(temp, "AT+CWAUTOCONN=%d\r\n", flag);
    if(ESP_SendCommaandResponse(temp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF uint8_t *ESP_GetData(){
    return ESP_Buf;
}

ESP_DEF bool AT_SetCWMode(AT_CWMODE mode){
    uint8_t *CommandTemp;
    sprintf(CommandTemp, "AT+CWMODE=%d\r\n", mode);
    if(ESP_SendCommandResponse(CommandTemp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}
ESP_DEF uint8_t *AT_GetCWMode(void){
    if(ESP_SendCommandResponse("AT+CWMODE?\r\n", ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return ESP_Buf;
    }else{
        return NULL;
    }
}


ESP_DEF bool SetSmartConfig(SmartConfigTypeDef mode){
    uint8_t temp[40];
    memset(temp, '\0', strlen(40));
    sprintf(temp, "AT+CWSTARTSMART=%d\r\n", mode);
    if(ESP_SendCommaandResponse(temp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF bool StopSmartConfig(){
    if(ESP_SendCommaandResponse("AT+CWSTOPSMART\r\n", ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF bool APConnect(uint8_t *ssid, uint8_t *password){
    uint8_t temp[40];
    memset(temp, '\0', strlen(temp));
    if(password == NULL){
        sprintf("AT+CWJAP=\"%s\",\"\"\r\n", ssid);
    }else{
        sprintf("AT+CWJAP=\"%s\",\"%s\"\r\n", ssid, password);
    }
    if(ESP_SendCommaandResponse(temp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF bool APDisConnect(void){
    if(ESP_SendCommaandResponse("AT+CWQAP\r\n", ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF bool GetWiFiList(void){
    if(ESP_SendCommandResponse("AT+CWLAP\r\n", ESP_OK, AP_SEARCH_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF bool GetApList(void){
    if(ESP_SendCommandResponse("AT+CWLAP\r\n", ESP_OK, AP_SEARCH_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF uint8_t WiFiList(uint8_t *AP_List, uint8_t *NameTemp[]){
    uint8_t idx = 0;
    uint8_t *ptr = strtok(AP_List, "()");
    while(ptr != NULL){
        if(strlen(ptr) > 50){
            NameTemp[idx] = ptr;
            idx++;
        }
        ptr = strtok(NULL, "()");
    }
    return (idx-1);
}

ESP_DEF uint8_t ApInfoList(uint8_t *AP_List, uint8_t *NameTemp[]){
    uint8_t idx = 0;
    uint8_t *ptr = strtok(AP_List, "()");
    while(ptr != NULL){
        if(strlen(ptr) > 50){
            NameTemp[idx] = ptr;
            idx++;
        }
        ptr = strtok(NULL, "()");
    }
    /** no AP Search */
    return (idx - 1);
}

ESP_DEF uint8_t ApSearchList(uint8_t max, uint8_t *NameTemp[]){
    if(GetApList()){
        uint8_t *rows = ESP_GetData();
        uint8_t idx = 0;
        uint8_t *ptr = strtok(rows, "()");
        while(ptr != NULL){
            if(strlen(ptr) > 50){
                NameTemp[idx] = ptr;
                idx++;
                if(idx == max){
                    break;
                }
            }
            ptr = strtok(NULL, "()");
        }
        return (idx - 1);
    }else{
        return FALSE;
    }
}

/** Ap Mode Function */
ESP_DEF bool SetAP(AP_InitTypeDef *APx){
    uint8_t temp[40];
    memset(temp, '\0', strlen(temp));
    if(APx->mode == OPEN){
        sprintf(temp, "AT+CWSAP=\"%s\",%d,%d\r\n", APx->ssid, APx->pw, APx->ch, APx->mode);
    }else{
        sprintf(temp, "AT+CWSAP=\"%s\",\"%s\",%d,%d\r\n", APx->ssid, APx->pw, APx->ch, APx->mode);
    }
    
    if(ESP_SendCommaandResponse(temp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF bool SetAPNetwork(AP_NetworkInitTypeDef *AP_Netx){
    uint8_t temp[50];
    memset(temp, '\0', 50);
    sprintf(temp, "AT+CIPAP=\"%s\",\"%s\",\"%s\"\r\n", AP_Netx.ip, AP_Netx->gateway, AP_Netx->netmask);
    if(ESP_SendCommaandResponse(temp, ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

/** Test Function */
ESP_DEF bool AT_Test(){
    if(ESP_SendCommandResponse("AT\r\n", ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

ESP_DEF bool AT_Version(void){
    if(ESP_SendCommandResponse("AT+GMR\r\n", ESP_OK, COMMAND_RESPONSE_TIMEOUT)){
        return TRUE;
    }else{
        return FALSE;
    }
}

bool ESP_ResponseAvabile(){
    return (ESP_HeadPoint > 0) ? TRUE : FALSE;
}

bool ESP_ReadForResponse(const char *msg, unsigned int nTime){
    BufferClean();
#ifdef USE_STDPERIPH_DRIVER
    Delay(nTime);
#elif USE_HAL_DRIVER
    HAL_Delay(nTime);
#endif
    if(ESP_ResponseAvabile()){
        if(ESP_GetState(msg)){
            return TRUE;
        }
    }
    return FALSE;
}

bool ESP_GetState(const char *msg){
    size_t bufferLen = strlen((const char *)ESP_Buf);
    if(bufferLen < ESPBUF_MAXSIZE){
        if(strstr((const char *)ESP_Buf, msg)){
            return TRUE;
        }
    }
    return FALSE;
}

/** Buffer Function */
bool IsEmpty(){
    if(ESP_HeadPoint == ESP_TailPoint){
        return TRUE;
    }else{
        return FALSE;
    }
}

void IncreatePointer(uint32_t *pointer){
    (*pointer)++;
    if(ESPBUF_MAXSIZE == (* pointer)){
        (* pointer) = 0;
    }
}

void EnQueue(uint8_t data){
    ESP_Buf[ESP_HeadPoint] = data;
    IncreatePointer(&ESP_HeadPoint);
}

uint8_t DeQueue(){
    uint8_t data;
    data = ESP_Buf[ESP_TailPoint];
    IncreatePointer(&ESP_TailPoint);
    return data;
}

void BufferClean(){
    ESP_TailPoint = ESP_HeadPoint = 0;
    memset(ESP_Buf, '\0', ESPBUF_MAXSIZE);
}
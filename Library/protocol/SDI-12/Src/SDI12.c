#include "SDI12.h"
#include <string.h>

uint8_t *CommandArray[500] = {"?I!", "I!", "A", "M!", "D", "R0!"};

/** Receive Buffer variable */
uint8_t rxBuffer[SDI_MAX];

/** Buffer Pointer */
uint32_t rx_Head = 0;
uint32_t rx_Tail = 0;

/** Empty Check Buffer */
bool SDI12_Empty(){
    if(rx_Head == rx_Tail){
        return TRUE;
    }else{
        return FALSE;
    }
}

/** Clear Buffer Pointer */
void SDI12_Clean(){
    bzero(rxBuffer, SDI_MAX);
    rx_Head = rx_Tail = 0;
}

/** Increment Buffer Pointer */
void SDI12_IncreasePointer(uint32_t *pData){
    (* pData)++;
    if(SDI_MAX == (* pData)){
        (* pData) = 0;
    }
}

/** Save value in Buffer */
void SDI12_EnQue(uint8_t data){
    rxBuffer[rx_Head] = data;
    SDI12_IncreasePointer(rx_Head);
}

/** Get value in Buffer */
uint8_t SDI12_DeQue(){
    uint8_t retVal = rxBuffer[rx_Tail];
    SDI12_IncreasePointer(rx_Tail);
    return retVal;
}


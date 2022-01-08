#include "hw_config.h"
#include "stm32f10x.h"
#include <stdlib.h>
#include "errno.h"
#include <sys/stat.h>
#include <sys/types.h>

__attribute__((used))
int _getpid(void){
    return 1;
}

__attribute__((used))
int _write(int fd, char *ptr, int len){
    size_t i;
    for(i = 0; i < len; i++){
        USART_SendData(USART1, ptr[i]);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    }
    return len;
}

__attribute__((used))
int _close(int file){
    return -1;
}
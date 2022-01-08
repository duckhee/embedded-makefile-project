#include "hw_config.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/times.h>

extern int errno;

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
int _kill(int pid, int sig){
    errno = EINVAL;
    return -1;
}

__attribute__((used))
void _exit(int status){
    _kill(status, 1);
    while(1){
        ;
    }
}

__attribute__((used))
int _fstat(int file, struct stat *st){
    st->st_mode = S_IFCHR;
    return 0;
}

__attribute__((used))
int _isatty(int file){
    return 1;
}

__attribute__((used))
int _lseek(int file, int ptr, int dir){
    return 0;
}

__attribute__((used))
int _open(char *path, int flags, ...){
    return -1;
}

__attribute__((used))
int _times(struct tms *buf){
    return -1;
}

__attribute__((used))
int _wait(int *status){
    errno = ECHILD;
    return -1;
}

__attribute__((used))
int _unlink(char *name){
    errno = ENOENT;
    return -1;
}

__attribute__((used))
int _stat(char *file, struct stat *st){
    st->st_mode = S_IFCHR;
    return -1;
}

__attribute__((used))
int _link(char *old, char *new){
    errno = EMLINK;
    return -1;
}

__attribute__((used))
int _execve(char *name, char **argc, char **env){
    errno = ENOMEM;
    return -1;
}

__attribute__((used))
int _close(int file){
    return -1;
}
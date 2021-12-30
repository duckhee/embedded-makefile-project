#define MENU_LOCAL

#include "stdio.h"
#include "menu.h"
#include "string.h"

/** MAX ARGS */
#define MAX_ARGS            20

MENU_DEF void Main_Menu();

void display_prompt(char *prompt);
int get_args(char *s, char **argv);


void display_prompt(char *prompt){
    if(prompt == NULL){
        printf(">>>");
    }else{
        printf("%s", prompt);
    }
}

/** Get ARGV */
int get_args(char *s, char **argv){
    int args = 0;
    if (!s || *s == '\0')
    {
        return 0;
    }
    while (args < MAX_ARGS){
        while ((*s ==' ') || (*s == '\t')){
            s++;
        }

        if (*s == '\0'){
            argv[args] = 0;
            return args;
        }
        argv[args++]=s;
        while (*s && (*s != ' ') && (*s  != '\t')){
            s++;
        }
        if (*s == '\0'){
            argv[args]=0;
            return args;
        }
        *s++='\0';
    }
    return args;
}
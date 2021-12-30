#ifndef __MENU_H__
#define __MENU_H__




#ifdef MENU_LOCAL
#define MENU_DEF    extern
#else
#define MENU_DEF
#endif

MENU_DEF void Main_Menu();

#endif
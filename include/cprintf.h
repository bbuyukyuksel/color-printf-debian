#ifndef CPRINTF_H
#define CPRINTF_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>



enum COLORS{RED,LRED,GREEN,LGREEN,YELLOW,LYELLOW,BLUE,LBLUE,MAGENTA,LMAGENTA,CYAN,LCYAN,RESET,START = 0, FINISH = RESET};
extern void setColor(enum COLORS);
extern int cprintf(enum COLORS,const char *fmt, ...);

#endif
#include "cprintf.h"
int cprintf(enum COLORS color,const char *fmt, ...)
{
    setColor(color);
    char buffer[4096];
    va_list args;
    va_start(args, fmt);
    int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    printf("%s",buffer);
    setColor(RESET);
    return rc;
}

void setColor(enum COLORS color){
  int colorCode = 0;
  int lFlag = 0;
  switch(color){
    case RED:{
	colorCode = 31;
    }break;
    case GREEN:{
	colorCode = 32;
    }break;
    case YELLOW:{
	colorCode = 33;
    }break;
    case BLUE:{
	colorCode = 34;
    }break;
    case MAGENTA:{
	colorCode = 35;
    }break;
    case CYAN:{
	colorCode = 36;
    }break;
    
    case LRED:{
	lFlag = 1;	
	colorCode = 31;
    }break;
    case LGREEN:{
	lFlag = 1;
	colorCode = 32;
    }break;
    case LYELLOW:{
	lFlag = 1;
	colorCode = 33;
    }break;
    case LBLUE:{
	lFlag = 1;
	colorCode = 34;
    }break;
    case LMAGENTA:{
	lFlag = 1;
	colorCode = 35;
    }break;
    case LCYAN:{
	lFlag = 1;
	colorCode = 36;
    }break;    
    case RESET:{
	printf("\033[0m");
	return;
    }break;
  }
	printf("\033[%d;%dm",lFlag,colorCode);
}


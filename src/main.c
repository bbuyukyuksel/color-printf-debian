#include "cprintf.h"

int main(){
  setColor(RED);
  printf("Hello World!\n");
  setColor(RESET);

  cprintf(LYELLOW,"Merhaba Dunya!\n");
  
  enum COLORS color = START;
  for(; color < FINISH; color++)
    cprintf(color,"%d",color);
  return 0;

}
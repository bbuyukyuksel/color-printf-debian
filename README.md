# cprintf

## Implementations

make : it will compile main.c which is created test purpose
make compile
make clean

gcc main.c -Llib/ -lcprintf -Iinclude

## Example

-> int x = 5;
-> int y = 10;
-> cprintf(RED,"%d + %d = %d",x,y,x+y);


/*                        */
/* Program Name: wherey.c */
/*                        */
#include <conio.h>
#include <stdio.h>

void main(void)
{
   clrscr();
   gotoxy(20,20);
   printf("Current cursor location (X,Y) is :"
   "(%d,%d)\n",wherex(),wherey());
   getch();
}

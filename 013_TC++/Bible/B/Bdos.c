/*                       */
/* Program Name : bdos.c */
/*                       */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define  CHAR_IN_NO_ECHO       8
#define  CHAR_OUT              2

int my_getche()
{
   char ch;

   /* We won't change the values in DX and AL */
   ch = bdos(CHAR_IN_NO_ECHO, _DX, _AL);
   bdos(CHAR_OUT, ch, _AL);
   return (int) ch;
}

void main()
{
   clrscr();
   printf("Pleas enter a character :");
   printf("\nThe character you entered is : %c\n", my_getche());

   printf("\nPress any key to continue...");
   getch();
}

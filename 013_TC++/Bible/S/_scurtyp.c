
/*                           */
/* Program Name : _scurtyp.c */
/*                           */

#include <conio.h>
#include <stdio.h>

void main(void)
{
   clrscr();
   printf("\nNormal Cursor: ");
   getch();
   _setcursortype(_NOCURSOR);
   printf("\nNo Cursor    : ");
   getch();
   _setcursortype(_SOLIDCURSOR);
   printf("\nSolid Cursor : ");
   getch();
   _setcursortype(_NORMALCURSOR);
   printf("\nNormal Cursor: ");
   getch();
}


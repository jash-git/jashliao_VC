/*                          */
/* Program Name : disable.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void interrupt (*old0x1c)(void);
void interrupt new0x1c()
{
   /* If your Screen Adapter is monochrome card , change
      following address constant to 0xB0000000  */
   char far *scr = (char far *) 0xB8000000;
   static char icon[2] = {'Ü', 'ß'};
   static int  index = 0;
   int curx, cury;

   disable();

   curx = wherex();
   cury = wherey();

   gotoxy(40, 10);
   *(scr) = icon[index];
   index = (index + 1) % 2;
   gotoxy(curx, cury);

   enable();
   old0x1c();
}

void main()
{
   char str[80];

   clrscr();

   old0x1c = getvect(0x1C);
   disable();
   setvect(0x1C, new0x1c);
   enable();

   printf("  <-- This should be moving.\n");
   printf("Please enter a test string:");
   gets(str);

   disable();
   setvect(0x1C, old0x1c);
   enable();

   printf("\nPress any key to continue...");
   getch();
}

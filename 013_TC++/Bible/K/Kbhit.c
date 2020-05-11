/*                        */
/* Program Name : kbhit.c */
/*                        */

#include <conio.h>
#include <dos.h>

void main()
{
   int cx = 40, cy = 13;
   int dx = 1, dy = 1;

   clrscr();
   gotoxy(30, 25);
   cputs("Press any key to stop......");
   while (!kbhit()) {
      gotoxy(cx, cy);
      putch(' ');

      if (cx == 79)
         dx = -1;
      if (cx == 1)
         dx = 1;
      if (cy == 24)
         dy = -1;
      if (cy == 1)
         dy = 1;

      cx += dx; cy += dy;
      gotoxy(cx, cy);
      putch('o');
      delay(100);
   }
}

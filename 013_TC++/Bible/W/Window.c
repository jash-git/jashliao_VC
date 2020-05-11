
/*                        */
/* Program Name: window.c */
/*                        */
#include <conio.h>

void main(void)
{
   int i;
   window(10,10,33,19);
   clrscr();
   textcolor(BLACK);
   textbackground(WHITE);
   for (i=1;i<=9;i++)
      cprintf(" This is a text window \r\n");
   cprintf(" This is a text window ");
   getch();
}

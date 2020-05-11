
/*                          */
/* Program Name: nomvideo.c */
/*                          */
#include <conio.h>

void main(void)
{
   clrscr();
   gotoxy(36,12);
   normvideo();
   cputs("NORMVIDEO");
   gotoxy(36,13);
   highvideo();
   cputs("HIGHVIDEO");
   gotoxy(36,14);
   lowvideo();
   cputs("LOWVIDEO");
   gotoxy(30,25);
   cputs("Press any key to exit");
   getch();
}

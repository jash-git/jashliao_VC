
/*                         */
/* Program Name: movetex.c */
/*                         */
#include <conio.h>

void show_ball_item(void);

char *ball_item[]=
   { "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿",
     "³ Basketball  ³",
     "³ Volleyball  ³",
     "³ Football    ³",
     "³ Tennisball  ³",
     "³ Cricketball ³",
     "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" };

void main(void)
{
   clrscr();
   normvideo();
   show_ball_item();
   gotoxy(23,24);
   cputs("Press any key to copy table of ball");
   getch();
   movetext(1,1,15,7,66,19);
   gotoxy(30,25);
   cputs("Press any key to exit");
   getch();
}

void show_ball_item(void)
{
   int i;
   textbackground(BLACK);
   textcolor(WHITE);
   gotoxy(1,1);
   lowvideo();
   cputs(ball_item[0]);
   for (i=2;i<=6;i++) {
      gotoxy(1,i);
      lowvideo();
      cputs(ball_item[i-1]);
      highvideo();
      gotoxy(3,i);
      cputs(ball_item[i-1]+2);
      gotoxy(4,i);
      lowvideo();
      cputs(ball_item[i-1]+3);
   }
   gotoxy(1,7);
   lowvideo();
   cputs(ball_item[6]);
}

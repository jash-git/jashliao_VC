
/*                         */
/* Program Name: puttext.c */
/*                         */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <dos.h>

#define ESC 27

void show_high_title(void);
void show_norm_title(void);
void show_ball_item(void);

char title[]="Ball";

char *ball_item[]=
   { "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿",
     "³ Basketball  ³",
     "³ Volleyball  ³",
     "³ Football    ³",
     "³ Tennisball  ³",
     "³ Cricketball ³",
     "³ Exit        ³",
     "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" };

void main(void)
{
   char num=0;
   char item,choice;
   char text_buffer[2*8*15];
   clrscr();
   normvideo();
   _setcursortype(_NOCURSOR);
   while (1) {
      show_norm_title();
      item=getch();
      if (item=='B' || item=='b') {
         show_high_title();
         if (num==0)
            show_ball_item();
         else
            puttext(1,2,15,9,text_buffer);
         choice=getch();
         choice=toupper(choice);
         switch(choice) {
            case 'B':
               gotoxy(1,3);
               cputs(ball_item[1]);
               textbackground(7);
               textcolor(BLACK);
               gotoxy(2,3);
               cputs(ball_item[1]+1);
               gotoxy(15,3);
               textbackground(BLACK);
               textcolor(WHITE);
               lowvideo();
               cputs(ball_item[1]+14);
               gotoxy(30,13);
               cputs("Playing basketball game");
               gotoxy(30,14);
               cputs("Press any key to end game");
               getch();
               gettext(1,2,15,9,text_buffer);
               textbackground(BLACK);
               textcolor(WHITE);
               clrscr();
               break;
            case 'V':
               gotoxy(1,4);
               cputs(ball_item[2]);
               textbackground(7);
               textcolor(BLACK);
               gotoxy(2,4);
               cputs(ball_item[2]+1);
               textbackground(BLACK);
               textcolor(WHITE);
               gotoxy(15,4);
               lowvideo();
               cputs(ball_item[2]+14);
               gotoxy(30,13);
               cputs("Playing volleyball game");
               gotoxy(30,14);
               cputs("Press any key to end game");
               getch();
               gettext(1,2,15,9,text_buffer);
               textbackground(BLACK);
               textcolor(WHITE);
               clrscr();
               break;
            case 'F':
               gotoxy(1,5);
               cputs(ball_item[3]);
               textbackground(7);
               textcolor(BLACK);
               gotoxy(2,5);
               cputs(ball_item[3]+1);
               textbackground(BLACK);
               textcolor(WHITE);
               gotoxy(15,5);
               lowvideo();
               cputs(ball_item[3]+14);
               gotoxy(30,13);
               cputs("Playing football game");
               gotoxy(30,14);
               cputs("Press any key to end game");
               getch();
               gettext(1,2,15,9,text_buffer);
               textbackground(BLACK);
               textcolor(WHITE);
               clrscr();
               break;
            case 'T':
               gotoxy(1,6);
               cputs(ball_item[4]);
               textbackground(7);
               textcolor(BLACK);
               gotoxy(2,6);
               cputs(ball_item[4]+1);
               textbackground(BLACK);
               textcolor(WHITE);
               gotoxy(15,6);
               lowvideo();
               cputs(ball_item[4]+14);
               gotoxy(30,13);
               cputs("Playing tennisball game");
               gotoxy(30,14);
               cputs("Press any key to end game");
               getch();
               gettext(1,2,15,9,text_buffer);
               textbackground(BLACK);
               textcolor(WHITE);
               clrscr();
               break;
            case 'C':
               gotoxy(1,7);
               cputs(ball_item[5]);
               textbackground(7);
               textcolor(BLACK);
               gotoxy(2,7);
               cputs(ball_item[5]+1);
               textbackground(BLACK);
               textcolor(WHITE);
               gotoxy(15,7);
               lowvideo();
               cputs(ball_item[5]+14);
               gotoxy(30,13);
               cputs("Playing cricketball game");
               gotoxy(30,14);
               cputs("Press any key to end game");
               getch();
               gettext(1,2,15,9,text_buffer);
               textbackground(BLACK);
               textcolor(WHITE);
               clrscr();
               break;
            case 'E':
               gotoxy(1,8);
               cputs(ball_item[6]);
               textbackground(7);
               textcolor(BLACK);
               gotoxy(2,8);
               cputs(ball_item[6]+1);
               textbackground(BLACK);
               textcolor(WHITE);
               gotoxy(15,8);
               lowvideo();
               cputs(ball_item[6]+14);
               delay(100);
               gettext(1,2,15,9,text_buffer);
               textbackground(BLACK);
               textcolor(WHITE);
               clrscr();
               exit(0);
               break;
            default:clrscr();
         }
      }
      if (item==ESC)
         break;
   }
   getch();
}

void show_ball_item(void)
{
   int i;
   textbackground(BLACK);
   textcolor(WHITE);
   gotoxy(1,2);
   lowvideo();
   cputs(ball_item[0]);
   for (i=2;i<=7;i++) {
      gotoxy(1,i+1);
      lowvideo();
      cputs(ball_item[i-1]);
      highvideo();
      gotoxy(3,i+1);
      cputs(ball_item[i-1]+2);
      gotoxy(4,i+1);
      lowvideo();
      cputs(ball_item[i-1]+3);
   }
   gotoxy(1,9);
   lowvideo();
   cputs(ball_item[7]);
}

void show_norm_title(void)
{
   textbackground(BLACK);
   textcolor(WHITE);
   highvideo();
   gotoxy(6,1);
   cputs(title);
   gotoxy(7,1);
   lowvideo();
   cputs(title+1);
}

void show_high_title(void)
{
   textbackground(7);
   textcolor(BLACK);
   gotoxy(6,1);
   cputs(title);
}

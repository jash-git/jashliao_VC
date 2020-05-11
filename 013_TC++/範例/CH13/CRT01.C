/* program crt01.c */

#include <conio.h>
main()
{
	char s[81]="abcdefghijklmnopqrstuvwxyz";
	int y;
	clrscr();
	gotoxy( 1,1 );
	cprintf("%3d%3d",wherex(),wherey());
	gotoxy( 1,2 );
	cputs(s);
	cprintf("\r\n%3d%3d",wherex(),wherey());
	gotoxy( 1,wherey()+1 );
	cprintf("press any key will delete first line");
	y = wherey();
	getch();
	gotoxy( 1,1 );
	delline();
	gotoxy( 1,y );
	cprintf("press any key will insert blank line on line 2");
	getch();
	gotoxy( 1,2 );
	insline();
	gotoxy( 1,y+2 );
	cprintf("press any key will clear from f until eoln");
	getch();
	gotoxy( 6,1 );
	clreol();
}

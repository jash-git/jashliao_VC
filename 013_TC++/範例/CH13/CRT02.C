/* progarm crt02.c */

#include <conio.h>
main()
{
	char password[7];
	textbackground( BLACK );
	textcolor( LIGHTGRAY );
	clrscr();
	gotoxy(10,12);
	cprintf("Enter ");
	textcolor( WHITE+BLINK );
	cprintf("password ");
	textcolor( LIGHTGRAY );
	cprintf("here : ");
	textcolor( BLACK );
	cscanf("%s",&password);
	if ( ! (strcmp("tintin",password)) )
	{
		textbackground( LIGHTGRAY );
		textcolor( BLACK );
		gotoxy(10,14);
		cputs("Success...");
	}
	else
	{
		textcolor( WHITE );
		gotoxy(10,14);
		cputs("Wrong password...");
	}
	normvideo();
}

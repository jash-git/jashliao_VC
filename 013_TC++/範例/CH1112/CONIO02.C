/* program conio02.c */
/* demo different between puts and cputs */

#include <conio.h>
main()
{
	char string[81]="c programming language";
	puts(string);
	puts(string);
	cputs(string);
	cputs(string);
}

/* program conio01.c */
/* demo string console i/o */

#include <conio.h>
main()
{
	int numread;
	char string[82],*input;
	string[0] = 80;
	cprintf("enter a line:");
	input = cgets(string);
	numread = string[1];
	cprintf("\nEnter %d characters\r\n",numread);
	cprintf("The string is %s\r\n",input);
}

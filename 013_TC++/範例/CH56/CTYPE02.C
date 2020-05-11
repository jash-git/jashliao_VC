/* program ctype02.c */
/* demo get control key ASCII */

#include <ctype.h>
main()
{
	char ch;
	for ( ; ; )
	{
		printf("press control key to test : ");
		ch = getch();
		if ( iscntrl( ch ) )
		{
			printf("The first key is 0, ");
			ch = getch();
			printf("the second key is %d\n",ch);
		}
		else  if ( isspace( ch ) )
			break;
	}
}

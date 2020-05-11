/* program ctype01.c  */
/* demo character type testing */

#include <ctype.h>
main()
{
	char ch;
	for ( ; ; )
	{
		printf("\npress letter or digit character, space for stop: ");
		ch = getche();
		if ( isupper( ch ) )
			printf("\n%c is upper character .",ch);
		else if ( islower( ch ) )
			printf("\n%c is lower character .",ch);
		else if ( isdigit( ch ) )
			printf("\n%c is digit character .",ch);
		else if ( isspace( ch ) )
			break;
	}
}

/* program string07.c */

#include <string.h>
main()
{
	char *s="\0",*p="\0";
	s = "Turbo C++ program language, I like it";
	p = strtok(s," ");
	printf( p );
	do
	{
		p = strtok('\0',", ");
		if ( p )
			printf("|%s",p);
	}
	while ( p );
	printf("\n");
}


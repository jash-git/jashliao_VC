/* program string03.c */

#include <string.h>
main()
{
	char *s1="\0",*s2="\0";
	printf("Enter first string : ");
	gets(s1);
	printf("Enter second string : ");
	gets(s2);
	if ( strcmp(s1,s2) < 0 )
			printf("first string < second string\n");
		else 	if ( strcmp(s1,s2) == 0 )
						printf("first string = second string\n");
					else
						printf("first string > second string\n");
}

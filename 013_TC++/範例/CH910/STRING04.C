/* program string04.c */

#include <string.h>
main()
{
	char *s1="\0",*s2;
	s2 = "abcde";
	strcpy(s1,s2);
	printf("%s\n",s1 );
}

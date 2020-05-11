/* program string02.c */

#include <string.h>
main()
{
	char s1[80] = "abcdefghijk";
	char *s2;
	s2 = strchr(s1,(int)'g');
	printf("%s\n",s2);
}

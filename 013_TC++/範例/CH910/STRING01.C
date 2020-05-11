/* program string01.c */

#include <string.h>
main()
{
	char s1[80] = "abcde";
	char s2[80] = "xyzw";
	strcat(s1,s2);
	printf("%s\n",s1);
}

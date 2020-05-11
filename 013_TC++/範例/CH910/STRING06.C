/* program string06.c */

#include <string.h>

main()
{
	char s1[80] = "abcdefghijk";
	char s2[80] = "def";
	char *s3;
	s3 = strstr(s1,s2);
	printf("%s\n",s3);
}

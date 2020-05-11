/* program ptr05.c */
/* demo pointer string passing */

#include "string.h"
main()
{
	void sub(char **);
	char *s = "abcde";
	sub(&s);
	puts(s);
}
void sub(char **t)
{
	char *s1 = "xyz";
	strcat(*t,s1);
}

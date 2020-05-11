/* program ptr07.c */
/* demo pointer string passing by address */

#include <string.h>
main()
{
	void catenation(char **s);
	char *x = "abcde";
	printf("\nx = %s\n",x);
	catenation(&x);
	printf("\nx = %s\n",x);
}
catenation(char **s)
{
	char *t = "xyz";
	strcat(*s,t);
}


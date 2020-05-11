/* program string08.c */

#include <string.h>
main()
{
	char *s = "abcde";
	char *t = "\0";
	strncpy(t,s,3);
	puts( t );
}

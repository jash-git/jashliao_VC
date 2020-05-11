/* program  string10.c */

#include <string.h>
main()
{
	char *s1 = "abcdef";
	char *s2 = "stuvwxyz";
	strncat(s1,s2,5);
	puts( s1 );
}

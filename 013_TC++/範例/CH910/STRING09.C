/* program string09.c */

#include <string.h>
main()
{
	char *s = "abcdeaijkawxyz";
	char *t="\0";
	t = strrchr(s,'a');
	puts( t );
}

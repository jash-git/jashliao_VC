/* program graph05.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int lowest,highest;
	getmoderange(HERCMONO,&lowest,&highest);
	printf("Lowest = %d\n",lowest);
	printf("Highest = %d\n",highest);
}

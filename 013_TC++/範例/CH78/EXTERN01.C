/* program extern01.c */
/* demo */

#include "file2.h"
int x,y;
main()
{
	void sub1(void);
	x=1;
	printf("%d\n",x);
	sub1();
	printf("%d\n",x);
	sub2();
	printf("%d\n",x);
}
void sub1(void)
{
	x += 1;
}

/* program link12.c */
/* demo link list reverse */

#include <stdlib.h>
#include "link10.h"
main()
{
	void reverse(struct node *);
	setup();
	reverse( base );
	display( base );
	printf("\n");
}
void reverse(struct node *p)
{
	struct node *q = NULL,*r;
	while( p != NULL )
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	base = q;
}

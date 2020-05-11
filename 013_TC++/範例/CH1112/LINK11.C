/* program link11.c */
/* demo link list search */

#include <stdlib.h>
#include "link10.h"
main()
{
	int search(int,struct node *);
	int key,num;
	setup();
	printf("\nYour search key : ");
	scanf("%d",&key);
	if ( ( num = search( key , base )) != 0 )
		printf("found in link list %dth node\n",num);
	else
		printf("not found in link list.\n");
}
int search( int key , struct node *p )
{
	int i=1;
	while ( p != NULL )
		if ( key == p->data )
			break;
		else
		{
			i++;
			p = p->next;
		}
	if ( p == NULL )
		return( 0 );
	else
		return( i );
}

/* program link07.c */
/* demo data node created */

#include <stdlib.h>
main()
{
	struct node
	{
		int data;
		struct node *next;
	} *p;
	p=(struct node *) malloc(sizeof(struct node));
	printf("Enter a data : ");
	scanf("%d",&(p->data));
	p->next = NULL;
	printf("p->data = %d\n",p->data);
	free( p );
}

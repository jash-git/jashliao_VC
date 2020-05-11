/* program link08.c */
/* demo 3-nodes link list */

#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
main()
{
	void display(struct node *);
	struct node *p;
	p=(struct node *) malloc(sizeof(struct node));
	p->data = 11;
	p->next=(struct node *) malloc(sizeof(struct node));
	p->next->data = 22;
	p->next->next=(struct node *) malloc(sizeof(struct node));
	p->next->next->data = 33;
	p->next->next->next = NULL;
	display( p );
	printf("\n");
}
void display( struct node *p )
{
	if ( p != NULL )
	{
		printf("%3d",p->data);
		display( p->next );
	}
}



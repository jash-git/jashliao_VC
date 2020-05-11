/* program link09.c */
/* demo link list created by forward */

#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
main()
{
	struct node *head,*tail,*p;
	int i,n;
	printf("How many data node to create ? ");
	scanf("%d",&n);
	head=tail=(struct node *) malloc(sizeof(struct node));
	for ( i=1 ; i<=n ; i++ )
	{
		p=(struct node *) malloc(sizeof(struct node));
		if ( ! p )
		{
			printf(" Out of memory.\n");
			break;
		}
		printf("Enter %dth node data : ",i);
		scanf("%d",&(p->data));
		p->next = NULL;
		tail->next = p;
		tail=p;
	}
	p = head;
	head = head->next;
	free( p );
	p = head;
	while ( p != NULL )
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}

/* program link02.c */
/* demo pointerto link */

#include <stdio.h>
struct node
{
	int data;
	struct node *next;
};
main()
{
	void display( struct node * );
	struct node one,two,three;
	struct node *ptr;
	ptr = &one;
	one.data = 11;
	one.next = &two;
	two.data = 22;
	two.next = &three;
	three.data = 33;
	three.next = NULL;
	display( ptr );
}
void display( struct node *p )
{
	int i=1;
	while ( p != NULL )
	{
		printf("The %dth node is %d \n",i,p->data);
		i++;
		p = p->next;
	}
}

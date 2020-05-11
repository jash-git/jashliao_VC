/* program link13.c */

#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head,*scan,*pred,*p;
generate()
{
	p=(struct node *) malloc(sizeof(struct node));
	printf("Enter a data : ");
	scanf("%d",&(p->data));
	p->next = NULL;
}
search1(struct node *s,int key)
{
	while ( s != NULL )
	{
		if ( key > s->data )
			break;
		else
		{
			pred = s;
			s = s->next;
		}
	}
	scan = s;
}
insert( int key )
{
	search1( head , key );
	if ( scan == head )
	{
		p->next = head;
		head = p;
	}
	else
	{
		p->next = scan;
		pred->next = p;
	}
}
search2( struct node *s , int key )
{
	while ( s != NULL )
	{
		if ( key == s->data )
			break;
		else
		{
			pred = s;
			s = s->next;
		}
	}
	scan = s;
}
delete( int key )
{
	struct node *t;
	search2( head , key );
	if ( scan == NULL )
		printf("can not delete.\n");
	else if ( scan == head )
	{
		t = head;
		head = head->next;
		free( t );
	}
	else
	{
		t = scan;
		pred->next = scan->next;
		free( t );
	}
}
display( struct node *p )
{
	while ( p != NULL )
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
displaymenu()
{
	printf("Main menu\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Your select : ");
}
main()
{
	int k;
	char sw;
	head = scan = pred = NULL;
	while ( 1 )
	{
		displaymenu();
		scanf(" %c",&sw);
		switch( sw )
		{
			case '1' :
				generate();
				insert( p->data );
				break;
			case '2' :
				printf("Enter delete item : ");
				scanf("%d",&k);
				delete(k);
				break;
			case '3' :
				display( head );
				break;
			default  :
				exit( 1 );
		}
	}
}

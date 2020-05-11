/* program link03.c */
/* demo pointer by value */

struct node
{
	int data;
	struct node *next;
};
main()
{
	void sub( struct node *);
	struct node one,two;
	struct node *p;
	p = &one;
	one.data = 11;
	one.next = &two;
	two.data = 22;
	two.next = &one;
	sub( p );
	printf("p->data = %d\n",p->data);
	printf("p->next->data = %d\n",p->next->data);
}
void sub( struct node *x )
{
	x->data = 33;
	x = x->next;
	x->data = 44;
}

/* program link01.c */
/* demo pointer point to struct */

struct node
{
	int a;
	float b;
};
main()
{
	struct node r={123,1.2345};
	struct node *p=&r;
	printf("p->a = %d\n",p->a);
	printf("p->b = %6.4f\n",p->b);
}

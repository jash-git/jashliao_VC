/* program struct07.c */
/* demo struct data type as parameter by address */

struct node
{
	int item1;
	int item2;
};
main()
{
	void sub( struct node * );
	struct node datanode;
	datanode.item1 = 12;
	datanode.item2 = 34;
	sub( &datanode );
	printf("datanode.item1 = %d\n",datanode.item1);
	printf("datanode.item2 = %d\n",datanode.item2);
}
void sub( struct node *t_node )
{
	t_node->item1 = 56;
	(*t_node).item2 = 78;
}

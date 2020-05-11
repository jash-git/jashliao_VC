/* program struct05.c */
/* demo struct data type as parameter by value */

struct node
{
	int item1;
	int item2;
};
main()
{
	void sub( struct node );
	struct node datanode;
	datanode.item1 = 12;
	datanode.item2 = 34;
	sub( datanode );
	printf("datanode.item1 = %d\n",datanode.item1);
	printf("datanode.item2 = %d\n",datanode.item2);
}
void sub( struct node t_node )
{
	printf("t_node.item1 = %d\n",t_node.item1);
	printf("t_node.item2 = %d\n",t_node.item2);
	t_node.item1 = 56;
	t_node.item2 = 78;
	printf("t_node.item1 = %d\n",t_node.item1);
	printf("t_node.item2 = %d\n",t_node.item2);
}

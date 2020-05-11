/* program struct06.c */
/* demo struct data type as parameter by value */

struct node
{
	int item1;
	int item2;
};
main()
{
	int sum;
	int add( struct node );
	struct node datanode = {12,34};
	sum = add( datanode );
	printf("%d + %d = %d",datanode.item1,
					datanode.item2,sum);
}
int add( struct node x_node )
{
	return( x_node.item1+x_node.item2 );
}


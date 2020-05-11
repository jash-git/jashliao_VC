/* program link06.c */
/* demo data node memory request */

#include <stdlib.h>
struct node
{
	int x;
	float y;
	char z;
};
main()
{
	struct node *ptr;
	ptr = malloc( sizeof( struct node ));
	(*ptr).x = 12;
	(*ptr).y = 3.456;
	(*ptr).z = 'a';
	printf("ptr->x = %d\n",ptr->x);
	printf("ptr->y = %5.3f\n",ptr->y);
	printf("ptr->z = %c\n",ptr->z);
	free( ptr );
}

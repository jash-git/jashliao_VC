/* program fun10.c*/
/* demo passing by address */

int x = -1;
liar(int *a,int *b)
{
	*a = - *b;
	printf("x =%3d  a =%3d  b =%3d\n",x,*a,*b);
	*b = - *b;
	printf("x =%3d  a =%3d  b =%3d\n",x,*a,*b);
}
main()
{
	liar( &x , &x );
	printf("x =%3d\n",x);
}

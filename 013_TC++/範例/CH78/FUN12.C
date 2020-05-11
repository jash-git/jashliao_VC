/* program fun12.c */
/* demo parameter passing */

int a=1, b=2, c=3, d=4;
main()
{
	void pass(int *,int);
	printf("a=%d  b=%d  c=%d  d=%d\n",a,b,c,d);
	pass( &a , b );
	printf("a=%d  b=%d  c=%d  d=%d\n",a,b,c,d);
}
void pass(int *a,int b)
{
	int c=7;
	*a = 5;
	b = 6;
	d = 8;
	printf("a=%d  b=%d  c=%d  d=%d\n",*a,b,c,d);
}

/* program assign01.c */
/* demo assignment */

main()
{
	int a=10;
	int b=20;
	int c;
	c = a = b;
	printf("a = %d, b = %d, c = %d\n",a,b,c);
	c = a == b;
	printf("a = %d, b = %d, c = %d\n",a,b,c);
}

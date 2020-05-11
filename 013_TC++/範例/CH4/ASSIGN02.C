/* program assign02.c 8/
/* demo assignment */

main()
{
	int a=6;
	int b=8;
	int c;
	c = a++;
	printf("a = %d, c = %d\n",a,c);
	c = a--;
	printf("a = %d, c = %d\n",a,c);
	c = ++b;
	printf("b = %d, c = %d\n",b,c);
	c = --b;
	printf("b = %d, c = %d\n",b,c);
}

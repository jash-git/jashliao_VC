/* program fun01b.c */
/* demo ANSI style */

main()
{
	int f(int);
	int i;
	printf("Enter int value : ");
	scanf("%d",&i);
	printf("f(%d)=%d\n",i,f(i));
}
int f(int x)
{
	return( 3*x+5 );
}

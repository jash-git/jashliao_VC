/* program fun01a.c */
/* demo K & R style */

main()
{
	int i;
	printf("Enter int value : ");
	scanf("%d",&i);
	printf("f(%d)=%d\n",i,f(i));
}
f(int x)
{
	return( 3*x+5 );
}

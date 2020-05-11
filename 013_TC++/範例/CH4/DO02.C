/* program do02.c */
/* demo do while loop using */

main()
{
	int n,s=0;
	do
	{
		printf("Enter one value or 0 for stop :");
		scanf("%d",&n);
		s += n;
	}
	while ( n );
	printf("Total = %d\n",s);
}

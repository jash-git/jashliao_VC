/* program do01.c */
/* demo do while loop using */

main()
{
	int s=0;
	int i=0;
	int n;
	printf("Enter one integer value :");
	scanf("%d",&n);
	do
	{
		s += i;
		i++;
	}
	while ( i <= n );
	printf("sum = %d\n",s);
}

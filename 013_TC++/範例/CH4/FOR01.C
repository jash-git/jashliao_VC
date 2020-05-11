/* program for01.C */
/* demo for loop using */

main()
{
	int s,i,n;
	s = 0;
	printf("Enter one integer value :");
	scanf("%d",&n);
	for ( i=1 ; i<=n ; i++ )
		s += i;
	printf("sum = %d\n",s);
}

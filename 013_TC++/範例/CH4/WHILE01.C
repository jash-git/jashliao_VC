/* program while01.c */
/* demo while long using */

main()
{
	int s,i,n;
	s=0;i=1;
	printf("Enter one integer value : ");
	scanf("%d",&n);
	while ( i <= n )
	{
		s += i;
		i++;
	}
	printf("sum = %d\n",s);
}

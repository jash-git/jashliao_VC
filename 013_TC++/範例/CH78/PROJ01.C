/* program proj01.c */
/* demo seperate compile */

main()
{
	int a,b,*c;
	printf("Enter two integer value : ");
	scanf("%d %d",&a,&b);
	c = multiply(a,b,&c);
	printf("%d*%d = %d\n",a,b,*c);
}

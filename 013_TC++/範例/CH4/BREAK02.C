/* program break02.c */
/* demo break statement using */

main()
{
	int t,tf,c=0;
	printf("Enter total number and feet :");
	scanf("%d %d",&t,&tf);
	while ( c <= t )
		if ( 2*c+4*(t-c) == tf )
			break;
		else c++;
	if ( c <= t )
		printf("Chicken= %d, Rabbit= %d\n",c,t-c);
	else
		printf("Input data error, no solution!\n");
}

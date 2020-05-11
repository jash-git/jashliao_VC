/* program break03.c */
/* demo break statement using */

main()
{
	int t,tf,c=-1;
	printf("Enter total number and feet :");
	scanf("%d %d",&t,&tf);
	do
	{
		c++;
		if ( 2*c+4*(t-c) == tf )
			break;
	}
	while ( c <= t );
	if  ( c <= t )
		printf("Chicken= %d, Rabbit= %d \n",c,t-c);
	else
		printf("Input data error, no solution!\n");
}

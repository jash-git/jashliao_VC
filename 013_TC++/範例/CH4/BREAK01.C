/* program break01.c */
/* demo break statement using */

main()
{
	int t,tf,c;
	printf("Enter total number and feet :");
	scanf("%d %d",&t,&tf);
	for ( c=0 ; c <= tf ; c++ )
		if ( 2*c+4*(t-c) == tf )
			break;
	if ( c <= t )
		printf("Chicken= %d, Rabbit= %d\n",c,t-c);
	else printf("Input data error, no solution!\n");
}

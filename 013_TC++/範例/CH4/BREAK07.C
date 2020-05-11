/* program break07.c */
/* demo goto using */

main()
{
	int t,tf,c;
	printf("Enter total number and feet : ");
	scanf("%d %d",&t,&tf);
	for ( c=0 ; c<=tf ; c++ )
		if ( 2*c+4*(t-c) == tf )
			goto answer;
	printf("Input data error, no solution !\n");
	goto stop;
	answer :
	printf("Chicken = %d, Rabbit = %d\n",c,t-c);
	stop :;
}

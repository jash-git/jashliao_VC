/* program op05.c */
/* demo conditional expression and operator */

main()
{
	int max,min,abs;
	int i=-3,j=-5;
	max = ( i > j ) ? i : j;
	min = ( i < j ) ? i : j;
	abs = ( i < 0 ) ? -i : i;
	printf("%d and %d, the max is %d\n",i,j,max);
	printf("%d and %d, the min is %d\n",i,j,min);
	printf("The abs(%d) is %d\n",i,abs);
}

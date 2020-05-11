/* program op01.c */
/* demo arithmetic operation */

main()
{
	int i,j;
	i = 10;
	j = 3;
	printf("%d mod %d = %d\n",i,j,i %j );
	j = i++;
	printf("j = %d\n",j);
	i = 10;
	j = ++i;
	printf("j = %d\n",j);
}

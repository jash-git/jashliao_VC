/* program do03.c */
/* demo do while long using */

main()
{
	char ch;
	int  count=0;
	printf("press any key until press return : ");
	do
	{
		ch = getche();
		count++;
	}
	while ( ch != '\r');
	printf("\nTotal typing %d characters\n",count);
}

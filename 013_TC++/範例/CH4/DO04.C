/* program do04.c */
/* demo do while loop using */

main()
{
	char ch;
	do
	{
		ch =  getch();
		printf("\n The keypressed is %c, ",ch);
		printf("ASCII value is %d\n",ch);
	}
	while( ch != 'Q');
}

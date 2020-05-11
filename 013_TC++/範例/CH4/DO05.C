/* program do05.c */
/* demo do while nesting using */

main()
{
	char ch;
	int charcount=0;
	int linecount=0;
	printf("press ctr-z for stop\n");
	do
	{
		do
		{
			ch = getche();
			charcount++;
		}
		while ( ch != '\r' && ch != 26 );
		putch('\n');
		linecount++;
	}
	while (  ch != 26 );
	printf("\nTotal typing %d characters",charcount);
	printf("\nTotal typing %d lines\n",linecount);
}

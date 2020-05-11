/* program break05.c */
/* demo continue statement using */

main()
{
	int i;
	for ( i=1 ; i<21 ; i++ )
	{
		printf("%3d",i);
		if ( i % 5 != 0 )
			continue;
		printf("\n");
	}
}

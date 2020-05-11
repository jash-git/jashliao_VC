/* program if06.c */
/* demo dangling if */

main()
{
	int x=5;
	int y=20;
	if( x > 0 )
		 if ( x > y )
				x -= 5;
	else
	y -= 5;
	printf("x = %d, y = %d\n",x,y);
}

/* program  switch01.c */
/* demo  switch & break using */

main()
{
	int i;
	while ( 1 )
	{
		printf("Enter 1-3 or 4 for exit : ");
		scanf("%d",&i);
		switch( i )
		{
			case 1 :
						printf("Excellent!\n");
						break;
			case 2 :
						printf("Good!\n");
						break;
			case 3 :
						printf("Fair!\n");
						break;
			case 4 :
						printf("Bye! Bye!\n");
						break;
		 default :
						printf("Illegal number try again ! \n");
		}
		if ( i == 4 )
			break;
	}
}

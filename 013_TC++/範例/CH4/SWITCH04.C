/* program switch04.c */
/* demo nesting switch using */

main()
{
	char p1,p2;
	printf("Enter s, r or p for play 1: ");
	scanf("%c",&p1);
	printf("Enter s, r or p for play 2: ");
	scanf(" %c",&p2);
	switch( p1 )
	{
		case 's' :
			switch( p2 )
			{
				case 's' :
					printf("scissors ties scissors, p1=p2\n");
					break;
				case 'r' :
					printf("scissors crush by rock, p1<p2\n");
					break;
				case 'p' :
					printf("scissors cut paper, p1>p2\n");
					break;
			}
			break;
		case 'r' :
			printf("rock ");
			switch( p2 )
			{
				case 's' :
					printf("crushes scissors, p1>p2\n");
					break;
				case 'r' :
					printf("ties rock, p1=p2\n");
					break;
				case 'p' :
					printf("warped by paper, p1<p2\n");
					break;
			}
			break;
		case 'p' :
			printf("paper ");
			switch( p2 )
			{
				case 's' :
					printf("cut by scissors, p1<p2\n");
					break;
				case 'r' :
					printf("warps rock, p1>p2\n");
					break;
				case 'p' :
					printf("ties paper, p1=p2\n");
					break;
			}
			break;
	}
}

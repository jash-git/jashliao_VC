/* program enum03.c */

main()
{
	enum Week {Sun,Mon,Tue,Wed,Thr,Fri,Sat,Outrange} day;
	int i;
	do {
			printf("\nEnter (0-6) : ");
			scanf("%d",&i);
			switch( i )
			{
				case 0 : day = Sun;
								 break;
				case 1 : day = Mon;
								 break;
				case 2 : day = Tue;
								 break;
				case 3 : day = Wed;
								 break;
				case 4 : day = Thr;
								 break;
				case 5 : day = Fri;
								 break;
				case 6 : day = Sat;
								 break;
			 default : day = Outrange;
			}
			switch(day)
			{
				case 0 : printf("Sun");
								 break;
				case 1 : printf("Mon");
								 break;
				case 2 : printf("Tue");
								 break;
				case 3 : printf("Wed");
								 break;
				case 4 : printf("Thr");
								 break;
				case 5 : printf("Fri");
								 break;
				case 6 : printf("Sat");
								 break;
			 default : exit( 1 );
		}
	}
	while ( i < 7 );
}

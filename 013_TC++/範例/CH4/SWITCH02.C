/* program switch02.c */
/* demo  switch & break using */

main()
{
	int numdeg;
	do
	{
		printf("Enter numeric degree or -1 stop : ");
		scanf("%d",&numdeg);
		if (numdeg == -1)
			 break;
		printf("%d ===> ",numdeg);
		switch( numdeg / 10 )
		{
			case  0 :
			case  1 :
			case  2 :
			case  3 :
			case  4 :
							printf("%c\n",'F');
							break;
			case  5 :
							printf("%c\n",'D');
							break;
			case  6 :
							printf("%c\n",'C');
							break;
			case  7 :
							printf("%c\n",'B');
							break;
			case  8 :
			case  9 :
			case 10 :
							printf("%c\n",'A');
							break;
			default :
							break;
		}
	}
	while ( numdeg >= 0 );
}

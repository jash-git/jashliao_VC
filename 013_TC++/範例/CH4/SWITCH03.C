/* program switch03.c */
/* demo switch & break using */

main()
{
	char lg;
	int i=0,gpa=0;
	do
	{
		printf("Enter letter  grade : ");
		scanf(" %c",&lg);
		switch( lg )
		{
			case 'a' :
								i++;
								gpa += 4;
								break;
			case 'b' :
								i++;
								gpa += 3;
								break;
			case 'c' :
								i++;
								gpa += 2;
								break;
			case 'd' :
								i++;
								gpa += 1;
								break;
			default  : ;
		}
	}
	while ( lg != 'q' );
	printf(" The grade point average = %4.2f\n",(float)gpa/i);
}

/* program if03.c */
/* demo nesting statement */

main()
{
	int a,b,c,t;
	printf("Enter triangle 3-edges length :");
	scanf("%d %d %d",&a,&b,&c);
	if ( a < b )
	{
		t = a; a = b; b = t;
	}
	if ( a < c )
	{
		t = a; a = c; c = t;
	}
	if ( b < c )
	{
		t = b; b = c; c = t;
	}
	if ( b+c <= a )
			printf(" can not be a triangle \n");
	else if ( a*a == b*b+c*c )
					printf("Right Triangle\n");
			 else if ( a*a > b*b+c*c )
							printf("Obtuse  Triangle\n");
						else printf("Acute Triangle\n");
}

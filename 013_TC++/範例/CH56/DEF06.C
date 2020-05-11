/* program def06.c */
/* demo define boolean function */

#define Is_Lower(c) (((c) >= 'a' ) && ((c) <= 'z' )) ? 1 : 0
#define Is_Upper(c)	(((c) >= 'A' ) && ((c) <= 'Z' )) ? 1 : 0
main()
{
	char ch;
	do {
				printf("press <a..z> or < A..Z> ");
				ch = getche();
		 }
	while ( ! Is_Lower( ch ) && ! Is_Upper( ch ) );
	if ( Is_Upper( ch ) )
		printf("\n %c is upper character\n",ch);
	else
		printf("\n %c is lower character\n",ch);
}

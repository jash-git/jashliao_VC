/* program file08.c */
/* demo disk to screen */

#include <stdio.h>
main()
{
	FILE *testf;
	char *fn="\0";
	char ch;
	printf("Enter file name : ");
	gets( fn );
	testf = fopen( fn, "r" );
	if ( testf == NULL )
	{
		puts("can not open file\n");
		exit();
	}
	while ( (ch=getc( testf )) != EOF )
		if ( ch != '\n' )
			putchar( ch );
		else
			printf("\n");
	fclose( testf );
}

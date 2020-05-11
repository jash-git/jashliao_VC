/* program file07.c */
/* demo keyboard to disk */

#include <stdio.h>

main()
{
	FILE *testf;
	char *fn="\0";
	char ch;
	printf("Enter file name : ");
	gets( fn );
	testf = fopen(fn,"w");
	if ( testf == NULL )
	{
		puts("can not open file \n");
		exit();
	}
	
	while ( (ch=getche()) != 26 )	/* ctrl-z */
		if ( ch != '\r')
			putc(ch,testf);
		else
		{
			putch('\n');
			fprintf(testf,"\n");
		}
	fclose( testf );
}

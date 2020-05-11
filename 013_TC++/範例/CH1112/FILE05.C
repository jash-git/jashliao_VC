/* program file05.c */
/* demo binary file created */

#include <stdio.h>
main()
{
	FILE *outf;
	int num;
	outf = fopen( "file05.dat","wb");
	for ( num=0 ; num<10 ; num++ )
		putw( num , outf );
	fclose( outf );
	printf("Binary integer file created.\n");
}


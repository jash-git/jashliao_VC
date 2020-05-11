/* program file03.c */
/* demo write to disk */

#include <stdio.h>
main()
{
	int num;
	FILE*outf;
	outf =  fopen("file03.txt","w");
	for ( num=0 ; num<10 ; num++ )
		fprintf(outf,"%3d",num);
	fclose( outf );
	printf("Integer text file created.\n");
}


/* program graph25.c */

#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	FILE *fp;
	int x1,x2,x3,x4;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	fp = fopen("graph25.txt","r");
	rewind( fp );
	while ( !feof( fp ) )
	{
		fscanf(fp,"%d %d %d %d ",&x1,&x2,&x3,&x4);
		line( x1,x2,x3,x4 );
	}
	fclose( fp );
	getche();
	closegraph();
}


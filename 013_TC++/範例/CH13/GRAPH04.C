/* program graph04.c */

#include <graphics.h>
#include <stdlib.h>
#include <time.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int i;
	unsigned int x=60,y=100,x1,y1;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	randomize();
	for ( i=0 ; i<20 ; i++ )
	{
		x1 = (unsigned)(random(320));
		y1 = (unsigned)(random(160));
		line(x,y,x1,y1);
		x = x1;
		y = y1;
	}
	getch();
	closegraph();
}

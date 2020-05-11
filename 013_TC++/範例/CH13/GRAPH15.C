/* program graph15.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	setcolor(getmaxcolor());
	circle(50,50,20);
	setfillstyle( WIDE_DOT_FILL,LIGHTGRAY );
	floodfill(50,50,getmaxcolor());
	getch();
	closegraph();
}

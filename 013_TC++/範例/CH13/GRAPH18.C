/* program graph18.c */

#include <graphics.h>
#include <stdlib.h>
#define topflag 1
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int y0=10,y1=60,y2=110,x1=10,x2=50;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	bar3d(x1,y1,x2,y2,10,0);
	sleep( 1 );
	setfillstyle( HATCH_FILL,WHITE );
	bar3d(x1,y0,x2,y1,10,topflag);
	getch();
	closegraph();
}

/* program graph08.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	struct arccoordstype arcco;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	arc(100,100,0,270,30);
	getarccoords(&arcco);
	line(arcco.xstart,arcco.ystart,100,100);
	line(arcco.xend,arcco.yend,100,100);
	getch();
	closegraph();
}

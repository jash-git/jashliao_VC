/* program graph09.c */

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
	circle(100,100,50);
	ellipse(100,100,0,360,30,50);
	ellipse(100,100,0,180,50,30);
	rectangle(0,0,100,100);
	pieslice(100,100,0,30,30);
	getch();
	closegraph();
}

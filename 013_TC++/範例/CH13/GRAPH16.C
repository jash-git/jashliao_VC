/* program graph16.c */

#include <graphics.h>
#include <stdlib.h>
#define  clipping 1
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	rectangle(19,19,getmaxx()-19,getmaxy()-19);
	setviewport(20,20,getmaxx()-20,getmaxy()-20,clipping);
	outtextxy(20,20,"<return> clear viewport :");
	getch();
	clearviewport();
	outtextxy(20,20,"<return> to quit :");
	getch();
	closegraph();
}

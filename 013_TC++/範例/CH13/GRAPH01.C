/* program graph01.c */

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
	line(15,10,25,10);
	moveto(25,10);
	lineto(25,15);
	lineto(15,15);
	lineto(15,10);
	moveto(20,3);
	lineto(20,35);
	getch();
	closegraph();
}

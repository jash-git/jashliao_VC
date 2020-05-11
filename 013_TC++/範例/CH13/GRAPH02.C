/* program graph02.c */

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
	line(5,5,35,5);
	moveto(35,5);
	lineto(35,35);
	lineto(5,35);
	lineto(5,5);
	line(10,10,17,10);
	line(23,10,30,10);
	line(20,10,20,25);
	line(20,25,23,25);
	line(13,27,13,30);
	line(27,27,27,30);
	line(13,30,27,30);
	getch();
	closegraph();
}

/* program graph06.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int color;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	color = getmaxcolor();
	randomize();
	do
	{
		putpixel(random(100),random(100),color);
		delay(10);
	}
	while ( ! kbhit() );
	printf("\n");
	getch();
	closegraph();
}

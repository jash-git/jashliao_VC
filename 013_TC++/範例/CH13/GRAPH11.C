/* program graph11.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int gray50[8]={0xaa,0x55,0xaa,0x55,
								 0xaa,0x55,0xaa,0x55};
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	setfillpattern( gray50,LIGHTGRAY );
	bar(0,0,300,300);
	getch();
	closegraph();
}

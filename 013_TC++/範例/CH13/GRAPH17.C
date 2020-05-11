/* program graph17.c */

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
	moveto( 0,0 );
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	outtext("ABC");
	outtext("DEF");
	getch();
	moveto(100,50);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	settextjustify(RIGHT_TEXT,TOP_TEXT);
	outtext("ABC");
	moveto(125,50);
	outtext("DEF");
	getch();
	moveto(100,100);
	settextstyle(DEFAULT_FONT,VERT_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	outtext("ABC");
	moveto(100,125);
	outtext("DEF");
	getch();
	closegraph();
}

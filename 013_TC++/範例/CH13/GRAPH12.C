/* program graph12.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	struct fillsettingstype fillinfo;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	bar(0,0,50,50);
	sleep( 1 );
	setfillstyle(SLASH_FILL,WHITE);
	bar(50,0,100,50);
	sleep( 1 );
	setfillstyle(HATCH_FILL,LIGHTGRAY);
	bar(100,0,150,50);
	getch();
	closegraph();
}

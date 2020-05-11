/* program graph13.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	struct viewporttype	p;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	getviewsettings(&p);
	rectangle(0,0,p.right-p.left,p.bottom-p.top);
	if ( p.clip )
		outtext("Clipping is active.");
	else
		outtext("No clipping today.");
	getch();
	closegraph();
}

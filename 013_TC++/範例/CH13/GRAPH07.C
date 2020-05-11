/* program graph07.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int radius;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	for ( radius=1 ; radius<=5 ; radius++ )
		arc(100,100,0,90,radius*10);
	getch();
	closegraph();
}

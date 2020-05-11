/* program graph14.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int triangle[]={80,150,40,250,120,250,80,150};
	int pentagon[]={80,1,40,31,40,81,120,81,120,31,80,1};
	int numps=sizeof(pentagon)/(2*sizeof(int));
	int numpoints=sizeof(triangle)/(2*sizeof(int));
	initgraph(&graphdriver,&graphmode," ");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	drawpoly(numpoints,triangle);
	setfillstyle( LTBKSLASH_FILL,WHITE );
	fillpoly( numps,pentagon );
	getch();
	closegraph();
}

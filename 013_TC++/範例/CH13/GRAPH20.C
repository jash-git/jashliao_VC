/* program graph20.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not garphics.\n");
		exit( 1 );
	}
	if ((graphdriver==HERCMONO) || (graphdriver==VGA) ||
			(graphdriver==EGA64) || (graphdriver==EGAMONO))
	{
		setactivepage( 0 );
		circle( 100,100,80 );
		setvisualpage( 0 );
		sleep( 1 );
		setactivepage( 1 );
		rectangle( 10,20,30,40 );
		setvisualpage( 1 );
	}
	else
		outtext("No paging supported.");
	getch();
	closegraph();
}

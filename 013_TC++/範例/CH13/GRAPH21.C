/* program graph21.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int i=0;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	if ((graphdriver==HERCMONO) || (graphdriver==VGA) ||
			(graphdriver==EGA64) || (graphdriver==EGAMONO))
		do
		{
			cleardevice();
			setvisualpage( i % 2 );
			setactivepage((i+1) % 2);
			rectangle(10+i*5,20,30+i*5,40);
			setvisualpage((i+1) % 2);
			sleep( 1 );
			i++;
		}
		while ( i != 20 );
	else
		outtext("No paging supported.");
	getch();
	closegraph();
}

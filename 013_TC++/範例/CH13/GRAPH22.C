/* program graph22.c */

#include <graphics.h>
#inlcude <stdlib.h>
#include <math.h>
#include <dos.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int x=300,y=200,r=180,n=20,keypressed;
	int xasp,yasp;
	double p,s=0,x1,y1;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	circle( x,y,r );
	setbkcolor( 0 );
	getaspectratio( &xasp,&yasp );
	p = (double)xasp / yasp;
	do
	{
		s = 0.0;
		do
		{
			x1 = x+sin(s)*(r-10)*p;
			y1 = y-cos(s)*(r-10)*p;
			setcolor(15);
			line( x,y,(int)x1,(int)y1 );
			delay(n);
			setcolor(0);
			line( x,y,(int)x1,(int)y1 );
			s += 0.1;
		 }
		 while ( ( s < 6.2 ) && ! kbhit() );
	}
	while ( ! kbhit() );
	getch();
	closegraph();
}

/* program graph10.c */

#include <graphics.h>
#include <stdlib.h>
#define width 10
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int i;
	char pattern[]={2,3,5,8,10};
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	for ( i=0 ; i<5 ; i++ )
	{
		setfillstyle( pattern[i] , WHITE );
		bar((i+1)*width,(i+1)*10,(i+2)*width,200);
	}
	getch();
	closegraph();
}

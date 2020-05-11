/* program graph03.c */

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	int i=5,j;
	int x,y,x1,y1;
	FILE *fp;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	fp = fopen("c:\\turboc\\ch13\\graph03.txt","r");
	while ( i <= 165 )
	{
		rewind(fp);
		fscanf(fp," %d %d",&x,&y);
		for ( j=0 ; j<4 ; j++ )
		{
			fscanf(fp," %d %d",&x1,&y1);
			line(i+x,i+y,i+x1,i+y1);
			x = x1;
			y = y1;
		}
		i += 10;
	}
	fclose(fp);
	getch();
	closegraph();
}

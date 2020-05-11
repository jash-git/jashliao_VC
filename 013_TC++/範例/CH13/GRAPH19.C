/* program graph19.c */

#include <graphics.h>
#include <stdlib.h>
main()
{
	int graphdriver=DETECT,graphmode=DETECT;
	unsigned size;
	void *buffer;
	initgraph(&graphdriver,&graphmode,"");
	if ( graphresult() != grOk )
	{
		printf("can not graphics.\n");
		exit( 1 );
	}
	bar( 0,0,getmaxx(),getmaxy() );
	size = imagesize( 10,20,30,40 );
	buffer = malloc(size);
	getimage(10,20,30,40,buffer);
	randomize();
	do
	{
		sleep( 1 );
		cleardevice();
		putimage(random(720),random(348),buffer,COPY_PUT);
	}
	while ( ! kbhit() );
	closegraph();
}

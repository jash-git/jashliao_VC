/* program file27.c */
/* demo unbuffered file random access */

#include <io.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#define  size 	128
char buf[size];
void display();
main()
{
	void display( int );
	int fd,s,numread;
	long pos;
	if (( fd = open("file25.dat",O_RDONLY )) == -1 )
	{
		printf("can not open file.\n");
		exit( 1 );
	}
	do {
			printf("\nbuffer no (-1 for stop): ");
			scanf("%d",&s);
			pos = (long)(s*size);
			if (lseek(fd,pos,SEEK_SET) != pos)
				printf("seek error.\n");
			if ((numread=read( fd,buf,size)) != size)
				printf("EOF  reach.\n");
			display(numread);
	}
	while (s>=0);
	close(fd);
}
void display( int numread )
{
	int i,j;
	for ( i=0 ; i<numread/16 ; i++)
	{
		for ( j=0 ; j<16 ; j++ )
			printf("%3x",buf[i*16+j]);
		printf("   ");
		for ( j=0; j<16 ; j++)
		{
			if (isprint( buf[i*16+j]))
				printf("%c",buf[i*16+j]);
			else
				printf(".");
		}
		printf("\n");
	}
}

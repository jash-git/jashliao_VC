/* program file22.c */
/* demo unbuffered file retrived */

#include <io.h>
#include <fcntl.h>
#define buf_size 	1024
main()
{
	unsigned buf[ 512 ];
	unsigned handle,i;
	if ( (handle = open("file21.dat",O_BINARY|O_RDONLY)) == -1 )
	{
		printf("can not open file.\n");
		exit( 1 );
	}
	if ( (temp=read( handle,buf,buf_size ) )!= buf_size )
	{
		printf("error on read\n");
		exit( 1 );
	}
	for ( i=0 ; i<512 ; i++ )
		printf("%4d",buf[i]);
	printf("\n");
	close( handle );
}

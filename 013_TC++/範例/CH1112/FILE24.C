/* program file24.c */
/* demo unbuffered file retrived */

#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#define  buf_size 	1024
main()
{
	unsigned buf[ 512 ];
	unsigned handle,i,read_byte;
	long offset;
	if ((handle=open("file21.dat",O_BINARY|O_RDONLY)) == -1)
	{
		printf("can not open file.\n");
		exit( 1 );
	}
	printf("Enter offset even bytes ( 0 - 1024 ) : ");
	scanf("%D",&offset);
	lseek( handle,offset,SEEK_SET );
	if ( (read_byte = read( handle,buf,buf_size-offset ) )
				!= buf_size - offset )
	{
		printf("error on read.\n");
		exit( 1 );
	}
	for ( i=0 ; i<(buf_size-offset)/2 ; i++ )
		printf("%4d",buf[i]);
	printf("\n");
	close( handle );
}

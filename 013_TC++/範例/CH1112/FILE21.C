/* program file21.c */
/* demo unbuffered file created */

#include <io.h>
#include <sys\stat.h>
#include <fcntl.h>
#include <sys\types.h>
#define  buf_size	1024
main()
{
	unsigned buf[ 512 ];
	unsigned handle,i;
	if ((handle=open("file21.dat",O_CREAT|O_BINARY|O_WRONLY,S_IWRITE)) == -1 )
	{
		printf("can not open file.\n");
		exit( 1 );
	}
	for ( i=0 ; i<512 ; i++ )
		buf[i] = i;
	if ( write( handle,buf,buf_size ) != buf_size )
	{
		printf("error on write.\n");
		exit( 1 );
	}
	printf("Unbuffer file created.\n");
	close( handle );
}

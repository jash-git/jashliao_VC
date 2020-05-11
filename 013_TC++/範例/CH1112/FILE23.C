/* program file23.c */
/* demo unbuffered file retrived */

#include <io.h>
#include <fcntl.h>
#define  buf_size 	32
#define  array_size 16
main()
{
	unsigned buf[ array_size ];
	unsigned handle,i;
	if ((handle=open("file21.dat",O_BINARY|O_RDONLY)) == -1)
	{
		printf("can not open file.\n");
		exit( 1 );
	}
	while ((read(handle,buf,buf_size)) && !eof(handle))
	{
		for ( i=0 ; i<array_size ; i++ )
			printf("%4d",buf[i]);
		printf("\n");
	}
	close( handle );
}

/* program file26.c */
/* demo unbuffered file retrived */

#include <io.h>
#include <errno.h>
#include <fcntl.h>
#define buf_size 	128
main()
{
	char buf[buf_size];
	int fd,t;
	if (( fd = open( "file25.dat",O_RDONLY )) == -1 )
	{
		printf("Error no: %d\t",errno);
		printf("can not open file.\n");
		exit( 1 );
	}
	while ( ! eof(fd) )
	{
		read(fd,buf,buf_size);
		printf("%s\n",buf );
	}
	close( fd );
}

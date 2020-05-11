/* program file25.c */
/* demo unbuffered file created */

#include <io.h>
#include <sys\stat.h>
#include <errno.h>
#include <sys\types.h>
#define  buf_size	128
main()
{
	char buf[ buf_size ];
	int handle,t;
	if ((handle=creat("file25.dat",S_IWRITE|S_IREAD)) == -1 )
	{
		printf("Error no : %d\t",errno);
		printf("can not open file.\n");
		exit( 1 );
	}
	do
	{
		for ( t=0 ; t<buf_size ; t++ )
			buf[t] = '\0';
		gets( buf );
		if (write(handle,buf,buf_size) != buf_size )
		{
			printf("error on write.\n");
			exit( 1 );
		}
	}
	while (strcmp(buf,"quit"));
	close(handle);
}

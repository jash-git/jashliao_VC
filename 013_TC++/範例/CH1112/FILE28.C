/* program file28.c */
/* demo copy an any file */

#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <sys\types.h>
#define  buf_size  128
main()
{
	char buf[ buf_size ];
	int handle1,handle2,read_byte;
	char *sf,*df;
	printf("Enter source file name : ");
	scanf("%s",sf);
	printf("Enter destination file name : ");
	scanf("%s",df);
	if ((handle1=open(sf,O_RDONLY)) == -1 )
	{
		printf("can not open source file.\n");
		exit(1);
	}
	if ((handle2=creat(df,S_IWRITE|S_IREAD))==-1)
	{
		printf("can not open target file.\n");
		exit(1);
	}
	while( !eof(handle1) )
		if ((read_byte=read(handle1,buf,buf_size)) != -1 )
			write(handle2,buf,read_byte);
		else
			printf("error on read.\n");
	close( handle1 );
	close( handle2 );
}

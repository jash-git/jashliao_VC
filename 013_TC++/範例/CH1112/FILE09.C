/* program file09.c */
/* demo command line file argument */

#include <stdio.h>
main(int argc,char *argv[])
{
	FILE *fp;
	char ch;
	int count=0;
	if ( argc  != 2 )
	{
		printf("You missing the file name.\n");
		exit();
	}
	if (( fp = fopen(argv[1],"r+t") ) == NULL )
	{
		printf("Can not open file.\n");
		exit();
	}
	while ( getc( fp )  != EOF )
		count++;
	fclose( fp );
	printf("FILE %s has %d characters.\n",argv[1],count);
}

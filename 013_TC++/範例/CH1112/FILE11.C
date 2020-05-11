/* program file11.c */
/* demo file of string retrived  */

#include <stdio.h>
main()
{
	FILE *fp;
	char string[81];
	if (( fp = fopen( "file10.txt","r" )) == NULL )
	{
		printf("can not open file\n");
		exit();
	}
	while ( fgets( string , 81 , fp ) != NULL )
		printf("%s",string );
	fclose( fp );
}

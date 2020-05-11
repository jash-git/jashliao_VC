/* program file10.c */
/* demo string type write to disk */

#include <stdio.h>
#include <string.h>
main()
{
	FILE *fp;
	char string[81];
	if (( fp = fopen("file10.txt","w")) == NULL )
	{
		printf("can not open file\n");
		exit();
	}
	printf("Enter strings or RETURN for stop:\n");
	while ( strlen( gets( string ) ) > 0 )
	{
		fputs( string , fp );
		fputs( "\n", fp );
	}
	printf("File of string created\n");
	fclose( fp );
}

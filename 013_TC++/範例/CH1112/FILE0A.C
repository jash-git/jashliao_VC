/* program file0a.c */

#include <stdio.h>
main()
{
	char filename[81];
	FILE *f;
	printf("Enter the name of an existing file : ");
	scanf("%s",&filename);
	/* open file */
	if ( (f = fopen(filename,"r")) == NULL )
	{
		printf("Can not open %s file.\n",filename);
		exit(0);
	}
	/* try to write a line */
	fprintf(f,"Test...");
	/* check for error */
	if ( ferror(f) != 0 )
	{
		printf("Error detect!\n");
		clearerr(f);
	}
	if ( ferror(f) == 0 )
		printf("Error cleared.\n");
	fclose( f );
}

/* program file02.c */
/* demo from disk to screen, textfile */

#include <stdio.h>
main()
{
	FILE *inf;
	int x;
	inf = fopen("file01.txt","r");
	while ( ! feof( inf ) )
	{
		fscanf( inf, "%d",&x);
		printf("%d ",x);
	}
	printf("End of file ...\n");
	fclose( inf );
}


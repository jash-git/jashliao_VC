/* program file04.c */
/* demo from disk to disk */

#include <stdio.h>
main()
{
	FILE *inf, *outf;
	int num;
	inf = fopen("file03.txt","r");
	outf = fopen("file04.txt","w");
	while ( ! feof( inf ) )
	{
		fscanf(inf," %d",&num);
		fprintf(outf," %d",num*2);
	}
	fcloseall();
	printf("File processing ok.\n");
}

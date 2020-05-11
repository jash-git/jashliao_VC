/* program file01.c */
/* demo from keyboard to disk, text file */

#include <stdio.h>
main()
{
	FILE *outf;
	int x1,x2;
	outf = fopen("file01.txt","w");
	printf("Enter two integer value : ");
	scanf("%d %d",&x1,&x2);
	fprintf(outf,"%d %d",x1,x2);
	fclose( outf );
	printf("file file01.txt created.\n");
}

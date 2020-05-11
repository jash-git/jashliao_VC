/* program file17.c */
/* demo file of array created */
#include <stdio.h>
#include <stdlib.h>
main()
{
	int x[10]={75,55,65,95,80,60,85,90,100,70};
	FILE *fp;
	if (( fp = fopen("file17.dat","wb")) == NULL )
	{
		printf("can not open file \n");
		exit(1);
	}
	fwrite( &x,sizeof(x),1,fp);
	fclose( fp );
	printf("file of array created.\n");
}

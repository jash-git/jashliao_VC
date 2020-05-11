/* program file18.c */
/* demo file of array retrived */
#include <stdio.h>
#include <stdlib.h>
main()
{
	int x[10];
	int i;
	FILE *fp;
	if ( ( fp=fopen("file17.dat","rb") ) == NULL )
	{
		printf("can not open file \n");
		exit(1);
	}
	rewind(fp);
	fread(&x,sizeof(x),1,fp);
	for ( i=0 ; i<10 ; i++ )
		printf("%4d",x[i]);
	printf("\n");
	fclose( fp );
}

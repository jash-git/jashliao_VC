/* program file06.c */
/* demo binary file retrived */

#include <stdio.h>
main()
{
	FILE *inf;
	int num;
	inf = fopen("file05.dat","rb");
	while ((num = getw( inf )) != EOF )
			printf("%3d",num);
	fclose ( inf );
	printf("\nEnd of binary file.\n");
}

/* program text02.c */
/* demo text file retrived */

#include <stdio.h>
main()
{
	struct score
	{
		char id[7];
		char name[9];
		int s1,s2;
	};
	struct score p;
	FILE *fp;
	if ((fp=fopen("text01.txt","r")) == NULL )
	{
		printf("can not open file\n");
		exit( 1 );
	}
	while ( fscanf(fp,"%s %s %d %d ",
					&(p.id),&(p.name),&(p.s1),&(p.s2)) != EOF )
		printf("%6s %8s %4d %4d\n",p.id,p.name,p.s1,p.s2);
	printf("End of file.\n");
	fclose( fp );
}

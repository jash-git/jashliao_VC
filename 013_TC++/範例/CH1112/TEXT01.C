/* program text01.c */
/* demo text file created */

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
	if ((fp=fopen("text01.txt","w")) == NULL )
	{
		printf("Can not open file\n");
		exit(1);
	}
	do
	{
		printf("\nEnter id : ");
		scanf("%s",&(p.id));
		printf("Enter name : ");
		scanf("%s",&(p.name));
		printf("Enter math score : ");
		scanf("%d",&(p.s1));
		printf("Enter bcc score : ");
		scanf("%d",&(p.s2));
		fprintf(fp,"%s\\0 %s\\0 %d %d\n",p.id,p.name,p.s1,p.s2);
		printf("Continue or not (Y/N) ? ");
	}
	while ( toupper(getche()) == 'Y');
	fclose( fp );
	printf("\nText file created.\n");
}

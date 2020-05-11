/* program file14.c */
/* demo file of struct random access */

#include <stdio.h>
main()
{
	struct score
	{
		char id[7];
		char name[9];
		int s1,s2;
	};
	struct score student;
	FILE *fp;
	int recnum;
	if ((  fp = fopen("file12.dat","rb")) == NULL )
	{
		printf("can not open file\n");
		exit();
	}
	do
	{
		printf("\nEnter record number : ");
		scanf("%d",&recnum );
		fseek(fp,sizeof(student)*recnum,SEEK_SET);
		if ( fread(&student,sizeof(student),1,fp ) )
		{
			printf("\nID   : %s\n",student.id);
			printf("NAME : %s\n",student.name );
			printf("MATH : %d\n",student.s1 );
			printf("BCC  : %d\n",student.s2 );
		}
		else
			printf("  Error input!");
		printf("  Continue or not ( Y / N ) ? ");
	}
	while ( toupper( getche() ) == 'Y' );
	fclose( fp );
}

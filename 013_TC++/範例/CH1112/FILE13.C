/* program file13.c */
/* demo file of struct retrived */

#include <stdio.h>
main()
{
	struct
	{
		char id[7];
		char name[9];
		int s1,s2;
	}	student;
	int temp;
	FILE *fp;
	fp = fopen("file12.dat","rb");
	if ( fp == NULL )
	{
		printf("can not open file\n");
		exit();
	}
	rewind( fp );
	while(!feof(fp) && fread(&student,sizeof(student),1,fp))
	{
		printf("\nID   : %s\n",student.id );
		printf("NAME : %s\n",student.name );
		printf("MATH : %d\n",student.s1 );
		printf("BCC  : %d\n",student.s2 );
	}
	fclose( fp );
}

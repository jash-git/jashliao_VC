/* program file16.c */
/* demo file of struct update */

#include <stdio.h>
main()
{
	struct score
	{
		char id[7];
		char name[9];
		int  s1,s2;
	};
	struct score student;
	FILE *fp;
	int recnum,sw;
	if (( fp = fopen( "file12.dat","r+b" ) ) == NULL )
	{
		printf("can not open file.\n");
		exit();
	}
	do
	{
		printf("\nEnter record number : ");
		scanf("%d",&recnum);
		fseek(fp,sizeof(student)*recnum,SEEK_SET);
		if (fread(&student, sizeof(student),1,fp))
		{
			printf(" 1.ID:%s,2.NAME:%s,3.MATH:%d, 4.BCC:%d\n",
			student.id,student.name,student.s1,student.s2);
			do
			{
				printf("Which field do you update (1-4");
					printf(",0 for exit) ? ");
					scanf("%d",&sw);
			}
			while (( sw < 0 ) || ( sw > 4 ));
			switch ( sw )
			{
				case 1 : printf("Enter correct id : ");
								 scanf("%s",&student.id);
								 break;
				case 2 : printf("Enter correct name : ");
								 scanf("%s",&student.name );
								 break;
				case 3 : printf("Enter correct math : ");
								 scanf("%d",&student.s1 );
								 break;
				case 4 : printf("Enter correct bcc : ");
								 scanf("%d",&student.s2 );
								 break;
			 default : ;
			}
			fseek(fp,sizeof(student)*recnum,SEEK_SET);
			fwrite(&student,sizeof(student),1,fp);
		}
		else
			printf("  Input error!\n");
		printf("  Continue or not ( Y / N ) ? ");
	}
	while ( toupper(getche()) == 'Y');
	fclose( fp );
	printf("\nDAM file update completely.\n");
}

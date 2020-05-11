/* program file15.c */
/* demo file of  struct append */

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
	if (( fp = fopen("file12.dat","ab")) == NULL )
	{
		printf("can not opeon file\n");
		exit();
	}
	do
	{
		printf("\nEnter id : ");
		scanf("%s",&student.id);
		printf("Enter name : ");
		scanf("%s",&student.name);
		printf("Enter math score : ");
		scanf("%d",&student.s1);
		printf("Enter bcc score : ");
		scanf("%d",&student.s2);
		fwrite( &student , sizeof( student ) , 1 , fp );
		printf("  Continue or not ( Y / N ) ? ");
	}
	while ( toupper( getche() ) == 'Y');
	fclose( fp );
	printf("\nFile of struct append.\n");
}

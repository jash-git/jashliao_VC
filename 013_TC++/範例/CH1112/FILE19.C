/* program file19.c */
/* demo dam file created basis on record key */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define  n	47
struct score
{
	char id[7];
	char name[9];
	int s1,s2;
};
struct score  student;
FILE *fp;
garbagefillin()
{
	int i;
	for (i=0;i<n;i++)
	{
		strcpy(student.id ,"000000");
		strcpy(student.name ,"********");
		student.s1 = 0;
		student.s2 = 0;
		fwrite(&student,sizeof(student),1,fp);
	}
}
hash( char key[7] )
{
	long int num, sum=0;
	num = atol( key );
	while ( num > 0 )
	{
		sum += ( num % 100 );
		num /= 100;
	}
	return ( (int) sum % n );
}
next_location( int recnum )
{
	return(( recnum+1 ) % n );
}
empty( int recnum )
{
	fseek( fp, sizeof(student)*recnum, SEEK_SET );
	fread( &student, sizeof(student),1,fp );
	if ( (strcmp( student.id,"000000")) == 0 )
		return( 1 );
	else return( 0 );
}
main()
{
	char query_id[7];
	int home_address,collision;
	if (( fp = fopen("file19.dat","w+b")) == NULL )
	{
		printf("can not open file\n");
		exit( 1 );
	}
	rewind( fp );
	garbagefillin();
	do
	{
		printf("\nEnter record ID : ");
		scanf("%s",&query_id );
		home_address = hash( query_id );
		do
		{
			collision = !( empty( home_address ));
			if ( collision )
			if (strcmp( student.id,query_id ) == 0 )
			{
				printf("data duplicated...\n");
				break;
			}
			else
				home_address = next_location( home_address );
		}
		while ( collision );
		if ( collision )
			continue;
		strcpy( student.id , query_id );
		printf("Enter name : ");
		scanf("%s",&student.name );
		printf("Enter math : ");
		scanf("%d",&student.s1);
		printf("Enter bcc : ");
		scanf("%d",&student.s2);
		fseek(fp,sizeof(student)*home_address,SEEK_SET);
		fwrite(&student,sizeof(student),1,fp);
	}
	while(printf("Continue or not (Y/N)? ") &&
				toupper(getche()) == 'Y');
	fclose( fp );
	printf("\nDAM file created.\n");
}

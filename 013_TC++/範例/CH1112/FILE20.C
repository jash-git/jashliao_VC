/* program file20.c */
/* demo dam file fretrived according record */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define  n	47
struct score
{
	char id[7];
	char name[9];
	int s1,s2;
};
struct score student;
FILE *fp;
hash( char key[7] )
{
	long int num,sum=0;
	num = atol( key );
	while ( num > 0 )
	{
		sum += ( num % 100 );
		num /= 100;
	}
	return( (int) sum % n );
}
next_location( int recnum )
{
	return(( recnum+1 ) % n);
}
empty( int recnum )
{
	fseek(fp,sizeof(student)*recnum,SEEK_SET);
	fread(&student, sizeof(student),1,fp);
	if (strcmp(student.id,"000000") == 0 )
		return( 1 );
	else
		return( 0 );
}
main()
{
	char query_id[7];
	int home_address,exist;
	if ( ( fp = fopen( "file19.dat","r+b")) == NULL )
	{
		printf("can not open file.\n");
		exit(1);
	}
	do
	{
		printf("\nEnter record ID : ");
		scanf("%s",&query_id );
		home_address = hash( query_id );
		do
		{
			exist = !( empty( home_address ));
			if ( !( exist ) )
			{
				printf("invalid key data not found.\n");
				break;
			}
			else if ( strcmp(student.id,query_id) == 0 )
			{
				printf("ID:%s, NAME:%s, MATH:%d, BCC:%d\n",
						student.id,student.name,student.s1,student.s2);
				break;
			}
					else
						home_address = next_location( home_address );
		}
		while ( exist );
			printf("Continue or not ( Y/N ) ? ");
	}
	while ( toupper( getche() ) == 'Y' );
	printf("\nDAM file retrived demo success !\n");
	fclose( fp );
}

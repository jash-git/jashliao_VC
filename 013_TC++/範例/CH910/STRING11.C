/* program  string11.c */

#include <string.h>
main()
{
	void cmpresult(char *,char *,int);
	char *s1 = "Turbo C";
	char *s2 = "Turbo Pascal";
	cmpresult( s1 , s2 , 6 );
	cmpresult( s1 , s2 , 7 );
}
void cmpresult( char *s , char *t , int n )
{
	if ( strncmp( s , t , n ) == 0 )
		printf("%s = %s for %d leading\n",s,t,n);
	else  if ( strncmp( s , t , n ) > 0 )
					printf("%s > %s for %d leading\n",s,t,n);
				else
					printf("%s < %s for %d leading\n",s,t,n);
}


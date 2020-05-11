/* program str07.c */
/* demo string application */

#include <string.h>
main()
{
	void tlb(char **);
	void ttb(char **);
	char *s = "       Turbo   C        ";
	tlb(&s);
	ttb(&s);
	printf("%s\n",s);
}
void tlb(char **s)		/* trancate leading blank */
{
	int i;
	for ( i=0 ; i<strlen(*s) ; i++ )
		if ( *(*s+i) != ' ')
			break;
	*s = strchr(*s,*(*s+i));
}
void ttb(char **s)		/* trancate backing blank */
{
	int i;
	for ( i=strlen(*s)-1 ; i>=0 ; i-- )
		if ( *(*s+i)  != ' ')
			break;
	*(*s+i+1) = '\0';
}

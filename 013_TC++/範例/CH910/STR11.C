/* program str11.c */
/* password coding */

#include <string.h>
char s[]="abcdefghijklmnopqrstuvwxyz";
main()
{
	int i,j,k;
	char p[80],t[80];
	printf("Enter offset : ");
	scanf("%d",&k);
	printf("Enter source word :");
	scanf(" ");
	gets(p);
	for ( i=0 ; i<strlen(p) ; i++ )
	{
		for ( j=0 ; j<strlen(s) ; j++ )
			if ( *(p+i) == *(s+j) )
				break;
		if (j==strlen(s))
			 *(t+i) = ' ';
		else
			 *(t+i) = *(s + (j+k)%26 );
	}
	printf("plaintext  = %s\n",p);
	printf("ciphertext = %s\n",t);
}



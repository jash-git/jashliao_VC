/* program conio03.c */
/* demo getpass using */

#include <conio.h>
#include <string.h>
main()
{
	int c=0,ok;
	char *p="tintin";
	char *password;
	do
	{
		password = getpass("Enter your password : ");
		if (( ok = strcmp( p,password )) == 0 )
			printf("Welcome to computer center !\n");
		else
			printf("Illegal password, try again...\n");
		c++;
	}
	while ( ( c<3 ) && ( ok ) );
}

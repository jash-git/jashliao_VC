/* program str04.c */
/* demo string element access */

main()
{
	char s1[] = "abcdefghij";
	char *s2 = "mnopqrstuv";
	int i;
	for ( i=0 ; i<10 ; i++ )
		printf("%c",s1[i]);
	printf("\n");
	for ( i=0 ; i<10 ; i++ )
		printf("%c",*(s1+i));
	printf("\n");
	for ( i=0 ; i<10 ; i++ )
		printf("%c",s2[i]);
	printf("\n");
	for ( i=0 ; i<10 ; i++ )
		printf("%c",*(s2+i));
	printf("\n");
}


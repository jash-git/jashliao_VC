/* program str02.c */
/* demo string input and output */

main()
{
	char s1[80];
	char s2[80];
	char *s3="\0";
	printf("Enter first string : ");
	gets(s1);
	printf("Enter second string : ");
	gets(s2);
	printf("Enter third string : ");
	gets(s3);
	printf("The first string = %s\n",s1 );
	printf("The second string = %s\n",s2 );
	printf("The third string = ");
	puts(s3);
}

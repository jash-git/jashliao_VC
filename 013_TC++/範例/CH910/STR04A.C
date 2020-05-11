/* program str04a.c */
/* demo scanf() and gets() mix using */

main()
{
	char s1[80];
	char s2[80];
	printf("Enter first string : ");
	scanf("%s",&s1);
	printf("Enter second string : ");
	scanf(" ");
	gets(s2);
	printf("first string=%s\n",s1);
	printf("second string=");
	puts(s2);
}

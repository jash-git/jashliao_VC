/* program str03.c */
/* demo string expression for special characters */

main()
{
	char s1[] = "\"Turbo C programming\"";
	char s2[] = "The command is CD \\ turboc";
	char s3[] = "I don\'t like Turbo C";
	char s4[] = "Using \%s to print string";
	puts(s1);
	puts(s2);
	printf("%s\n",s3);
	printf("%s\n",s4);
}


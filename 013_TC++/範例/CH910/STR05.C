/* program str05.c */
/* demo output string variable address */

main()
{
	char s1[11]="c language";
	char s2[]="abcde";
	char *s3="computer";
	printf("s1 address = %u\n",&s1);
	printf("s1 address = %u\n",s1);
	printf("s2 address = %u\n",&s2);
	printf("s2 address = %u\n",s2);
	printf("s3 address = %u\n",&s3);
	printf("s3 content = %u\n",s3);
}


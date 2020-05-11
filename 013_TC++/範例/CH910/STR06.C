/* program str06.c */
/* demo string variable assign */

main()
{
	char *s1 = "abcde";
	char *s2;
	char *s3;
	s2 = s1;
	s3 = s2;
	puts( s1 );
	puts( s2 );
	puts( s3 );
}

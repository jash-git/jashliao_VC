/* program str06a.c */
/* string variable pass by address */

main()
{
	void change(char *);
	char s[] = "abcdefg";
	char *t="ijklmnop";
	change( s );
	change( t );
	puts( s );
	puts( t );
}
void change( char *x )
{
	*(x+2) = '$';
	*(x+5) = '+';
}

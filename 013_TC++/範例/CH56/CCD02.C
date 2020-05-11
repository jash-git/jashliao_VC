/* program ccd02.c */

#ifdef __TURBOC__
#define print(n) printf("verson is %x\n",n);
#endif
main()
{
	print( __TURBOC__);
	printf("Test predefined preprocessor symbol.\n");
}

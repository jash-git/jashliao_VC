/* program ptr01.c */
/* demo pointer concept */

main()
{
	int a=2,*p,*q;
	*p=&a;
	q = p;
	printf("%3d %3d\n",*p,*q);
}

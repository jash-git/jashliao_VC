/* program io02.c */
/* demo printing control format */

main()
{
	double d=1.23456e+308;
	printf("d = %lf\n",d);
	printf("d = %le\n",d);
	printf("d = %lg\n",d);
}

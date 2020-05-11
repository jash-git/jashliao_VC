/* program ccd01.c  */

#define DOUBLE
main()
{
	#ifdef DOUBLE
		double pi = 3.141593468435e+000;
	#else
		flolat pi = 3.14159;
	#endif
	#ifndef FLOAT
		printf("pi = %le\n",pi);
	#else
		printf("pi = %f\n",pi);
	#endif
}

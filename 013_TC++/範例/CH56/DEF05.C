/* program def05.c */
/* demo define constant and function */

#define c_to_f	1.8
#define f_to_c	0.555556	/* 5/9 */
#define dif 		32.0
#define fr(c)		(c) * c_to_f + dif
#define ce(f)		( (f) -  dif )  * f_to_c
main()
{
	float c,f;
	printf("Enter C degree and F degree : ");
	scanf("%f %f",&c,&f);
	printf("%6.2f C degree = %6.2f F degree \n",c,fr(c) );
	printf("%6.2f F degree = %6.2f C degree \n",f,ce(f) );
}

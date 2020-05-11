/* program def03.c */
/* demo define function */

#define f(x)	2*(x)*(x)-4*(x)+5
main()
{
	int x;
	printf("Enter one integer value : ");
	scanf(" %d",&x);
	printf("The f(%d) = 2x^2 - 4x + 5 = %d\n",x,f(x) );
}

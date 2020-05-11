/* program def02.c */
/* demo define constand and function */

#define pi		3.14159
#define Area(r) 	2*pi*(r)*(r)
main()
{
	int r;
	printf("Enter radius : ");
	scanf(" %d",&r);
	printf("The area = %10.4f\n",Area(r));
}

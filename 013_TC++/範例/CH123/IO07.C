/* program io07.c */
/* demo I/O for various kind of data type */

main()
{
	int a,b;
	float c,d;
	char ch;
	char s[10];

	a = 120;
	c = 0.000456;
	ch = '$';
	printf("Enter integer value :");
	scanf("%d",&b);
	printf("\nEnter float and string :");
	scanf("%f %s",&d,&s);
	printf("\n%d + %d = %d\n",a,b,a+b);
	printf("%d + %f = %f\n",a,c,a+c);
	printf("%f + %f = %f\n",c,d,c+d);
	printf("%g\n",c);
	printf("%c %s \n",ch,s);
}

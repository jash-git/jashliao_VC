/* program  ptr04.c */
/* demo pointer as parameter pass by address */

main()
{
	void sub(int **,int **);
	int a=1,*p;
	p = &a;
	sub(&p,&p);
	printf("%3d\n",*p);
}

void sub(int **x,int **y)
{
	**x = 2;
	printf("%d %d\n",**x,**y);
	**y = 3;
	printf("%d %d\n",**x,**y);
}

/* program fun02.c */
/* demo function component */

int k=1;
main()
{
	void sub(int,float);
	int x=2;
	float y=3.5;
	sub(x,y);
	printf("%d %4.1f %d\n",x,y,k);
}
void sub(int i,float f)
{
	int j=4;
	i++;
	f--;
	k = j;
	printf("%d %4.1f %d\n",i,f,k);
}

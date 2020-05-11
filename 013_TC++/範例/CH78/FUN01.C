/* program fun01.c */
/* demo block structure  */

int x=1;
int y=2;
main()
{
	void subroutine1(void);
	int x=3;
	int i=4;
	printf("X = %d  Y = %d  I = %d\n",x,y,i );
	subroutine1();
}
void subroutine1(void)
{
	void subroutine2(int);
	int j=5;
	subroutine2( j );
	printf("X = %d  Y = %d  J = %d \n",x,y,j);
}
void subroutine2( int x )
{
	int k=6;
	printf("X = %d  Y = %d  K = %d\n",x,y,k);
}

/* program rcs08.c */
/* demo recursive  call for Hanoi tower */

main()
{
	int n;
	void hanoi(int,char,char,char);
	printf("Enter how many disk : ");
	scanf("%d",&n);
	printf("\n %d disks moving as following : \n");
	printf("---------------------------------\n");
	hanoi (n,'a','c','b');
	printf("---------------------------------\n");
}
void hanoi(int n,char frompeg,char topeg,
					 char auxpeg)
{
	if ( n == 1 )
	{
		printf(" move disk 1 from peg %c to peg %c \n",
						 frompeg,topeg);
	}
	else
	{
		hanoi(n-1,frompeg,auxpeg,topeg);
		printf(" move disk %d from peg %c to peg %c \n",
						 n,frompeg,topeg);
		hanoi(n-1,auxpeg,topeg,frompeg);
	}
}

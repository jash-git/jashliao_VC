/* program ary0d.c */
/* demo structure programing */

main()
{
	void Input(int *);
	void Process(int *);
	void Output(int *);
	int x[6];
	Input( x );
	Process( x );
	Output( x );
}
/* Input routine */
void Input(int x[])
{
	int i;
	for ( i=0 ; i<6 ; i++ )
	{
		printf("Enter x[%d]=",i);
		scanf("%d",&x[i]);
	}
}
void Process(int x[])
{
	int i;
	for ( i=0 ; i<6 ; i++ )
		x[i] += x[(i+1)%6];
}
void Output(int x[])
{
	int i;
	for ( i=0 ; i<6 ; i++ )
		printf("%4d",x[i]);
	printf("\n");
}

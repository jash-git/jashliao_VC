/* program ary09.c */
/* demo arry using for indexing */

main()
{
	int x[10] = { 70,26,75,83,69,92,85,65,45,61 };
	int c[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
	int i;
	for ( i=0 ; i<10 ; i++ )
		c[ x[i]/10 ]++;
	for ( i=0 ; i<9 ; i++ )
		printf("%2d - %3d ==> %2d\n",i*10,i*10+9,c[i]);
	printf("%2d - %3d ==> %2d\n",90,100,c[9]+c[10]);
}

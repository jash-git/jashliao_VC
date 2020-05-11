/* program ptr06.c */
/* demo pointer array */

main()
{
	int x[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int *ptr,i;
	ptr = x;
	printf("The array starting address is %5u\n",&x[0]);
	for ( i=0 ; i<10 ; i++ )
		printf("%2d",*(ptr+i) );
	printf("\n");
}


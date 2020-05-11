/* program const03.c */
/* demo bit operation */

main()
{
	int i = 24;
	int j = 16;
	int k,l,m,n,p,q;
	k = i & j;  /* AND */
	l = i | j;  /* OR  */
	m = ~i;     /* NOT */
	n = i ^ j;  /* XOR */
	p = i >> 2; /* Shift right 2 bits */
	q = j << 2; /* Shift left 2 bits */
	printf("%d AND %d = %d\n",i,j,k);
	printf("%d OR %d = %d\n",i,j,l);
	printf("NOT %d = %d\n",i,m);
	printf("%d XOR %d = %d\n",i,j,n);
	printf("%d Shift right 2 bit = %d\n",i,p);
	printf("%d Shift left 2 bit = %d\n",j,q);
}

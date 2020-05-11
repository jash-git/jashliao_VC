/* program struct10.c */
/* demo array of struct as parameter */

#define n 	4
struct score
{
	char *name;
	int s1,s2;
	float avg;
};
main()
{
	void count( struct score * );
	void sort( struct score * );
	void print( struct score * );
	struct score class[] =
	{ {"Jame",60,90},{"Jackson",59,59},
		{"Jacky",80,90},{"Jenny",70,70} };
	count( class );
	sort( class );
	print( class );
}
void count( struct score *cs )
{
	int i;
	for ( i=0 ; i<n ; i++ )
		(*(cs+i)).avg=((*(cs+i)).s1+(*(cs+i)).s2)/2;
}
void sort( struct score *cs )
{
	struct score t;
	int i,j;
	for ( i=0 ; i<n-1 ; i++ )
		for ( j=i+1 ; j<n ; j++ )
			if ( (*(cs+i)).avg < (*(cs+j)).avg )
			{
				t = *(cs+i);
				*(cs+i) = *(cs+j);
				*(cs+j) = t;
			}
}
void print( struct score x[n] )
{
	int i;
	for ( i=0 ; i<n ; i++ )
		printf("%-8s %5d %5d   %6.1f\n",x[i].name,
						x[i].s1,x[i].s2,x[i].avg);
}

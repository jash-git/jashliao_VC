/* program  ary14.c */
/* demo two dimension array using */
/* poker flush and distribute */

#include <stdlib.h>
#include <time.h>
#define m	4
#define n 13
char c[m] = { 6,3,4,5 };
char *d[n] = {"A","2","3","4","5","6",
							"7","8","9","10","J","Q","K"};
main()
{
	int i,j;
	int x[m][n];
	void flushcard(int [m][n]);
	void printcard(int [m][n]);
	for ( i=0 ; i<m ; i++ )
		for ( j=0 ; j<n ; j++ )
			x[i][j] = 0;
	randomize();
	flushcard(x);
	printcard(x);
}
/* flush card and distribute */
void flushcard(int x[m][n])
{
	int i,j,p=0,c=0;
	do
	{
		i = random( m );
		j = random( n );
		if ( x[i][j] == 0 )
		{
			p = p % m + 1;
			x[i][j] = p;
			c++;
		}
	}
	while ( c < 52 );
}
/* output card */
void printcard(int x[m][n])
{
	int p,i,j;
	for ( p=1 ; p<=m ;  p++ )
	{
		for ( i=0 ; i<m ; i++ )
			for ( j=0 ; j<n ; j++ )
				if (x[i][j] == p )
					printf("%c %-3s",c[i],d[j]);
		printf("\n");
	}
}

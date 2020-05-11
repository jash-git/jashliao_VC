/* program crt03.c */

#include <stdio.h>
#define  x 		 10
#define  y 		 4
#define  space 32
struct personnel
{
	char name[13],adrs[31],tel[8];
}p;
void forms()
{
	clrscr();
	gotoxy( x,y );
	printf("***     DATA ENTRY FORM     ***\n");
	gotoxy( x,y+2 );
	printf("1.NAME:............\n");
	gotoxy( x,y+4 );
	printf("2.ADRS:..............................\n");
	gotoxy( x,y+6 );
	printf("3.TEL:.......\n");
	gotoxy( x,y+8 );
	printf("SEL:.");
	gotoxy( x,y+10 );
	printf("*** OPERATION GUIDE ***\n");
	gotoxy( x,y+11 );
	printf("Press 1-3 to update each filed\n");
	gotoxy( x,y+12 );
	printf("Press 4 to write data into diskette");
	gotoxy( x,y+13 );
	printf("Press RETURN to start key in data\n");
	gotoxy( x,y+14 );
	printf("Press SPACE BAR to exit  ");
}
main()
{
	FILE *fp;
	int  s,ch;
	fp = fopen("crt03.txt","w");
	do
	{
		forms();
		ch = getche();
		printf("\n");
		if ( ch != space )
		{
			gotoxy( x+7,y+2 );
			gets( p.name );
			gotoxy( x+7,y+4 );
			gets( p.adrs );
			gotoxy( x+6,y+6 );
			gets( p.tel );
			do
			{
				gotoxy( x+4,y+8 );
				s = getche();
				switch ( s )
				{
					case '1' :
						gotoxy( x+7,y+2 );
						gets( p.name );
						break;
					case '2' :
						gotoxy( x+7,y+4 );
						gets( p.adrs );
						break;
					case '3' :
						gotoxy( x+6,y+6 );
						gets( p.tel );
						break;
					case '4' :
						fprintf(fp,"%13s %31s %8s\n",p.name,p.adrs,p.tel);
						break;
					default: ;
				}
			}
			while ( s < '4' );
		}
	}
	while ( ch != space );
	gotoxy( x,y+15 );
	printf("crt03.txt created ...");
	fclose( fp );
}

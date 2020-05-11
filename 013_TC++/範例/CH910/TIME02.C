/* program time02.c */
/* demo setdate and get date */

#include <dos.h>
main()
{
	void printdate( struct date d );
	int month,day,year;
	struct date d;
	getdate( &d );
	printdate( d );
	printf("Enter new date (mm/dd/yy) : ");
	scanf("%d/%d/%d",&month,&day,&year);
	d.da_day = day;
	d.da_mon = month;
	d.da_year = year + 1900;
	setdate( &d );
	getdate( &d );
	printdate( d );
}
void printdate( struct date d )
{
	printf("The date is %d/%d/%d\n",
					d.da_mon,d.da_day,d.da_year-1900);
}

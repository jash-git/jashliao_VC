/* program time06.c */
/* demo set time from UNIX format */

#include <stdio.h>
#include <dos.h>
#include <time.h>
main()
{
	void print_date_time(struct date,struct time);
	int d,m,y,h,min,sec;
	long uxtime;
	time_t tt;
	struct date de;
	struct time te;
	getdate( &de );
	gettime( &te );
	print_date_time( de,te );
	printf("Enter new date (mm/dd/yy) : ");
	scanf("%d/%d/%d",&m,&d,&y);
	printf("Enter new time (hh:mi:ss) : ");
	scanf("%d:%d:%d",&h,&min,&sec);
	de.da_mon = m;
	de.da_day = d;
	de.da_year = y+1900;
	te.ti_hour = h;
	te.ti_min = min;
	te.ti_sec = sec;
	/* convert date & time to UNIX format */
	uxtime = dostounix(&de,&te);
	/* set date and time from stime() */
	stime( &uxtime );
	/* get the time from time() */
	tt = time( NULL );
	printf("The date and time is %s\n",ctime(&tt));
}
void print_date_time(struct date de,struct time te)
{
	printf("The date is %d/%d/%d\n",de.da_mon,
					de.da_day,de.da_year-1900);
	printf("The time is %d:%d:%d\n",te.ti_hour,
					te.ti_min,te.ti_sec);
}

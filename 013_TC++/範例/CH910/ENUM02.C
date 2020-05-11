/* program enum02.c */

main()
{
	enum week {Sun,Mon,Tue,Wed,Thr,Fri,Sat};
	enum week day;
	char dayname[][4] = {"Sun","Mon","Tue","Wed","Thr","Fri","Sat"};
	for ( day=Sun ; day<=Sat ; day++ )
		printf("%4s",dayname[day]);
}

/* program enum01.c */

main()
{
	enum week { Sun,Mon,Tue,Wed,Thr,Fri,Sat };
	enum week day;
	day = Sun;
	for ( day=Sun ; day<=Sat ; day++ )
		printf("%2d",day);
	printf("\n");
}

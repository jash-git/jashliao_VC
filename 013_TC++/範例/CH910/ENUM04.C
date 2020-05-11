/* program enum04.c */

main()
{
	enum coin { penny,nickel,dime=4,quarter=6,half_dollar,dollar};
	enum coin money;
	for ( money=penny ; money<=dollar ; money++ )
		printf("%3d",money);
	printf("\n");
}

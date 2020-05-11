/* program struct01.c */
/* demo structure data type I/O */

main()
{
	struct date
	{
		int month,day,year;
	};
	struct date birthday;
	birthday.month = 3;
	birthday.day = 10;
	birthday.year = 1990;
	printf("The birthday is %d/%d/%d\n",
					birthday.month,birthday.day,birthday.year);
}

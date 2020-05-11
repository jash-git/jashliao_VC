/* program struct04.c */
/* demo struct assign */

main()
{
	struct personnel
	{
		char *name;
		int age;
	};
	struct personnel p1,p2;
	p1.name = "Jacky";
	p1.age = 37;
	p2 = p1;
	printf("The name is %s\n",p2.name);
	printf("The age is %d\n",p2.age);
}

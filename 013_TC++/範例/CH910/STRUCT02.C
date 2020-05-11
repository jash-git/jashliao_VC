/* program struct02.c */
/* demo structure data type I/O */

main()
{
	struct personnel
	{
		char *name;
		int age;
	};
	struct personnel p;
	printf("Enter name : ");
	scanf("%s",p.name );
	printf("Enter age : ");
	scanf("%d",&(p.age) );
	printf("Name = %s, Age = %d",p.name,p.age);
}

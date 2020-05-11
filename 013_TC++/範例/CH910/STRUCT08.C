/* program struct08.c */
/* demo array of structure data type */

struct score
{
	char *name;
	int s1,s2;
	float avg;
};
main()
{
	struct score class[] = { {"Jame",60,90},
													 {"Jackson",59,59},
													 {"Jacky",80,90},
													 {"Jenny",70,70} };
	int i;
	for ( i=0 ; i<4 ; i++ )
		class[i].avg = (class[i].s1+class[i].s2)/2;
	printf("Name        S1    S2      Average\n");
	printf("---------------------------------\n");
	for ( i=0 ; i<4 ; i++ )
		printf("%-8s %5d %5d     %6.1f\n",class[i].name,
						class[i].s1,class[i].s2,class[i].avg);
}

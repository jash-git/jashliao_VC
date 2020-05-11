/* program while03.c */
/* demo while loop using */

main()
{
	int count = 0;
	printf("Press any key until press return : ");
	while ( getche() != '\r')
		count++;
	printf("\nTotal typing %d characters\n",count );
}

/* program sound06.c */

#include <dos.h>
void sirene()
{
	int freq;
	for ( freq=500 ; freq<=2000 ; freq++ )
	{
		delay( 1 );
		sound( freq );
	}
	for ( freq=2000 ; freq>=500 ; freq-- )
	{
		delay( 1 );
		sound( freq );
	}
}
main()
{
	printf("\nPress any key to stop : ");
	while ( ! kbhit() )
		 sirene();
	nosound();
}


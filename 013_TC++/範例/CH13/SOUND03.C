/* program sound03.c */

#include <dos.h>
main()
{
	unsigned f;
	do
	{
    printf("key in frequence : ");
		scanf("%d",&f);
		sound( f );
		sleep( 1 );
		nosound();
	}
	while (f != 0);
}

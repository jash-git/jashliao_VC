/* program file0b.c */
/* demo try to open 16 temporary files */
/* but do not use these files */

#include <stdio.h>
main()
{
	int i;
	for ( i=1 ; i<=16 ; i++ )
		if ( tmpfile() == NULL )
			printf("Error opening file #%d\n",i);
		else
			printf("Temporary file #%-2d opened\n",i);
	i = fcloseall();
	printf("%d files were closed.",i);

}

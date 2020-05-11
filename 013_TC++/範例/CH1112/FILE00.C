/* program file00.c */
/* demo execution result output  to printer */

#include <stdio.h>
#include <bios.h>
main()
{
	int a,b;
	if (biosprint(1,'x',0)==200)
	{
		printf("printer not ready, open the printer.\n");
		exit();
	}
	printf("Enter a and b : ");
	scanf("%d %d",&a,&b);
	fprintf(stdprn,"Enter a and b : %d %d\n",a,b);
	fprintf(stdprn,"%d + %d = %d\n",a,b,a+b);
}

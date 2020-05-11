/*                          */
/* Program Name : _getdrv.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <direct.h>

void main()
{
   unsigned driveno;

   clrscr();

   driveno = _getdrive();
   printf("Current disc drive is %c:\n", driveno + 'A' - 1);

   printf("\nPress any key to continue...");
   getch();
}

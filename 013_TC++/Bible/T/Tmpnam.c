/*                         */
/* Program Name : tmpnam.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   char tmpname[3][L_tmpnam];

   clrscr();

   tmpnam(tmpname[0]);
   tmpnam(tmpname[1]);
   tmpnam(tmpname[2]);

   printf("Temporary name 0: %s\n", tmpname[0]);
   printf("Temporary name 1: %s\n", tmpname[1]);
   printf("Temporary name 2: %s\n", tmpname[2]);
   printf("Temporary name in internal static object : %s\n", tmpnam(NULL));

   printf("\nPress any key to continue...");
   getch();
}

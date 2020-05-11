/*                         */
/* Program Name : access.c */
/*                         */

#include <io.h>
#include <stdio.h>
#include <conio.h>

void main()
{
   char pathname[80];

   clrscr();
   printf("Please enter a file name:");
   gets(pathname);

   if (access(pathname, 0) != 0)
      printf("File %s does not exist.\n", pathname);

   if (access(pathname, 2)  == 0)
      printf("File %s has write permission.\n", pathname);

   if (access(pathname, 4)  == 0)
      printf("File %s has read permission.\n", pathname);

   if (access(pathname, 6)  == 0)
      printf("File %s has read and write permission.\n",
             pathname);

   printf("\nPress any key to continue...");
   getch();
}

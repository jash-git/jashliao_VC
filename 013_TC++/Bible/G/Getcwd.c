/*                         */
/* Program Name : getcwd.c */
/*                         */

#include <dir.h>
#include <stdio.h>
#include <conio.h>

void main()
{
   char pathname[MAXPATH];
   /* MAXPATH is a symbol constant defined in dir.h */

   clrscr();

   getcwd(pathname, MAXPATH);
   printf("Current directory is : %s\n", pathname);

   printf("\nPress any key to continue...");
   getch();
}

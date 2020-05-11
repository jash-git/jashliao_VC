/*                           */
/* Program Name : getcrdir.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dir.h>

#define CUR_DIR        0

void main()
{
   char curdir[MAXDIR];

   clrscr();

   if(getcurdir(CUR_DIR, curdir) == 0)
      printf("Current working directory is : %s\n", curdir);
   else
      printf("Error to get current working directory.\n");

   printf("\nPress any key to continue...");
   getch();
}

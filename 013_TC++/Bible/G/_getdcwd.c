/*                            */
/*  Program Name: _getdcwd.c  */
/*                            */
#include <stdio.h>
#include <conio.h>
#include <direct.h>

#define CUR_DIR  0

void main()
{
   char curdir[MAXDIR];

   clrscr();

   if(_getdcwd(CUR_DIR, curdir, MAXDIR) != NULL)
      printf("Current wording directory is : %s \n", curdir);
   else
      printf("Error to get current working directory.\n");

   printf("\nPress any key to continue...");
   getch();
}

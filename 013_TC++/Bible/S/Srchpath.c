/*                           */
/* Program Name : srchpath.c */
/*                           */

#include <dir.h>
#include <stdio.h>
#include <conio.h>

void main()
{
   char pathname[MAXPATH];
   /* MAXPATH is a symbol constant defined in dir.h */
   char *path;

   clrscr();
   printf("Please enter a file name:");
   gets(pathname);

   if ((path = searchpath(pathname)) != NULL)
      printf("File %s is found at path: %s\n", pathname, path);
   else
      printf("File %s is not found !\n", pathname);

   printf("\nPress any key to continue...");
   getch();
}

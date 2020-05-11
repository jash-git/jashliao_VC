/*                            */
/*  Program Name: _fulpath.c  */
/*                            */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
   char rel_path[_MAX_PATH], abs_path[_MAX_PATH];

   clrscr();
   printf("Enter a relative path to expand :\n=>");
   gets(rel_path);
   printf("After expanding...\n");

   if (_fullpath(abs_path, rel_path, _MAX_PATH) != NULL)
      printf("The full path of %s is :\n%s\n", rel_path, abs_path);
   else
      printf("Error to expand full path of %s\n", rel_path);

   printf("\nPress any key to continue...");
   getch();
}

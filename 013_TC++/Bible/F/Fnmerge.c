/*                          */
/* Program Name : fnmerge.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dir.h>

void main()
{
   char fullpath[MAXPATH];
   char drive[MAXDRIVE];
   char directory[MAXDIR];
   char filename[MAXFILE];
   char extension[MAXEXT];

   clrscr();
   printf("Please enter disc drive letter :\n=>");
   gets(drive);

   printf("Please enter directory path (end with '\\') :\n=>");
   gets(directory);

   printf("Please enter file name :\n=>");
   gets(filename);

   printf("Please enter file extension (begin with '.') :\n=>");
   gets(extension);

   fnmerge(fullpath, drive, directory, filename, extension);

   printf("The full path is :\n=> %s\n", fullpath);

   printf("Press any key to continue...");
   getch();
}

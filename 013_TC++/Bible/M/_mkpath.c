/* Program : _mkpath.c */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
   char fullpath[_MAX_PATH];
   char drive[_MAX_DRIVE];
   char directory[_MAX_DIR];
   char filename[_MAX_FNAME];
   char extension[_MAX_EXT];

   clrscr();
   printf("Please enter disc drive letter :\n=>");
   gets(drive);

   printf("Please enter directory path :\n=>");
   gets(directory);

   printf("Please enter file name :\n=>");
   gets(filename);

   printf("Please enter file extension :\n=>");
   gets(extension);

   fnmerge(fullpath, drive, directory, filename, extension);

   printf("The full path is :\n=> %s\n", fullpath);

   printf("\nPress any key to continue...");
   getch();
}

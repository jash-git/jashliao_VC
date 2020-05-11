/*                          */
/* Program Name : fnsplit.c */
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
   printf("Please enter a full path :\n=>");
   gets(fullpath);

   fnsplit(fullpath, drive, directory, filename, extension);

   printf("Disc drive     = %s\n", drive);
   printf("Directory      = %s\n", directory);
   printf("File name      = %s\n", filename);
   printf("File extension = %s\n", extension);

   printf("Press any key to continue...");
   getch();
}

/*                        */
/* Program Name : fstat.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <io.h>
#include <fcntl.h>

void main()
{
   struct stat statbuf;
   int handle;
   char filename[80];

   clrscr();
   printf("Please enter a file name : ");
   gets(filename);

   if ((handle = open(filename, O_RDONLY)) == -1) {
      printf("Error to open file '%s'\n", filename);
      exit(0);
   }

   printf("Get file information...\n");
   fstat(handle, &statbuf);

   printf("\nFile state :\n");
   if (statbuf.st_mode & S_IFCHR)
      printf("File is a character device.\n");

   if (statbuf.st_mode & S_IFREG)
      printf("File is a ordinary file.\n");

   if (statbuf.st_mode & S_IREAD)
      printf("File is readable.\n");

   if (statbuf.st_mode & S_IWRITE)
      printf("File is writable.\n");

   close(handle);
   printf("\nPress any key to continue...");
   getch();
}

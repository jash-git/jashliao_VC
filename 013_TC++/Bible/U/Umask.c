/*                        */
/* Program Name : umask.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <sys\stat.h>
#include <fcntl.h>

void main()
{
   int handle;
   struct stat statdata;

   clrscr();
   printf("Set subsequent files to be read-only...\n");
   umask(S_IWRITE);

   printf("Attempt to creat a file...\n");
   if ((handle = open(tmpnam(NULL), O_CREAT | O_WRONLY)) == -1) {
      printf("Error to creat file.\n");
      exit(0);
   }

   fstat(handle, &statdata);
   if (statdata.st_mode & S_IREAD)
      printf("File is writable.\n");
   else
      printf("File is not writable.\n");

   close(handle);
   printf("\nPress any key to continue...");
   getch();
}

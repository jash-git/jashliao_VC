/*                       */
/* Program Name : lock.c */
/*                       */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <share.h>
#include <errno.h>
#include <sys\stat.h>

void main()
{
   char filename[80];
   int  handle1, handle2;
   char buffer[10];

   clrscr();
   printf("Please enter a file name : ");
   gets(filename);

   handle1 = sopen(filename, O_RDONLY, SH_DENYNO, S_IREAD);
   if(handle1 == -1) {
      printf("Cannot open file '%s'.\n", filename);
      exit(0);
   }

   printf("Are you sure to lock it (y/n)?");
   if (tolower(getche()) == 'y') {
      if (lock(handle1, 0, filelength(handle1)) == -1) {
         printf("\n\nError occured.\n");
         printf("Failed to lock file '%s'.\n", filename);
      }
      else
          printf("\n\nFile '%s' is successfully locked.\n",
                 filename);
   }
   else
      printf("\n\nFile %s is not locked.\n", filename);

   printf("Reopen file '%s'...\n", filename);
   handle2 = sopen(filename, O_RDONLY, SH_DENYNO, S_IREAD);
   if (handle2 == -1)
      printf("Error to open file '%s'.\n");

   printf("Read data using reopening file handle...\n");
   if (read(handle2, buffer, 10) == -1) {
      printf("\nError occured!\n");
      switch(errno) {
         case EACCES: printf("Permission denied.\n");
                       break;
         case EBADF : printf("Bad file number.\n");
                       break;
         default    : printf("Error No = %d\n", errno);
      }
   }
   else
      printf("Read access is Ok.\n");

   close(handle1);
   close(handle2);
   printf("\nPress any key to continue...");
   getch();
}

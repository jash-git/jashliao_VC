/*                         */
/* Program Name : chsize.c */
/*                         */

#include <io.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
   int handle;
   char *msg = "This is a test.";
   char filename[40] = "\\";

   clrscr();
   printf("Creat a temporary file...\n");
   if ((handle = creattemp(filename, 0)) == -1) {
      printf("Error to creat file.\n");
      exit(0);
   }

   printf("The temporary file name is %s\n", filename);
   printf("Write '%s' to the file...\n", msg);
   write(handle, msg, strlen(msg));
   printf("Current file size is %d\n", filelength(handle));
   printf("Truncate the file into 0 byte...\n");
   chsize(handle, 0);
   printf("After truncating...\n");
   printf("Current file size is %d\n", filelength(handle));
   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

/*                       */
/* Program Name : open.c */
/*                       */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <io.h>

void main()
{
   int  handle;
   int  length;
   char tmpname[40];
   char *msg = "This is a test.";

   /* Get a temporary file name */
   tmpnam(tmpname);

   clrscr();
   /* Creat a file with filname got from tmpname */
   printf("Creat temporary file '%s'...\n", tmpname);
   if ((handle = open(tmpname, O_CREAT | O_TEXT)) == -1 ) {
      printf("Cannot creat temporary file '%s'.\n", tmpname);
      exit(0);
   }

   printf("Write a message '%s' to %s...\n", msg, tmpname);
   length = strlen(msg) + 1; /* includes '\0' */
   write(handle, msg, length);
   printf("Close temporary file %s\n", tmpname);
   close(handle);

   printf("Reopen file %s...\n", tmpname);
   handle = open(tmpname, O_RDONLY | O_TEXT);
   printf("Read the message from %s...\n", tmpname);
   read(handle, msg, length);
   printf("The message written to %s is :%s\n", tmpname, msg);

   printf("Close file %s\n", tmpname);
   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

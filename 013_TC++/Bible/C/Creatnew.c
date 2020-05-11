/*                           */
/* Program Name : creatnew.c */
/*                           */

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <fcntl.h>
#include <conio.h>

void main()
{
   int    handle;
   int    length;
   char   msg[20] = "This is a test.";

   clrscr();
   if ((handle = creatnew("test", 0)) == -1) {
      printf("File 'test' already exists.\n");
      exit(0);
   }

   printf("Write a string '%s' to the file 'test'...\n", msg);
   length = strlen(msg) + 1;
   write(handle, msg, length);
   printf("Close file...\n");
   close(handle);

   printf("Reopen file 'test'...\n");
   handle = open("test", O_RDONLY | O_BINARY);
   read(handle, msg, length);
   printf("The string written to file is '%s'\n", msg);
   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

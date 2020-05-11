/*                          */
/* Program Name : setmode.c */
/*                          */

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fcntl.h>
#include <string.h>

void main()
{
   int handle;
   int length;
   int i;

   char *msg = "This is a test.\n\n";

   clrscr();

   printf("Create file 'test' at text mode...\n");
   handle = open("test", O_CREAT | O_RDWR | O_TEXT);
   printf("Switch to binary mode...\n");
   if (setmode(handle, O_BINARY) == -1) {
      printf("Error : Invalid argument.\n");
      exit(0);
   }

   length = strlen(msg);
   write(handle, msg, length);

   lseek(handle, SEEK_SET, 0);
   read(handle, msg, length);

   printf("The content of the file 'test' :\n");

   printf("Hexadecimal mode : ");
   for (i = 0; i < length; i++)
      printf(" %02X", msg[i]);

   printf("\nCharacter mode   : ");
   for (i = 0; i < length; i++)
      printf("%03c", msg[i]);

   close(handle);
   printf("\nPress any key to continue...");
   getch();
}

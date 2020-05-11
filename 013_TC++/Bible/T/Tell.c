/*                       */
/* Program Name : tell.c */
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
   char *msg = "This is a test.";

   clrscr();
   if ((handle = open("test", O_CREAT | O_WRONLY | O_APPEND)) == -1) {
      printf("Cannot create file 'test'\n'");
      exit(0);
   }

   printf("Write message  'This is a test.' to file...\n");
   write(handle, msg, strlen(msg));
   printf("The file pointer is at byte %ld\n", tell(handle));
   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

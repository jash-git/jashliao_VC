/*                           */
/* Program Name : _d_crtnw.c */
/*                           */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <fcntl.h>

void main()
{
   int      handle;
   int      length;
   char     msg[20] = "This is a test.";
   unsigned count;

   clrscr();
   if (_dos_creatnew("test", _A_NORMAL, &handle) != 0) {
      printf("Error : File 'test' already exists.\n");
      exit(0);
   }

   printf("Write a string '%s' to the file 'test'...\n", msg);
   length = strlen(msg) + 1;
   _dos_write(handle, msg, length, &count);
   printf("Total %d bytes are written.\n", count);
   printf("Close file...\n");
   _dos_close(handle);

   printf("\nPress any key to continue...");
   getch();
}

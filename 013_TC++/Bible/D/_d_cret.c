/*                          */
/* Program Name : _d_cret.c */
/*                          */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <io.h>

void main()
{
   int      handle;
   int      length;
   unsigned nwritten;
   char     msg[20] = "This is a test.";

   clrscr();
   if (_dos_creat("test", _A_NORMAL, &handle) != 0) {
      printf("File create failure.\n");
      exit(0);
   }

   printf("Write a string '%s' to the file 'test'...\n", msg);
   length = strlen(msg) + 1;
   _dos_write(handle, msg, length, &nwritten);
   printf("Close file...\n");
   _dos_close(handle);

   printf("Reopen file 'test'...\n");
   handle = _open("test", FA_RDONLY);
   _read(handle, msg, length);
   printf("The string written to file is '%s'\n", msg);
   _close(handle);

   printf("\nPress any key to continue...");
   getch();
}

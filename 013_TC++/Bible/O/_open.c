/*                        */
/* Program Name : _open.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>

void main()
{
   int  handle;
   int  i, j;
   unsigned char buffer[256];

   clrscr();
   if ((handle = _open("_open.c", O_RDONLY)) == -1) {
      printf("Cannot read from file _open.c\n");
      exit(0);
   }

   printf("Read first 256 bytes of data...\n");
   _read(handle, buffer, 256);

   printf("Contents of _open.c (first 256 bytes) :\n\n");

   for (i = 0, j = 0; i < 256; i++) {
      printf("%02X ", buffer[i]);
      if (i % 16 == 15) {
         printf("   ");
         for (; j <= i; j++)
            printf("%c", (buffer[j] < 32) ? '.' : buffer[j]);
         putchar('\n');
      }
   }

   _close(handle);

   printf("\nPress any key to continue...");
   getch();
}

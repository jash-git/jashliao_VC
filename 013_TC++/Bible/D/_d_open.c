/*                          */
/* Program Name : _d_open.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dos.h>

void main()
{
   int  handle;
   int  i, j;
   unsigned nread;
   unsigned char buffer[256];

   clrscr();
   if (_dos_open("_d_open.c", O_RDONLY, &handle) != 0) {
      printf("Cannot read from file _d_open.c\n");
      exit(0);
   }

   printf("Read first 256 bytes of data...\n");
   _dos_read(handle, buffer, 256, &nread);

   printf("Total %d bytes are read.\n", nread);
   printf("Contents of _d_open.c (first 256 bytes) :\n\n");

   for (i = 0, j = 0; i < 256; i++) {
      printf("%02X ", buffer[i]);
      if (i % 16 == 15) {
         printf("   ");
         for (; j <= i; j++)
            printf("%c", (buffer[j] < 32) ? '.' : buffer[j]);
         putchar('\n');
      }
   }

   _dos_close(handle);

   printf("\nPress any key to continue...");
   getch();
}

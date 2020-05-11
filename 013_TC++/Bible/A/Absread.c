/*                          */
/* Program Name : absread.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   unsigned char buffer[512];
   int  i, j;
   int  drive;
   int  lsector;
   int  result;

   clrscr();
   printf("Please enter disc drive :");
   drive = tolower(getche()) - 'a';

   printf("\nPlease enter logical sector number to read :");
   scanf("%d", &lsector);
   printf("\nContens of logical sector %d:\n\n", lsector);
   if (absread(drive, 1, lsector, buffer) == -1) {
      printf("Error occured!\n");
      switch(_AX) {
         case 0x01 : printf("Bad command.\n");
                     break;
         case 0x02 : printf("Bad address mark.\n");
                     break;
         case 0x03 : printf("Disc write protected.\n");
                     break;
         case 0x04 : printf("Requested sector was found.\n");
                     break;
         case 0x08 : printf("Failed during DMA.\n");
                     break;
         case 0x10 : printf("Data error detected via CRC.\n");
                     break;
         case 0x20 : printf("Disc controller failed.\n");
                     break;
         case 0x40 : printf("Seek operation on drive failed.\n");
                     break;
         case 0x80 : printf("Disc drive failed to respond.\n");
      }
   }
   else {
      for (i = 0, j = 0; i < 512; i++) {
         printf("%02X ", buffer[i]);
         if (i % 16 == 15) {
            printf("   ");
            for (; j <= i; j++)
               printf("%c", (buffer[j] < 32) ? '.' : buffer[j]);
            putchar('\n');
         }
      }
   }

   printf("\nPress any key to continue...");
   getch();
}

/*                           */
/* Program Name : abswrite.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void print_error_msg()
{
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
                   break;
       default   : printf("Error No = 0x%02X\n", _AX);
    }
}

void main()
{
   unsigned char buffer[512];
   int  i, j;
   int  drive;
   int  lsector;
   int  result;

   clrscr();
   printf("Please insert a floppy into drive A:");
   getch();
   printf("\nRead the first sector in drive A:...\n");
   if (absread(0, 1, 0, buffer) == -1)
      print_error_msg();
   else {
      buffer[3] = 'B';
      buffer[4] = 'L';
      buffer[5] = 'D';
      printf("Write the updated sector to sector 0...\n");
      if (abswrite(0, 1, 0, buffer) == -1)
	 print_error_msg();
      else {
	 printf("Read from sector 0 again...\n");
	 absread(0, 1, 0, buffer);
	 printf("Contents of sector 0 (after modification):\n\n");
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
   }

   printf("\nPress any key to continue...");
   getch();
}

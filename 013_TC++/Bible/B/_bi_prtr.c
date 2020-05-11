/*                           */
/* Program Name : _bi_prtr.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <bios.h>

#define  LPT1              0

#define  TIME_OUT       0x01
#define  IO_ERR         0x08
#define  SELECTED       0x10
#define  OUT_OF_PAPER   0x20
#define  ACKNOWLEDGE    0x40
#define  NOT_BUSY       0x80

void main()
{
   int status;

   clrscr();
   printf("Get printer status...\n\n");
   status = _bios_printer(2, LPT1, 0);

   printf("Printer status:\n");
   if (status & TIME_OUT)
      printf("Device time out.\n");

   if (status & IO_ERR)
      printf("I/O error.\n");

   if (status & SELECTED)
      printf("Printer is selected for output.\n");

   if (status & OUT_OF_PAPER)
      printf("Out of paper.\n");

   if (status & ACKNOWLEDGE)
      printf("Acknowledgment from printer.\n");

   if (status & NOT_BUSY)
      printf("Printer is not busy.\n");

   printf("\nPress any key to continue...");
   getch();
}

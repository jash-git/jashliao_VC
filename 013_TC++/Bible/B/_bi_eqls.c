/*                           */
/* Program Name : _bi_eqls.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <bios.h>

void main()
{
   int  eq;

   struct bit_field{
      unsigned int boot        : 1;
      unsigned int coprocessor : 1;
      unsigned int RAMs        : 2;
      unsigned int videomode   : 2;
      unsigned int floppies    : 2;
      unsigned int DMAs        : 1;
      unsigned int COMports    : 3;
      unsigned int gameio      : 1;
      unsigned int serial_lpt  : 1;
      unsigned int printers    : 2;
   } *eqptr;

   clrscr();
   printf("Get equipment information...\n");
   eq = _bios_equiplist();
   eqptr = (struct bit_field *) &eq;

   printf("\nEquipment information :\n");
   printf("parallel printers installed : %d.\n", eqptr->printers);
   printf("Serial printer attached     : %s.\n",
          (eqptr->serial_lpt == 1) ? "Yes" : "No");
   printf("Game I/O attached           : %s.\n",
          (eqptr->gameio == 1) ? "Yes" : "No");
   printf("Number of COM ports         : %d.\n", eqptr->COMports);
   printf("Direct memory access (DMA)  : Machine %s DMA.\n",
          (eqptr->DMAs == 1) ? "has" : "doesn't have");
   printf("Number of floppies          : %d.\n", eqptr->floppies + 1);
   printf("Initial video mode          : ");
   switch(eqptr->videomode) {
      case 0 : printf("Unused\n");
               break;
      case 1 : printf("40x25 BW with color card.\n");
               break;
      case 2 : printf("80x25 BW with color card.\n");
               break;
      case 3 : printf("80x25 BW with monochrome card.\n");
               break;
   }
   printf("Motherboard RAM size        : %dK.\n", (eqptr->RAMs + 1) * 16);
   printf("Floating-point copressor    : %s.\n",
          (eqptr->coprocessor == 1) ? "Present" : "Not present");
   printf("Boot from disc              : %s.\n",
          (eqptr->boot == 1) ? "Yes" : "No");

   printf("\nPress any key to continue...");
   getch();
}

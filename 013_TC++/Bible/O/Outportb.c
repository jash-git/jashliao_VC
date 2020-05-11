/*                           */
/* Program Name : outportb.c */
/*                           */

#include <dos.h>
#include <stdio.h>
#include <conio.h>

#define  PORT_8255_0x61 0x61

void main()
{
   int i;
   unsigned char ch;

   clrscr();

   printf("Now you can hear a voice from the speaker...\n");
   /* Read register 0x61 into ch */
   ch = inportb(PORT_8255_0x61);
   /* Clear the last 2 bit of ch into 00 */
   ch &= 0xFC;
   for (i = 0; i < 1000; i++) {
      ch ^= 0x02; /* Switch the 7th bit */
      /* Send the data into register 0x61 */
      outportb(PORT_8255_0x61, ch);
      delay(10);
   }

   printf("\nPress any key to continue...");
   getch();
}

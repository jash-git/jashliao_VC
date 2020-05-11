/*                           */
/* Program Name : _bi_scom.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <bios.h>

#define  COMPORT         0  /* COM port 1  */
#define  SPEED        0xA0  /* 2400 baud   */
#define  DATA         0x03  /* 8 data bits */
#define  STOP         0x04  /* 2 stop bits */
#define  PARITY       0x18  /* Even parity */

void main()
{
   int ch;
   int in, out;
   int status;
   int quit = 0;

   clrscr();
   printf("Initializing COM port 1...");
   _bios_serialcom(_COM_INIT, COMPORT, SPEED | DATA | STOP | PARITY);
   printf("\nStart operating...\nIf you want to quit, press ESC key...\n");

   while (!quit) {
      status = _bios_serialcom(_COM_STATUS, COMPORT, 0);
      if (status & 0x0100)
         if ((out = _bios_serialcom(_COM_RECEIVE, COMPORT, 0)) != 0)
            putchar(out);
      if (kbhit()) {
         if ((in = getche()) == 0x1B)
            quit = 1;
         _bios_serialcom(_COM_SEND, COMPORT, in);
      }
   }
}

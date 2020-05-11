/*                          */
/* Program Name : bioscom.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <bios.h>

#define  SET          0x00
#define  SEND         0x01
#define  RECEIVE      0x02
#define  STATUS       0x03

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
   bioscom(SET, SPEED | DATA | STOP | PARITY, COMPORT);
   printf("\nStart operating...\nIf you want to quit, press ESC key...\n");

   while (!quit) {
      status = bioscom(STATUS, 0, COMPORT);
      if (status & 0x0100)
         if ((out = bioscom(RECEIVE, 0, COMPORT)) != 0)
            putchar(out);
      if (kbhit()) {
         if ((in = getche()) == 0x1B)
            quit = 1;
         bioscom(SEND, in, COMPORT);
      }
   }
}

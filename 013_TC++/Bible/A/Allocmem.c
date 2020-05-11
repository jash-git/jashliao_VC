/*                           */
/* Program Name : allocmem.c */
/*                           */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

#define  SCR_SEGMENT   0xB800    /* for color card only */

void main()
{
   int i;
   unsigned scr_buffer;

   clrscr();
   randomize();

   if (allocmem(256, &scr_buffer) != -1) {
      printf("Cannot allocate required memory!\n");
      exit(0);
   }

   /* show 1920 random characters on the screen. */
   for (i = 0; i < 1920; i++)
      putchar(random(26) + 'a');

   /* Move current screen to buffer starts at
      segment scr_buffer */
   movedata(SCR_SEGMENT, 0, scr_buffer, 0, 4000);
   getch();
   clrscr();
   getch();

   /* Restore the screen... */
   movedata(scr_buffer, 0, SCR_SEGMENT, 0, 4000);

   freemem(scr_buffer);

   gotoxy(1, 24);
   printf("\nPress any key to continue...");
   getch();
}

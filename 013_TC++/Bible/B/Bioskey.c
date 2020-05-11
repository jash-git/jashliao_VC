/*                          */
/* Program Name : bioskey.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <bios.h>

#define INSERT    0x80
#define CAPS      0x40
#define NUM       0x20
#define SCROLL    0x10
#define ALT       0x08
#define CTRL      0x04
#define L_SHIFT   0x02
#define R_SHIFT   0x01

void main()
{
   int last_status = -1; /* Initialize with a not meaningful value */
   int status;

   clrscr();
   printf("Press following keys, otherwise press ESC key to stop...\n\n");
   printf("Insert  Caps  Num   Scroll  Alt  Ctrl  Left   Right\n");
   printf("              Lock  Lock               Shift  Shift\n");
   printf("======  ====  ====  ======  ===  ====  =====  =====\n");

   while ((bioskey(1) & 0x00FF) != 0x1B) {
      if (bioskey(1) != 0) {
         /* There is a character in keyboard buffer */
         bioskey(0); /* Eat that character */
      }
      status = bioskey(2);
      if (last_status != status) {
         gotoxy(1, 6);
         cprintf("%s  %s  %s  %s  %s  %s  %s  %s",
                 (status & INSERT)  ? "лллллл" : "      ",
                 (status & CAPS)    ? "лллл"   : "    ",
                 (status & NUM)     ? "лллл"   : "    ",
                 (status & SCROLL)  ? "лллллл" : "      ",
                 (status & ALT)     ? "ллл"    : "   ",
                 (status & CTRL)    ? "лллл"   : "    ",
                 (status & L_SHIFT) ? "ллллл"  : "     ",
                 (status & R_SHIFT) ? "ллллл"  : "     ");
         last_status = status;
      }
   }

   printf("\n\nPress any key to continue...");
   getch();
}

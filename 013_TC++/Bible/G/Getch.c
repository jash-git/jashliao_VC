/*                        */
/* Program Name : getch.c */
/*                        */

#include <conio.h>

#define  ESC 0x1B

void main()
{
   char ch = '\0';

   clrscr();
   printf("Press any key to get keyboard scanning code:\n");
   printf("Press ESC key to quit.\n");

   while (ch != ESC) {
      switch(ch = getch()) {
         case 0  : printf("Extended key   : %d;%d\n", ch, getch());
                   break;
         default : printf("Key %c : %d\n", ch, ch);
      }
   }

   printf("Quit program.\n");

   printf("\nPress any key to continue...");
   getch();
}

/*                          */
/* Program Name : getchar.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   char msg[81];
   int  ch;
   int  i;

   printf("Please enter a line :\n");
   for (i = 0; i < 80 && (ch = getchar()) != '\n'; i++)
      msg[i] = ch;

   msg[i] = '\0';
   printf("The line you entered is : %s\n", msg);
   printf("\nPress any key to continue...");
   getch();
}

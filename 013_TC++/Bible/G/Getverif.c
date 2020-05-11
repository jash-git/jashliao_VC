/*                           */
/* Program Name : getverif.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   clrscr();

   printf("Current DOS verify flag is : %s\n",
           getverify() == 1 ? "on" : "off");
   printf("\nPress any key to continue...");
   getch();
}

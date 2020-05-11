/* Program : getswchr.c */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   clrscr();
   printf("Current DOS switch character is : %c\n", getswitchar());

   printf("\nPress any key to continue...");
   getch();
}


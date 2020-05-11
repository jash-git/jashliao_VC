
/*                          */
/* Program Name : setcbrk.c */
/*                          */

#include <dos.h>
#include <conio.h>
#include <stdio.h>

void main()
{
   int break_flag;

   clrscr();
   printf("Enter 0 to turn Control-Break off\n");
   printf("Enter 1 to turn Control-Break on\n");

   break_flag = getch() - 0;

   setcbrk(break_flag);

   if (getcbrk())
      printf("Control-Break flag is on\n");
   else
      printf("Control-Break flag is off\n");
} /* main() */

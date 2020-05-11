
/*                           */
/* Program Name : setverif.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   int verify_flag;
   char ch;

   clrscr();
   printf("Enter 0 to set verify flag off\n");
   printf("Enter 1 to set verify flag on\n");
   ch = getch();
   switch( ch) {
     case '0':
     case '1':
       setverify(verify_flag);
       break;
     default:
       puts("Input error !");
       return;
   }

   if (getverify())
      printf("Write disk verify flag is on\n");
   else
      printf("Write disk verify flag is off\n");
} /* main() */

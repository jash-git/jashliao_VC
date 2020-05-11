/*                         */
/* Program Name : printf.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   char  *msg = "This is a test.";
   int   i = 100;
   float f = 3.1415926;

   clrscr();
   printf("msg = %s\n", msg);
   printf("Address of msg : %Fp\n", msg);
   printf("The first character of msg is : %c\n", msg[0]);

   printf("i = %3d  (in decimal)\n", i);
   printf("i = %3o  (in octal)\n", i);
   printf("i = %3x  (in hexadecimal)\n", i);

   printf("f = %-11f (in the floating point format)\n", f);
   printf("f = %-11e (in the scientific format)\n", f);

   printf("\nPress any key to continue...");
   getch();
}

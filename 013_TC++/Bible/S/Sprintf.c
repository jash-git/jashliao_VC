/*                          */
/* Program Name : sprintf.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   char buffer[80];

   sprintf(buffer, "The number %d in hexadecimal is %#x\n", 100, 100);
   puts(buffer);

   printf("\nPress any key to continue...");
   getch();
}

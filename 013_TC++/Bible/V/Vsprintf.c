/*                           */
/* Program Name : vsprintf.c */
/*                           */

#include <stdio.h>
#include <conio.h>

int myvsprintf(char *format, ...)
{
   va_list arglist;
   int     numbers;
   char    buffer[100];

   va_start(arglist, format);
   numbers = vsprintf(buffer, format, arglist);
   va_end(arglist);

   puts(buffer);

   return numbers;
}

void main()
{
   char buffer[80];

   clrscr();
   myvsprintf("The number %d in hexadecimal is %#x.\n",
              100, 100);
   printf("\nPress any key to continue...");
   getch();
}

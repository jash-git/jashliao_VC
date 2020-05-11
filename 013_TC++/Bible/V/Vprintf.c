/*                          */
/* Program Name : vprintf.c */
/*                          */

#include <stdio.h>
#include <stdarg.h>
#include <conio.h>

int myvprintf(char *format, ...)
{
   va_list arglist;
   int     numbers;

   va_start(arglist, format);
   numbers = vprintf(format, arglist);
   va_end(arglist);

   return numbers;
}

void main()
{
   int   i    = 200;
   char  ch   = 'A';
   float f    = 3.1415;
   char  *str = "This is a test.";
   char buffer[81];

   clrscr();

   printf("write '%d', '%c', '%f', and '%s' to stdout...\n",
          i, ch, f, str);
   myvprintf("%d, %c, %f, %s", i, ch, f, str);

   printf("\nPress any key to continue...");
   getch();
}

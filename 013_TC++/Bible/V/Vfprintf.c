/*                           */
/* Program Name : vfprintf.c */
/*                           */

#include <stdio.h>
#include <conio.h>

int myfprintf(FILE *fptr, char *format, ...)
{
   va_list arglist;
   int     numbers;

   va_start(arglist, format);
   numbers = vfprintf(fptr, format, arglist);
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
   myfprintf(stdout, "%d, %c, %f, %s", i, ch, f, str);

   printf("\nPress any key to continue...");
   getch();
}

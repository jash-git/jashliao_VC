/*                          */
/* Program Name : bdosptr.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dos.h>

#define CHAR_OUT    0x02
#define STR_OUT     0x09

int my_puts(char *str)
{
   int result;

   /* We won't change the value in AL */
   result = bdosptr(STR_OUT, str, _AL);
   bdos(CHAR_OUT, '\n', _AL);
   bdos(CHAR_OUT, '\r', _AL);

   if (result == -1)
      return EOF;
   else
      return result = str[strlen(str) - 1];
}

void main()
{
   clrscr();
   my_puts("This message must be on the screen!$");

   printf("\nPress any key to continue...");
   getch();
}

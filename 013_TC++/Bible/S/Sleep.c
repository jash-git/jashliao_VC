
/*                        */
/* Program Name : sleep.c */
/*                        */

#include <dos.h>
#include <conio.h>
#include <stdio.h>

void main()
{
   int i, j;

   clrscr();
   for (i=1; i <= 5; i++)
   {
      printf("Sleeping for %d seconds", i);
      for (j = 0; j < i; j++)
        putchar('.');
      putchar('\n');
      sleep(i);
   }
} /* main() */

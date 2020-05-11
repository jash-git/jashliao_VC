/*                         */
/* Program Name : vscanf.c */
/*                         */

#include <stdio.h>
#include <stdarg.h>
#include <conio.h>

int myvscanf(char *format, ...)
{
   va_list arglist;
   int     numbers;

   va_start(arglist, format);
   numbers = vscanf(format, arglist);
   va_end(arglist);

   return numbers;
}

void main()
{
   int   number;
   char  name[20];
   float score;
   char  junk[10];

   clrscr();

   printf("Please enter number, name, and score (seperated"
          " by space character) :\n=>");

   myvscanf("%d %20s %f", &number, name, &score);
   gets(junk); /* Eats all junks in the keyboard buffer */

   printf("The number, name, and score you entered are :\n");

   printf("\tNumber: %d\n\tName  : %s\n\tScore : %f\n",
          number, name, score);

   printf("\nPress any key to continue...");
   getch();
}

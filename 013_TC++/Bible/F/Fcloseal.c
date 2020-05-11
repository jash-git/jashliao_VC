/*                            */
/* Program Name : fcloseall.c */
/*                            */

#include <stdio.h>
#include <conio.h>

void main()
{
   int  streams_closed;
   FILE *fptr0, *fptr1, *fptr2;

   clrscr();
   if ((fptr0 = tmpfile()) != NULL)
      printf("Temporary file 0 is opened.\n");

   if ((fptr1 = tmpfile()) != NULL)
      printf("Temporary file 1 is opened.\n");

   if ((fptr2 = tmpfile()) != NULL)
      printf("Temporary file 2 is opened.\n");

   /* Close all streams */
   streams_closed = fcloseall();

   if (streams_closed == EOF)
      printf("\nStream close error.\n");
   else  /* Print the number of streams been closed */
      printf("\n%d streams are closed.\n", streams_closed);

   printf("\nPress any key to continue...");
   getch();
}

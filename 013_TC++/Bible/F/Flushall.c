/*                           */
/* Program Name : flushall.c */
/*                           */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *fptr;

   /* Open a file */
   printf("Open a file 'flushall.c'...\n");
   fptr = fopen("flushall.c", "rt");

   /* Flush all streams */
   printf("%d streams are flushed.\n", flushall());

   fclose(fptr);

   printf("\nPress any key to continue...");
   getch();
}

/*                         */
/* Program Name : fflush.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *fptr;
   int  result;

   fptr = fopen("test", "w");

   clrscr();
   printf("Write message 'This is a test.' to file...\n");
   fputs("This is a test.", fptr);

   printf("Flush the data to file 'test'....\n");
   result = fflush(fptr);

   if (result == 0)
      printf("File was successfully flushed.\n");
   else
      printf("Failed to flush the file.\n");

   fclose(fptr);

   printf("\nPress any key to continue...");
   getch();
}

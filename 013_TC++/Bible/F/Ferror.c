/*                         */
/* Program Name : ferror.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *fptr;

   fptr = fopen("test", "w");

   /* force to occur an error condition */
   getc(fptr);

   clrscr();
   if (ferror(fptr) != 0) {
      /* Display an error message */
      printf("Error to read from file 'test'\n");

      /* Cleear error state */
      clearerr(fptr);
   }

   fclose(fptr);

   printf("\nPress any key to continue...");
   getch();
}

/*                         */
/* Program Name : fclose.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *fptr;
   char buffer[81];

   if ((fptr = fopen("fclose.c", "rt")) == NULL) {
      printf("File open failure.\n");
      exit(0);
   }

   clrscr();
   printf("=== Top of File ===\n");
   while(fgets(buffer, 80, fptr) != NULL)
      printf(buffer);

   fclose(fptr);
   printf("\n\n=== File is closed. ===\n");
   printf("\nPress any key to continue...");
   getch();
}

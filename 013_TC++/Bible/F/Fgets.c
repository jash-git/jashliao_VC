/*                        */
/* Program Name : fgets.c */
/*                        */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *fptr;
   char buffer[81];

   if ((fptr = fopen("fgets.c", "rt")) == NULL) {
      printf("File open failure.\n");
      exit(0);
   }

   printf("Content of the file fgets.c ===\n");
   while(fgets(buffer, 81, fptr) != NULL)
      printf(buffer);

   fclose(fptr);
   printf("\n=== End of File ===\n");

   printf("\nPress any key to continue...");
   getch();
}

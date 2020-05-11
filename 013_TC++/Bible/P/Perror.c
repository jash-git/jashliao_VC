/*                         */
/* Program Name : perror.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   char filename[11];
   FILE *fptr;

   clrscr();
   tmpnam(filename);
   printf("Attempting to open '%s'...\n", filename);

   if ((fptr = fopen(filename, "rt")) == NULL)
      perror("Error to open the specified file.\n");
   else {
      printf("File open is successful.\n");
      fclose(fptr);
   }

   printf("\nPress any key to continue...");
   getch();
}

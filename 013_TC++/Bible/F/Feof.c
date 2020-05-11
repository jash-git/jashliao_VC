/*                       */
/* Program Name : feof.c */
/*                       */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *fptr;
   char buffer[81];

   clrscr();
   if ((fptr = fopen("feof.c", "rt")) == NULL) {
      printf("Cannot open feof.c\n");
      exit(0);
   }

   printf("=== Top of File ===\n");
   while(fgets(buffer, 80, fptr))
      printf(buffer);

   if (feof(fptr) != 0)
      printf("\n=== End of File ===\n");
   else
      printf("\nFailed to read file.\n");

   printf("\nPress any key to continue...");
   getch();
}

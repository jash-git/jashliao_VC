/*                         */
/* Program Name : fopen0.c */
/*                         */

#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
   FILE *infile, *outfile;
   char buffer[81];

   clrscr();

   if ((infile = fopen("fopen0.c", "rt")) == NULL) {
      printf("File 'fopen0.c' open failure.\n");
      exit(0);
   }

   if ((outfile = fopen("fopen0.bak", "wt")) == NULL) {
      printf("Cannot create 'fopen0.bak'.\n");
      exit(0);
   }

   printf("\nCopying file fopen0.c to fopen0.bak......\n");
   while(fgets(buffer, 81, infile) != NULL)
      fputs(buffer, outfile);

   fclose(infile);
   fclose(outfile);

   printf("\nCompleted.\n");

   printf("\nPress any key to continue...");
   getch();
}

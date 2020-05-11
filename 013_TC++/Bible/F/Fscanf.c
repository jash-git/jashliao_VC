/*                         */
/* Program Name : fscanf.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *infile;
   char token[81];

   clrscr();


   if ((infile = fopen("fscanf.c", "rt")) == NULL) {
      printf("Cannot open file 'fscanf.c'.\n");
      exit(0);
   }

   printf("All tokens in the file 'fscanf.c' are:\n");

   while (fscanf(infile, "%s", token) != EOF)
      printf("%-20s", token);

   fclose(infile);
   printf("\nPress any key to continue...");
   getch();
}

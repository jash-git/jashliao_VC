/*                          */
/* Program Name : freopen.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *infile;
   char buffer[81];

   clrscr();

   /* Redirect standard printer to a file */
   if (freopen("printer.out", "wt", stdprn) == NULL) {
      fprintf(stderr, "Error to redirecting stdprn.\n");
      exit(0);
   }

   printf("Write message 'This is a test to printer...\\n' to stdprn...\n");
   /* This message will go to a file. */
   fprintf(stdprn, "This is a test to printer...\n");

   /* Close the standard printer stream */
   fclose(stdprn);

   /* Get the message written to printer in the file */
   infile = fopen("printer.out", "rt");
   fgets(buffer, 81, infile);

   printf("The message you wrote to print is :\n");
   printf(buffer);

   printf("\nPress any key to continue...");
   getch();
}

/*                          */
/* Program Name : fprintf.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE  *infile, *outfile;
   int   i    = 200;
   char  ch   = 'A';
   float f    = 3.1415;
   char  *str = "This is a test.";
   char buffer[81];

   clrscr();
   if ((outfile = fopen("test", "wt")) == NULL) {
      printf("File create failure.\n");
      exit(0);
   }

   printf("write '%d', '%c', '%f', and '%s' to file 'test'...\n",
          i, ch, f, str);
   fprintf(outfile, "%d, %c, %f, %s", i, ch, f, str);
   printf("Close file 'test'.\n");
   fclose(outfile);

   printf("Reopen file 'test' for reading...\n");
   infile = fopen("test", "rt");
   printf("The results of last writing...\n");
   fgets(buffer, 81, infile);
   puts(buffer);
   fclose(infile);

   printf("\nPress any key to continue...");
   getch();
}

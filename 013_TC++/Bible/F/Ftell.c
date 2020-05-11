/*                        */
/* Program Name : ftell.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
   FILE *outfile;

   clrscr();
   if ((outfile = fopen("test", "wt")) == NULL) {
      printf("Cannot create file 'test'\n'");
      exit(0);
   }

   printf("Write message  'This is a test.' to file...\n");
   fprintf(outfile, "This is a test.");
   printf("The file pointer is at byte %ld\n", ftell(outfile));
   fclose(outfile);

   printf("\nPress any key to continue...");
   getch();
}

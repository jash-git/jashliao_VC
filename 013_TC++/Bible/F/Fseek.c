/*                        */
/* Program Name : fseek.c */
/*                        */

#include <stdio.h>
#include <conio.h>

long filesize(char *filename);


void main()
{
   printf("The size of file %s is %ld\n", "fseek.c", filesize("fseek.c"));

   printf("\nPress any key to continue...");
   getch();
}

long filesize(char *filename)
{
   FILE *infile;
   long length;

   if ((infile = fopen(filename, "rb")) == NULL) {
      printf("File %s doesn't exist.\n", filename);
      exit(0);
   }

   /* Move file indicator to the end of the file */
   fseek(infile, 0L, SEEK_END);

   /* get the length of the file */
   length = ftell(infile);

   return length;
}

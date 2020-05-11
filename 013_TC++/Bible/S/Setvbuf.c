/*                          */
/* Program Name : setvbuf.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *infile;
   char buffer[65];

   clrscr();
   if ((infile = fopen("setvbuf.c", "rt")) == NULL) {
      printf("Cannot open file 'setvbuf.c'.\n");
      exit(0);
   }

   if (setvbuf(infile, buffer, _IOFBF, 64) != 0) {
      printf("Error to set buffer.\n");
      fclose(infile);
      exit(0);
   };

   printf("Reading a character from file 'setvbuf.c'...\n");
   getc(infile);
   printf("The content of the buffer : \n");
   buffer[64] = '\0';
   puts(buffer);

   fclose(infile);
   printf("\nPress any key to continue...");
   getch();
}

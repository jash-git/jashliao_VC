/*                         */
/* Program Name : setbuf.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *infile;
   char buffer[BUFSIZ+1];

   clrscr();

   if ((infile = fopen("setbuf.c", "rt")) == NULL) {
      printf("Cannot open file 'setbuf.c'.\n");
      exit(0);
   }

   setbuf(infile, buffer);
   printf("Reading a character from file 'setbuf.c'...\n");
   getc(infile);
   buffer[BUFSIZ] = '\0';

   printf("The content of the buffer : \n");
   printf(buffer);

   fclose(infile);

   printf("\nPress any key to continue...");
   getch();
}

/*                         */
/* Program Name : fopen1.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *infile;
   char buffer[17];
   int  length;
   int  i;

   if ((infile = fopen("fopen1.c", "rb")) == NULL) {
      printf("Cannot not open file 'fopen.c'.\n");
      exit(0);
   }

   clrscr();
   while ((length = fread(buffer, 1, 16, infile)) != 0) {
      for (i = 0; i < 16; i++)
         if (i < length)
            printf("%02X ", buffer[i]);
         else
            printf("  ");

      printf("   ");

      for (i = 0; i < length; i++)
         printf("%c", (buffer[i] < 32) ? '.' : buffer[i]);

      printf("\n");
   }

   printf("\nPress any key to continue...");
   getch();
}

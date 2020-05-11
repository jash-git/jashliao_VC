/*                        */
/* Program Name : fread.c */
/*                        */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *stream;
   char buffer[81];

   clrscr();
   if ((stream = fopen("fread.c", "rb")) == NULL) {
      printf("Cannot open file 'fread.c'.\n");
      exit(0);
   }

   printf("First 80 characters in file 'fread.c'...\n");
   fread(buffer, sizeof(char), 80, stream);
   /* Add a null character to the end oif string buffer */
   buffer[80] = '\0';
   printf("%s", buffer);
   fclose(stream);

   printf("\nPress any key to continue...");
   getch();
}

/*                        */
/* Program Name : fgetc.c */
/*                        */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *fptr;
   int  ch;

   clrscr();
   if ((fptr = fopen("fgetc.c", "rt")) == NULL) {
      printf("Cannot open file fgetc.c\n");
      exit(0);
   }

   printf("=== Content of file fgetc.c: ===\n");
   while ((ch = fgetc(fptr)) != EOF)
      putchar(ch);

   printf("=== End of File fgetc.c ===\n");
   fclose(fptr);
   printf("\nPress any key to continue...");
   getch();
}

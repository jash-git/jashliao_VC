/*                       */
/* Program Name : getc.c */
/*                       */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *fptr;
   int  ch;

   clrscr();
   if ((fptr = fopen("getc.c", "rt")) == NULL) {
      printf("Cannot open file getc.c\n");
      exit(0);
   }

   printf("=== Content of file getc.c: ===\n");
   while ((ch = getc(fptr)) != EOF)
      putchar(ch);

   printf("=== End of File getc.c ===\n");
   fclose(fptr);
   printf("\nPress any key to continue...");
   getch();
}

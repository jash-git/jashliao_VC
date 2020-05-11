/*                         */
/* Program Name : mktemp.c */
/*                         */

#include <dir.h>
#include <stdio.h>
#include <conio.h>

void main()
{
   char tmpname[13];
   FILE *fptr;
   int  i;

   clrscr();
   printf("The 10 unique file names are :\n");

   for (i = 0; i < 10;i++) {
      strcpy(tmpname, "tmpXXXXXX");
      printf("%s\n", mktemp(tmpname));
      fptr = fopen(tmpname, "w");
      fclose(fptr);
   }

   printf("\nPress any key to continue...");
   getch();
}

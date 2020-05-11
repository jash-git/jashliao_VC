/*                          */
/* Program Name : fileno.c  */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *fptr;

   fptr = fopen("fileno.c", "rt");
   printf("File handle of stdin  : %d\n", fileno(stdin));
   printf("File handle of stdout : %d\n", fileno(stdout));
   printf("File handle of stdprn : %d\n", fileno(stdprn));
   printf("File handle of file 'fileno.c' : %d\n", fileno(fptr));
   fclose(fptr);

   printf("\nPress any key to continue...");
   getch();
}

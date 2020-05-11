/*                           */
/* Program Name : dosexter.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   FILE *fptr;
   struct DOSERROR doserror;
   char tempname[14];

   clrscr();

   tmpnam(tempname);
   if ((fptr = fopen(tempname, "r")) == NULL) {
      printf("Cannot open file '%s'.\n", tempname);
      printf("Extended DOS error information:\n\n");

      dosexterr(&doserror);
      printf("Extended error : %d\n", doserror.exterror);
      printf("Class          : %d\n", doserror.class);
      printf("Action         : %d\n", doserror.action);
      printf("Error locus    : %d\n", doserror.locus);
   }
   else {
      printf("Successfully open file '%s'\n", tempname);
      fclose(fptr);
   }

   printf("\nPress any key to contunue...");
   getch();
}

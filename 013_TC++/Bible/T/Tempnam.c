/*                          */
/* Program Name : tempnam.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
   FILE *fptr;
   int i;
   char *tempname;

  for (i = 0; i < 3; i++) {
     if ((tempname = tempnam("\\tmp","wow")) == NULL)
        printf("Cannot create temporary file name.\n");
     else {
      if ((fptr = fopen(tempname,"wb")) == NULL)
        printf("Could not open temporary file\n");
      else
        fclose(fptr);
         printf("The file named %s is created.\n",tempname);
    }
    free(tempname);
  }
   printf("\nPress any key to continue...");
   getch();
}


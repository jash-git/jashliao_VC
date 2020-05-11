/*                           */
/* Program Name : clearerr.c */
/*                           */

#include <stdio.h>

void main()
{
   FILE *fptr;
   char fname[80];

   printf("Enter an existing file name:");
   gets(fname);

   /* Open the file */
   if ((fptr = fopen(fname, "rt")) == NULL) {
      printf("Failed to open : %s\n", fname);
      exit(0);
   }

   /* Try to write a message to the file... */
   printf("Attempt to write a message to the file...\n");
   fputs("Test string", fptr);

   if (ferror(fptr) != 0) {
      printf("Error occured!\n");
      clearerr(fptr); /* Clear the error */
      printf("Error cleared.\n");
   }
}

/*                          */
/* Program Name : fgetpos.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE   *fptr;
   fpos_t curpos;

   clrscr();

   if ((fptr = fopen("fgetpos.bak", "wt")) == NULL) {
      printf("Error to create file.\n");
      exit(0);
   }

   /* Get current file pointer */
   if (fgetpos(fptr, &curpos) == 0)
      printf("Current file pointer is at %d\n", curpos);
   else
      printf("Error occured!\n");

   printf("Now write the message 'This is a test.\\n' to file...\n");

   /* Write message to the file */
   fputs("This is a test.\n", fptr);

   /* Get current file pointer */
   fgetpos(fptr, &curpos);
   printf("Current file pointer is at %d\n", curpos);

   fclose(fptr);

   printf("\nPress any key to continue...");
   getch();
}

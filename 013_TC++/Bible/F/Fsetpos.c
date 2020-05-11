/*                          */
/* Program Name : fsetpos.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE   *fptr;
   fpos_t curpos;
   char   buffer[20];

   clrscr();
   if ((fptr = fopen("test", "wt")) == NULL) {
      printf("Cannot create file 'test'.\n");
      exit(0);
   }

   printf("Get current file location...\n");
   fgetpos(fptr, &curpos);
   printf("Write message 'This is a test 1' to file 'test'...\n");
   fputs("This is a test 1", fptr);

   printf("Move file indicator to last file location...\n");
   if(fsetpos(fptr, &curpos) != 0) {
      printf("Cannot setting file pointer.=n");
      exit(0);
   }

   printf("Write message 'THIS IS A TEST 2' to file 'test'...\n");
   fputs("THIS IS A TSET 2", fptr);

   fclose(fptr);
   fptr = fopen("test", "rt");

   printf("Content of the file 'test':\n");
   fgets(buffer, 20, fptr);
   printf(buffer);
   fclose(fptr);

   printf("\nPress any key to continue...");
   getch();
}

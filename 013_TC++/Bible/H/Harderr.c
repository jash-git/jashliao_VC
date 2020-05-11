/*                          */
/* Program Name : harderr.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define IGNORE  0
#define RETRY   1
#define ABORT   2

int handler(int errval,int ax,int bp,int si)
{
   int ok = 0;
   int status;

   if (ax & 0x8000) {
      cputs("Device error\r\n");
      hardretn(ABORT);
   }

   while(!ok) {
      cputs("Error ocurred: R)etry, I)gnore, A)bort:");
      switch(getche()) {
         case 'A' :
         case 'a' : status = ABORT;  ok = 1; break;
         case 'R' :
         case 'r' : status = RETRY;  ok = 1; break;
         case 'I' :
         case 'i' : status = IGNORE; ok = 1; break;
      }
      cputs("\r\n");
   }

   hardresume(status);
   return ABORT;
}

void main()
{
   FILE *fptr;

   clrscr();
   harderr(handler);
   printf("Please empty disc drive A:\n");
   printf("Then press any key ....\n");
   getch();
   printf("Create a file from drive A:\n");

   fptr = fopen("A:test.", "wt");
   printf("File pointer returned at %Fp\n", fptr);
   fclose(fptr);

   printf("\nPress any key to continue...");
   getch();
}

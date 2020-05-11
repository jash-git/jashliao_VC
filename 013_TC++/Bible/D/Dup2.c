/*                       */
/* Program Name : dup2.c */
/*                       */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <conio.h>

#define  STDOUT   1
#define  STDPRN   4

void main()
{
   int  oldhandle;
   char *message = "This is a test to STDPRN.";

   clrscr();

   /* Save STDPRN file handle */
   oldhandle = dup(STDPRN);
   printf("Redirect STDPRN to STDOUT...\n");
   if (dup2(STDOUT, STDPRN) == -1) {
      printf("Cannot force STDPRN to refer to STDOUT.\n");
      exit(0);
   }

   printf("Write message '%s' to STDPRN (now is to STDOUT)...\n", message);
   write(STDPRN, message, strlen(message));

   /* Restore STDPRN file handle */
   dup2(oldhandle, STDPRN);

   printf("\nPress any key to continue...");
   getch();
}

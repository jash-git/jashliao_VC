/*                            */
/* Program Name : creattemp.c */
/*                            */

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <errno.h>

void main()
{
   char   pathname[74] = "\\";
   int    handle;

   clrscr();
   if ((handle = creattemp(pathname, 0)) == -1) {
      switch(errno) {
         case ENOENT : printf("Cannot find path.\n");
                       break;
         case EMFILE : printf("Too many open files.\n");
                       break;
         case EACCES : printf("Permission denied.\n");
      }
      exit(0);
   }

   printf("Temporary file is successfully created.\n");
   printf("The name of this temporary file  is : %s\n", pathname);
   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

/*                           */
/* Program Name : findnext.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dir.h>
#include <dos.h>

void main()
{
   struct ffblk fileinfo;
   int done = 0;

   clrscr();
   printf("Get file listing from current directory...");
   if (findfirst("*.*", &fileinfo, 0) == 0) {
      printf("\nFile listing:\n");
      while (!done) {
         printf("%13s\n", fileinfo.ff_name);
         done = findnext(&fileinfo);
      }
   }
   else
      printf("Error to get file listing\n");

   printf("\nPress any key to continue...");
   getch();
}

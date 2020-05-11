/*                           */
/* Program Name : _d_fdnxt.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   struct find_t ffblk;
   int done = 0;

   clrscr();
   printf("Get file listing from current directory...");
   if (_dos_findfirst("*.*", _A_NORMAL, &ffblk) == 0) {
      printf("\nFile listing:\n");
      while (!done) {
         printf("%13s\n", ffblk.name);
         done = _dos_findnext(&ffblk);
      }
   }
   else
      printf("Error to get file listing\n");

   printf("\nPress any key to continue...");
   getch();
}

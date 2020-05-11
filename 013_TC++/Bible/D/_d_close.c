/*                           */
/* Program Name : _d_close.c */
/*                           */

#include <stdio.h>
#include <fcntl.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
   int    handle;

   clrscr();
   printf("Open file '_d_close.c'...\n");
   if (_dos_open("_d_close.c", O_RDONLY, &handle) != 0) {
      printf("Cannot open file '_d_close.c'.\n");
      exit(0);
   }

   if(_dos_close(handle) == 0)
      printf("Successfully closed file '_d_close.c'.\n");
   else
      printf("Error to close file '_d_close.c'.\n");

   printf("\nPress any key to continue...");
   getch();
}

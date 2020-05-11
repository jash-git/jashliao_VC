/*                           */
/* Program Name : findfrst.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dir.h>
#include <dos.h>

void main()
{
   struct ffblk fileinfo;

   clrscr();
   printf("Get the volume label of drive D:...");
   if (findfirst("D:*.*", &fileinfo, FA_LABEL) == 0)
      printf("\nThe volume label of drive D: is '%s'\n",
             fileinfo.ff_name);
   else
      printf("Drive D: has no label\n");

   printf("\nPress any key to continue...");
   getch();
}

/*                           */
/* Program Name : _d_fdfst.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   struct find_t ffblk;

   clrscr();
   printf("Get the volume label of disc C:...");
   if (_dos_findfirst("C:*.*", _A_VOLID, &ffblk) == 0)
      printf("\nThe volume label of drive C: is '%s'\n",
             ffblk.name);
   else
      printf("Error to get volume of disc C:\n");

   printf("\nPress any key to continue...");
   getch();
}

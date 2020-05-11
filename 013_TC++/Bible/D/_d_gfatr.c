/*                            */
/*  Program Name: _d_gfatr.c  */
/*                            */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

void main()
{
   char filename[80];
   unsigned attrib;

   clrscr();
   printf("Please enter a file name : ");
   gets(filename);

   printf("Get file information...\n");
   if (_dos_getfileattr(filename, &attrib) != 0) {
      printf("Error to get attribute of file '%s'\n", filename);
      exit(0);
   }

   printf("\nThe attribute if file '%s' :\n", filename);
   if (attrib & _A_RDONLY)
      printf("Read-only.\n");

   if (attrib & _A_HIDDEN)
      printf("Hidden file.\n");

   if (attrib & _A_SYSTEM)
      printf("System file.\n");

   if (attrib & _A_VOLID)
      printf("Volume labed.\n");

   if (attrib & _A_SUBDIR)
      printf("A directory.\n");

   if (attrib & _A_ARCH)
      printf("A achive.\n");

   if (attrib & _A_NORMAL)
      printf("A normal file.\n");

   printf("\nPress any key to continue...\n");
   getch();
}

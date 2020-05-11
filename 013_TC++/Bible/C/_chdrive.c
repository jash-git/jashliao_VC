/*                            */
/*  Program Name: _chdrive.c  */
/*                            */
#include <stdio.h>
#include <conio.h>
#include <direct.h>

void main()
{
   clrscr();
   printf("Set current active drive to C:...\n");
   if (_chdrive(3) != 0)
      printf("Error to set active drive to C:\n");
   else
      printf("Successfully set active drive to C:\n");

   printf("\nPress any key to continue...\n");
   getch();
}

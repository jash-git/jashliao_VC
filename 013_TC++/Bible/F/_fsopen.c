/*                          */
/* Program Name : _fsopen.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <share.h>

void main()
{
   FILE *fptr1, *fptr2;

   clrscr();
   if ((fptr1 = _fsopen("_fsopen.c", "rt", SH_DENYWR)) == NULL)
      printf("Error to open file '_fsopen.c' at first time.\n");
   else
      printf("File '_fsopen.c' is opened at first time.\n");

   if ((fptr2 = _fsopen("_fsopen.c", "rt", SH_DENYWR)) == NULL)
      printf("Error to open file '_fsopen.c' at second time.\n"
             "SHARE.EXE is working!\n");
   else
      printf("File '_fsopen.c' is opened at second time.\n");

   if (fptr1 != NULL)
      fclose(fptr1);

   if (fptr2 != NULL)
      fclose(fptr2);

   printf("\nPress any key to continue...");
   getch();
}

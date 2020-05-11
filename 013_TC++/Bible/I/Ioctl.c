
/*                        */
/* Program Name : ioctl.c */
/*                        */
#include <stdio.h>
#include <conio.h>
#include <dir.h>
#include <io.h>

void main()
{
   int stat;

   clrscr();
   /* use func 8 to determine if the default drive
    is removable */
   printf("IOCTL test : default drive is removable ?\n");
   stat = ioctl(0, 8, 0, 0);
   if (!stat)
      printf("Default drive %c is removable.\n",
                  getdisk() + 'A');
   else
      printf("Default drive %c is not removable.\n",
               getdisk() + 'A');
}

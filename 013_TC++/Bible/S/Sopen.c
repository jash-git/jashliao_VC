/*                        */
/* Program Name : sopen.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <share.h>
#include <io.h>

void main()
{
   int handle1, handle2;

   clrscr();
   handle1 = sopen("sopen.c", O_RDONLY, SH_DENYRW, S_IFREG);
   if(handle1 == -1)
      printf("Error to open file 'sopen.c' at first time.\n");
   else
      printf("File 'sopen.c' is opened at first time.\n");

   handle2 = sopen("sopen.c", O_RDONLY, SH_DENYNONE, S_IFREG);
   if(handle2 == -1)
      printf("Error to open file 'sopen.c' at second time.\n"
             "SHARE.EXE is working!\n");
   else
      printf("File 'sopen.c' is opened at second time.\n");

   if (handle1 != -1)
      close(handle1);

   if (handle2 != -1)
      close(handle2);

   printf("\nPress any key to continue...");
   getch();
}

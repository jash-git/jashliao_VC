/*                          */
/* Program Name : flength.c */
/*                          */

#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
   int handle;

   clrscr();
   printf("Open file flength.c...\n");
   if ((handle = open("flength.c", O_RDONLY)) == -1) {
      printf("Error to open file 'flength.c'.\n");
      exit(0);
   }
   printf("The file size of 'flength.c' is %ld\n",
          filelength(handle));

   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

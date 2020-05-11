/*                          */
/* Program Name : freemem.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   unsigned segment;

   clrscr();

   if (allocmem(1, &segment) != -1)
      printf("Error to allocate 16 bytes memory.\n");
   else {
      printf("Successfully allocated 16 bytes memory.\n");
      printf("Free the memory....\n");
      if (freemem(segment) == 0)
         printf("Memory is successfully freed.\n");
      else
         printf("Error to free the memory.\n");
   }

   printf("\nPress any key to continue...");
   getch();
}

/*                         */
/* Program Name : remove.c */
/*                         */

#include <stdio.h>
#include <conio.h>
#include <errno.h>

void main()
{
   char filename[80];

   clrscr();
   printf("Please enter a filename to delete:");
   gets(filename);

   if (remove(filename) == 0)
      printf("Successfully deleted file : %s\n", filename);
   else {
      switch(errno) {
         case ENOENT: printf("Cannot find file : %s \n",
                      filename);
                      break;
         case EACCES: printf("Permission denied.\n");
                      break;
         default    : printf("Errno : %d\n", errno);
      }
   }

   printf("\nPress any key to continue...");
   getch();
}

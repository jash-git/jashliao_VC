/*                        */
/* Program Name : chmod.c */
/*                        */

#include <io.h>
#include <sys\stat.h>
#include <errno.h>
#include <stdio.h>
#include <conio.h>

void main()
{
   char filename[80];

   clrscr();
   printf("Please enter a file name:");
   gets(filename);

   if (chmod(filename, S_IREAD) == 0)
      printf("File %s is successfully set to read-only "
             "mode.\n", filename);
   else {
      printf("\nError occured!\n\n");
      switch(errno) {
         case ENOENT: printf("File name is not found.\n");
                      break;
         case EACCES: printf("Permission denied.\n");
      }
   }

   printf("\nPress any key to continue...");
   getch();
}

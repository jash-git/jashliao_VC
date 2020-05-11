/*                         */
/* Program Name : unlink.c */
/*                         */

#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <errno.h>

void main()
{
   char filename[80];

   clrscr();
   printf("Please enter a file name : ");
   gets(filename);

   printf("Are you sure to delete it (y/n)?");
   if (tolower(getche()) == 'y') {
      if (unlink(filename) == -1) {
         printf("\n\nErrot occured.\n");
         switch(errno) {
            case ENOENT: printf("File %s is not found.\n",
                                filename);
                         break;

            case EACCES: printf("Permission deined.\n");
                         break;
            default    : printf("Errno = %d\n", errno);
         }
      }
      else
         printf("\n\nFile %s is successfully deleted.\n",
                filename);
   }
   else
      printf("\n\nFile %s is not deleted.\n", filename);

   printf("\nPress any key to continue...");
   getch();
}

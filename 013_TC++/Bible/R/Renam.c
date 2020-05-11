/*                        */
/* Program Name : renam.c */
/*                        */

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <errno.h>

void main()
{
   char oldname[80], newname[80];

   clrscr();
   printf("Please enter a filename to rename:");
   gets(oldname);
   /* Checks for file existence */
   if (access(oldname, 0) != 0) {
      printf("File : %s doesn't exist.\n", oldname);
      exit(0);
   }

   printf("Rename %s as : ", oldname);
   gets(newname);
   /* Checks for file existence */
   if (access(newname, 0) == 0) {
      printf("File : %s already exists.\n", newname);
      exit(0);
   }

   if (rename(oldname, newname) == 0)
      printf("Successfully renamed %s as %s\n",
             oldname, newname);
   else {
      switch(errno) {
         case ENOENT : printf("No such file.\n");
                       break;
         case EACCES : printf("Permission denied.\n");
                       break;
         case ENOTSAM: printf("Not the same device.\n");
                       break;
         default     : printf("Errno : %d\n", errno);
      }
   }

   printf("\nPress any key to continue...");
   getch();
}

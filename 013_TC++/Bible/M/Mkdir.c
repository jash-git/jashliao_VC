/*                        */
/* Program Name : mkdir.c */
/*                        */

#include <dir.h>
#include <stdio.h>
#include <errno.h>
#include <conio.h>

void main()
{
   char pathname[MAXPATH];
   /* MAXPATH is a symbol constant defined in dir.h */

   clrscr();

   printf("Please enter the directory you want to make"
          " :\n=>");

   gets(pathname);

   if (mkdir(pathname) == 0)
      printf("The directory %s is successfully created.\n",
             pathname);
   else {
      switch(errno) {
         case EACCES: printf("Permission denied.\n");
                      break;
         case ENOENT: printf("No such file or directory.\n");
      }
   }

   printf("\nPress any key to continue...");
   getch();
}

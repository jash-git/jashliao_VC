/*                        */
/* Program Name : chdir.c */
/*                        */

#include <dir.h>
#include <stdio.h>
#include <conio.h>

void main(int argc, char **argv)
{
   char pathname[MAXPATH];
   /* MAXPATH is a symbol constant defined in dir.h */

   if (argc < 2)
      printf("Usage : \n\tCH_DIR path [CR]\n");
   else {
       if (chdir(argv[1]) == -1)
          printf("Invalid directory.\n");
       else
          printf("Successfully changed directory to %s\n",
                 argv[1]);
   }

   printf("\nPress any key to continue...");
   getch();
}

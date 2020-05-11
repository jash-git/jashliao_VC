/*                          */
/* Program Name : readdir.c */
/*                          */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>

void main()
{
   char dirname[_MAX_PATH];
   DIR *dirptr;
   struct dirent *entry;
   int repeat = 1;

   clrscr();
   printf("Please enter a directory to list :");
   gets(dirname);

   if ((dirptr = opendir(dirname)) == NULL) {
      printf("Cannot open directory '%s'.\n", dirname);
      exit(0);
   }

   do {
      printf("\n----- File listing -----\n");
      while ((entry = readdir(dirptr)) != NULL)
         printf("%s\n",entry->d_name);
      printf("Review again ?(y/n)");
      if (toupper(getche()) == 'N')
         repeat = 0;
      else
         rewinddir(dirptr);
   } while(repeat);

   closedir(dirptr);

   printf("\nPress any key to continue...");
   getch();
}

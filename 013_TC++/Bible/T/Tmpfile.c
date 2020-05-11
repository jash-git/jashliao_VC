/*                          */
/* Program Name : tmpfile.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *tmp;

   clrscr();
   if ((tmp = tmpfile()) == NULL) {
      printf("Cannot create temporary file.\n");
      exit(0);
   }
   else
      printf("Temporary file is successfully opened.\n");

   printf("Write a message :\n'You cannot see this message at any files.'"
          "\nto temporary file...\n");
   fprintf(tmp, "You cannot see this message at any files.");

   printf("Close temoprary file...\n");
   fclose(tmp);

   printf("\nPress any key to continue...");
   getch();
}

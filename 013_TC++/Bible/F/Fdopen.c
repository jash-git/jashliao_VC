/*                         */
/* Program Name : fdopen.c */
/*                         */

#include <stdio.h>
#include <fcntl.h>
#include <conio.h>

void main()
{
   int  handle;
   FILE *fptr;
   char buffer[81];

   if ((handle = open("fdopen.c", O_RDONLY)) == -1) {
      printf("Cannot open low level I/O file.\n");
      exit(0);
   }

   if ((fptr = fdopen(handle, "rt")) == NULL) {
      printf("Cannot open stream I/O file.\n");
      exit(0);
   }

   clrscr();
   printf("=== Start to dump file... ===\n");
   while(fgets(buffer, 80, fptr) != NULL)
      printf(buffer);
   printf("\n=== End of file. ===\n");
   fclose(fptr);
   printf("\nPress any key to contunue...");
   getch();
}

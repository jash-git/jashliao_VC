/*                      */
/* Program Name : eof.c */
/*                      */

#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

void main()
{
   int  handle;
   char ch;

   clrscr();
   printf("Open file 'eof.c'...\n");
   if ((handle = open("eof.c", O_RDONLY | O_TEXT)) == -1) {
      printf("Cannot open feof.c\n");
      exit(0);
   }
   printf("=== Top of File ===\n");
   read(handle, &ch, 1);
   while(eof(handle) == 0) {
      putchar(ch);
      read(handle, &ch, 1);
   }
   printf("\n=== End of File ===\n");
   printf("\nPress any key to continue...");
   getch();
}

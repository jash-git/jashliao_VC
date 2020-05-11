/*                      */
/* Program Name : dup.c */
/*                      */

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <errno.h>
#include <fcntl.h>

void main()
{
   int    handle, duphandle;
   int    length;
   char   buffer[101];

   clrscr();
   printf("Open file 'dup.c'...\n");
   if ((handle = open("dup.c", O_RDONLY | O_TEXT)) == -1) {
      printf("Error to open file 'dup.c'\n");
      exit(0);
   }

   printf("File 'dup.c' is successfully opened.\n");
   printf("Duplicate the file handle...\n");
   if ((duphandle = dup(handle)) == -1) {
      printf("Error occured!\n");
      switch(errno) {
         case EMFILE: printf("Too many open files.\n");
                      break;
         case EBADF : printf("Bad original file handle.\n");
                      break;
      }
      exit(0);
   }

   printf("Use dupliicated file handle to read file 'dup.c'...\n");
   length = read(duphandle, buffer, 100);
   /* Make buffer into string */
   buffer[length] = '\0';

   printf("The first 100 bytes of characters in the file 'dup.c':\n");
   printf(buffer);
   close(duphandle);

   printf("\nPress any key to continue...");
   getch();
}

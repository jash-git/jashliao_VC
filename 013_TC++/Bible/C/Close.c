/*                        */
/* Program Name : close.c */
/*                        */

#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
   int    handle;
   double pi = 3.1415926;

   if ((handle = open("test", O_CREAT | O_BINARY )) == -1) {
      printf("File create failure.\n");
      exit(0);
   }

   printf("Write a double floating value %f to the file 'test'...\n", pi);
   write(handle, &pi, sizeof(double));
   printf("Close file...\n");
   close(handle);

   pi = 0.0;
   printf("Reopen file 'test'...\n");
   handle = open("test", O_RDONLY | O_BINARY);
   read(handle, &pi, sizeof(double));
   printf("The value written to file is %f\n", pi);
   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

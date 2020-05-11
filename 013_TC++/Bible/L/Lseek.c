/*                        */
/* Program Name : lseek.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

long filesize(char *filename);

void main()
{
   long flength;

   flength = filesize("lseek.c");
   if (flength < 0)
      printf("Error to get file size.\n");
   else
      printf("The size of file 'lseek.c' is %ld\n", flength);

   printf("\nPress any key to continue...");
   getch();
}

long filesize(char *filename)
{
   int  handle;
   long length;

   if ((handle = open(filename, O_RDONLY | O_BINARY)) == -1)
      return -1L;

   /* Move file pointer to the end of the file */
   length = lseek(handle, 0L, SEEK_END);
   close(handle);

   return length;
}

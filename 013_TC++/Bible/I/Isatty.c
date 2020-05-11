/*                         */
/* Program Name : isatty.c */
/*                         */

#include <io.h>
#include <stdio.h>
#include <conio.h>
#include <fcntl.h>

void main()
{
   int handle;

   clrscr();
   handle = fileno(stdaux);
   if (isatty(handle))
      printf("Handle %d (stdaux) is a device.\n", handle);
   else
      printf("Handle %d (stdaux) is not a device.\n",
             handle);

   printf("Open a file 'flength.c'....\n");
   handle = open("isatty.c", O_RDONLY);

   if (isatty(handle))
      printf("Handle %d (isatty.c) is a device.\n",
             handle);
   else
      printf("Handle %d (isatty.c) is not a device.\n",
             handle);

   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

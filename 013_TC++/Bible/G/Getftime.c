/*                           */
/* Program Name : getftime.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <dir.h>
#include <fcntl.h>
#include <stdlib.h>

void main()
{
   struct ftime timeinfo;
   char         path[MAXDIR];
   int          handle;

   clrscr();
   printf("Please enter a file name :");
   gets(path);

   if ((handle = open(path, O_RDONLY)) == -1) {
      printf("Error to open file :%s\n", path);
      exit(0);
   }

   printf("Getting date & time information of file %s...", path);
   getftime(handle, &timeinfo);

   printf("\n\nThe latest modification date : %d-%d-%d\n",
           timeinfo.ft_month,
           timeinfo.ft_day,
           timeinfo.ft_year + 1980);

   printf("The latest modification time : %d:%02d\n",
           timeinfo.ft_hour, timeinfo.ft_min);

   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

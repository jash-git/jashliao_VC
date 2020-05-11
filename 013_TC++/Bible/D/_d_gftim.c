/*                           */
/* Program Name : _d_gftim.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <dir.h>
#include <fcntl.h>
#include <stdlib.h>

struct {
   unsigned day   : 5;
   unsigned month : 4;
   unsigned year  : 7;
} date;

struct {
   unsigned secs_half : 5;
   unsigned minutes   : 6;
   unsigned hours     : 5;
} time;


void main()
{
   char   path[MAXDIR];
   int    handle;

   clrscr();
   printf("Please enter a file name :");
   gets(path);

   if (_dos_open(path, O_RDONLY, &handle) != 0) {
      printf("Error to open file :%s\n", path);
      exit(0);
   }

   printf("Getting date & time information of file %s...", path);
   _dos_getftime(handle, (unsigned *) &date, (unsigned *) &time);

   printf("\n\nThe latest modification date : %u-%u-%u\n",
           (unsigned) date.month,
           (unsigned) date.day,
           (unsigned) date.year+1980);

   printf("The latest modification time : %u:%02u\n",
           time.hours, time.minutes);

   _dos_close(handle);

   printf("\nPress any key to continue...");
   getch();
}

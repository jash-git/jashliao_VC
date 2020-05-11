
/*                             */
/*    Program Name: utime.c    */
/*                             */
#include <utime.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

void main(void)
{
   char *filename,error_number;
   struct utimbuf times;
   struct stat stattime;
   time_t currenttime;
   printf("Please input filename:");
   gets(filename);
   time(&currenttime);
   times.modtime = times.actime = currenttime;
   error_number=utime(filename,&times);
   if (error_number==-1) {
      printf("Input filename error");
   }
   else {
      stat(filename,&stattime);
      printf("Filename: %s\n",filename);
      printf("Filetime: %s\n",
		   asctime(localtime(&stattime.st_mtime)));
   }
}

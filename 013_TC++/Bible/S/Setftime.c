
/*                           */
/* Program Name : setftime.c */
/*                           */
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <fcntl.h>
#include <io.h>

void main()
{
   struct ftime filet;
   FILE *fp;

   clrscr();
   if ((fp = fopen("FTIME.TXT", "w")) == NULL)
   {
      perror("Error:");
      exit(1);
   }

   fprintf(fp, "testing...\n");
   fclose(fp);
   /* show current directory for time and date */
   system("dir FTIME.TXT");

   if ((fp = fopen("FTIME.TXT", "r")) == NULL)
   {
      perror("Error:");
      exit(1);
   }
   /* load ftime structure with new time and date */
   filet.ft_tsec = 1;
   filet.ft_min = 1;
   filet.ft_hour = 1;
   filet.ft_day = 1;
   filet.ft_month = 1;
   filet.ft_year = 21;


   /* change the time and date stamp */
   if (setftime(fileno(fp), &filet) == -1)
     printf("Set file time error !\n");

   /* close and remove the temporary file */
   fclose(fp);

   system("dir FTIME.TXT");

   unlink("FTIME.TXT"); /* delete file */

}  /* main() */

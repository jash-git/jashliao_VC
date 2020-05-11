
/*                          */
/* Program Name : setdta.c  */
/*                          */

#include <process.h>
#include <string.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main()
{
   char line[80], far *save_dta;
   char buffer[256] = "Borland C++ Bible setdta() test !";
   struct fcb blk;
   int result;

   clrscr();
   /* get new file name from user */
   printf("Enter a file name to create:");
   gets(line);

   /* parse the new file name to the dta */
   parsfnm(line, &blk, 1);
   printf("%d %s\n", blk.fcb_drive, blk.fcb_name);

   /* request DOS services to create file */
   if (bdosptr(0x16, &blk, 0) == -1)
   {
      perror("Error creating file");
      exit(1);
   }

   /* save old dta and set new dta */
   save_dta = getdta();
   setdta(buffer);

   /* write new records */
   blk.fcb_recsize = 256;
   blk.fcb_random = 0L;
   result = randbwr(&blk, 1);
   printf("result = %d\n", result);

   if (!result)
      printf("Write OK !\n");
   else
   {
      perror("Disk error");
      exit(1);
   }

   /* request DOS services to close the file */
   if (bdosptr(0x10, &blk, 0) == -1)
   {
      perror("Error closing file");
      exit(1);
   }

   /* reset the old dta */
   setdta(save_dta);
}  /* main() */

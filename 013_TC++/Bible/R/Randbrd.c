
/*                          */
/* Program Name : randbrd.c */
/*                          */

#include <conio.h>
#include <process.h>
#include <string.h>
#include <stdio.h>
#include <dos.h>

void main()
{
   char far *save_dta;
   char line[80], buffer[256];
   struct fcb blk;
   int i, result;

   clrscr();
   /* get user input file name for dta */
   printf("Enter drive and file name (no path - i.e. a:file.dat)\n");
   gets(line);

   /* put file name in fcb */
   if (!parsfnm(line, &blk, 1))
   {
      printf("Error in call to parsfnm\n");
      exit(1);
   }
   printf("Drive #%d  File: %s\n\n", blk.fcb_drive,
           blk.fcb_name);

   /* open file with DOS FCB open file */
   bdosptr(0x0F, &blk, 0);

   /* save old dta, and set new one */
   save_dta = getdta();
   setdta(buffer);

   /* set up info for the new dta */
   blk.fcb_recsize = 128;
   blk.fcb_random = 0L;
   result = randbrd(&blk, 1);

   /* check results from randbrd */
   if (!result)
      printf("Read OK\n\n");
   else
   {
      perror("Error during read");
      exit(1);
   }

   /* read in data from the new dta */
   printf("The first 128 characters are:\n");
   for (i=0; i<128; i++)
      putchar(buffer[i]);

   /* restore previous dta */
   setdta(save_dta);

} /* main() */

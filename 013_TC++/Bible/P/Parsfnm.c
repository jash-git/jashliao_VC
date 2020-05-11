
/*                          */
/* Program Name : parsfnm.c */
/*                          */
#include <process.h>
#include <string.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>

void main()
{
   char line[80];
   struct fcb blk;

   clrscr();
   /* get file name */
   printf("Enter drive and file name (no path; e.g., fa:file.dat)\n");
   gets(line);

   /* put file name in fcb */
   if (parsfnm(line, &blk, 1) == NULL)
      printf("Error in parsfm call\n");
   else
      printf("Drive #%d  Name: %11s\n", blk.fcb_drive,
              blk.fcb_name);

} /* main() */

/*                           */
/* Program Name : getdfree.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define  CUR_DISK       2  /* Disc C: */

void main()
{
   struct dfree diskinfo;

   clrscr();

   printf("\nGetting disk information...");
   getdfree(CUR_DISK, &diskinfo);

   if (diskinfo.df_sclus == 0xFFFF)
      printf("\nError to get disk information...\n");
   else {
      printf("\n\nDisk information:\n\n");
      printf("Available clusters  : %u\n", diskinfo.df_avail);
      printf("Total clusters      : %u\n", diskinfo.df_total);
      printf("Bytes per sector    : %u\n", diskinfo.df_bsec);
      printf("Sectors per cluster : %u\n", diskinfo.df_sclus);

      printf("\nThere are total %ld bytes free.\n",
            (unsigned long) diskinfo.df_avail *
                            diskinfo.df_sclus *
                            diskinfo.df_bsec);
   }

   printf("\nPress any key to continue...");
   getch();
}

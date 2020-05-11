/*                           */
/* Program Name : _d_dgfre.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define  CUR_DISK       3  /* Disc C: */

void main()
{
   struct diskfree_t diskinfo;

   clrscr();

   printf("\nGetting disk information...");

   if (_dos_getdiskfree(CUR_DISK, &diskinfo) == 0) {
      printf("\n\nDisk information:\n\n");
      printf("Available clusters  : %u\n", diskinfo.avail_clusters);
      printf("Total clusters      : %u\n", diskinfo.total_clusters);
      printf("Bytes per sector    : %u\n", diskinfo.bytes_per_sector);
      printf("Sectors per cluster : %u\n", diskinfo.sectors_per_cluster);

      printf("\nThere are total %ld bytes free.\n",
            (unsigned long) diskinfo.avail_clusters *
                            diskinfo.sectors_per_cluster *
                            diskinfo.bytes_per_sector);
   }
   else
      printf("\nError to get disk information...\n");

   printf("\nPress any key to continue...");
   getch();
}

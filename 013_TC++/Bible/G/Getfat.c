/*                         */
/* Program Name : getfat.c */
/*                         */

#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   struct fatinfo fat;
   clrscr();

   printf("Getting FAT information...");
   getfat(0, &fat);

   printf("\n\nFAT information:\n");
   printf("Sectors per cluster : %d\n", fat.fi_sclus);
   printf("FAT id byte         : %X\n", (unsigned char) fat.fi_fatid);
   printf("Number of clusters  : %d\n", fat.fi_nclus);
   printf("Bytes per sector    : %d\n", fat.fi_bysec);

   printf("\nPress any key to continue...");
   getch();
}

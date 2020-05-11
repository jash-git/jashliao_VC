/*                           */
/* Program Name : _bi_disk.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <bios.h>

#define  DRIVE           0 /* Drive A:           */
#define  HEAD            0 /* Head 0             */
#define  TRACK           0 /* Track 0            */
#define  SECTOR          1 /* Sector 0           */
#define  NSECT           1 /* Numbers of sectors */

void main()
{
   int i, j;
   int status;
   unsigned char buffer[512];
   struct diskinfo_t dinfo;

   clrscr();
   printf("Read sector %d from Drive %c:, head %d, track %d...",
           SECTOR, DRIVE + 'A', HEAD, TRACK);

   dinfo.drive = DRIVE;
   dinfo.head = HEAD;
   dinfo.track = TRACK;
   dinfo.sector = SECTOR;
   dinfo.nsectors = NSECT;
   dinfo.buffer = buffer;

   status = _bios_disk(_DISK_READ, &dinfo);

   if ((status & 0xFF00) == 0) {
      printf("\nData read from sector %d is ok.\n", SECTOR);
      printf("Contents of the sector %d:\n", SECTOR);

      for (i = 0, j = 0; i < 512; i++) {
         printf("%02X ", buffer[i]);
         if (i % 16 == 15) {
            printf("   ");
            for (; j <= i; j++)
               printf("%c", (buffer[j] < 32) ? '.' : buffer[j]);
            putchar('\n');
         }
      }
   }
   else
      printf("\nError to read sector %d\n", SECTOR);

   printf("\nPress any key to continue...");
   getch();
}

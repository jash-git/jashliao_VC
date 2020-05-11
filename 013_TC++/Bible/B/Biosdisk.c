/*                           */
/* Program Name : biosdisk.c */
/*                           */

#include <stdio.h>
#include <conio.h>
#include <bios.h>

#define  SERVICE         2 /* Read service       */
#define  DRIVE           0 /* Drive A:           */
#define  HEAD            0 /* Head 0             */
#define  TRACK           0 /* Track 0            */
#define  SECTOR          0 /* Sector 0           */
#define  NSECT           1 /* Numbers of sectors */

void main()
{
   int i, j;
   int status;
   unsigned char buffer[512];

   clrscr();
   printf("Read sector %d from Drive %c:, head %d, track %d...",
           SECTOR, DRIVE + 'A', HEAD, TRACK);

   status = biosdisk(SERVICE, DRIVE, HEAD, TRACK, SECTOR, NSECT, buffer);

   if (status == 0) {
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

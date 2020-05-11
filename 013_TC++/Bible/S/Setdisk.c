
/*                          */
/* Program Name : setdisk.c */
/*                          */

#include <conio.h>
#include <stdio.h>
#include <dir.h>

void main()
{
   int save, disk, disks;

   clrscr();
   /* save original drive */
   save = getdisk();

   /* print number of logic drives */
   disks = setdisk(save);
   printf("%d logical drives on the system\n\n", disks);

   /* print the drive letters available */
   printf("Available drives:\n");
   for (disk = 0;disk < 26;++disk)
   {
      setdisk(disk);
      if (disk == getdisk())
         printf("%c: drive is available\n", disk + 'A');
   }
   setdisk(save);

}  /* main() */

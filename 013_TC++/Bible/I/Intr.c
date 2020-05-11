
/*                       */
/* Program Name : intr.c */
/*                       */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dir.h>
#include <dos.h>

#define CFlag 1  /* Carry flag */

void main()
{
   char dirstr[80];
   struct REGPACK reg;

   clrscr();
   printf("Enter directory to change to: ");
   gets(dirstr);
   reg.r_ax = 0x3B << 8;         /* shift 3Bh into  AH */
   reg.r_dx = FP_OFF(dirstr);
   reg.r_ds = FP_SEG(dirstr);
   intr(0x21, &reg);
   if (reg.r_flags & CFlag)
      printf("Directory change failed !\n");
   getcwd(dirstr, 80);
   printf("The current directory is: %s\n", dirstr);
}

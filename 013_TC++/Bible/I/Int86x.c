
/*                         */
/* Program Name : int86x.c */
/*                         */
#include <dos.h>
#include <conio.h>
#include <process.h>
#include <stdio.h>

void main()
{
   char filename[80];
   union REGS inregs, outregs;
   struct SREGS segregs;

   clrscr();
   printf("Enter filename: ");
   gets(filename);
   inregs.h.ah = 0x43;
   inregs.h.al = 0x21;
   inregs.x.dx = FP_OFF(filename);
   segregs.ds = FP_SEG(filename);
   int86x(0x21, &inregs, &outregs, &segregs);
   printf("%s file attribute: %X\n", filename,
   outregs.x.cx);
} /* main() */

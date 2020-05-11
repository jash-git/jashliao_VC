
/*                         */
/* Program Name : intdos.c */
/*                         */
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   int err;
   union REGS regs;
   int ret;

   clrscr();
   regs.h.ah = 0x30; /* Get DOS version number */
   ret = intdos(&regs, &regs);
   printf("Dos ver %2d.%02d\n", regs.h.al, regs.h.ah);

}

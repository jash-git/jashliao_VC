
/*                        */
/* Program Name : int86.c */
/*                        */
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define VIDEO_INTR 0x10

void GoToXY(int x, int y);

void main()
{
  clrscr();
  GoToXY(25, 12);
  puts("Borland C++ Bible int86() test !\n");
}

void GoToXY(int x, int y)
{
  union REGS regs;

  regs.h.ah = 2;  /* set cursor position service */
  regs.h.dh = y;
  regs.h.dl = x;
  regs.h.bh = 0;  /* page 0 */
  int86(VIDEO_INTR, &regs, &regs);
}

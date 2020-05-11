
/*                       */
/* Program Name : keep.c */
/*                       */
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
  clrscr();
  puts("Press a key to exit...");
  getch();
  keep(0,(_SS+(_SP/16))-_psp );
  puts("Now, program is resident in memory !");
}

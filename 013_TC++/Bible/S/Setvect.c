
/*                          */
/* Program Name : setvect.c */
/*                          */

#include <stdio.h>
#include <dos.h>
#include <conio.h>

int flag = 0;
void interrupt NewTimer(void);

void main()
{
  unsigned c;
  void interrupt (*OldTimer)();
  unsigned intno = 0x1C;

  clrscr();
  printf("Before set new timer interrupt flag is %d\n", flag);
  OldTimer = getvect(intno);
  disable();
  setvect(intno, NewTimer);
  enable();
  puts("New timer installed !");
  puts("Press a key to quit ...");
  getch();

  /* reset vector and print the flag value */
  puts("Now uninstall user timer interrupt !");
  disable();
  setvect(intno, OldTimer);
  enable();
  printf("Current flag is %d\n", flag);

} /* main() */

void interrupt NewTimer()
{
  if (flag == 1)
    flag--;
  else
    flag++;
} /* NewTimer() */

/*                            */
/*  Program Name: _fpreset.c  */
/*                            */
#include <stdio.h>
#include <float.h>
#include <setjmp.h>
#include <signal.h>

void float_trap(int);

jmp_buf reenter;

void main(void)
{
   double one = 3.11, two = 0;
   /* Install signal handler for floating-point exception */
   if (signal(SIGFPE, float_trap) == SIG_ERR) {
      printf("error installing signal handler\n");
      exit(3);
   }
   printf("Generating a math error, press a key\n");
   getch();
   if (setjmp(reenter) == 0) {
      one /= two;
   }
   printf("Returned from signal trap\n");
}

/* Define a handler for trapping floating-point errors */
void float_trap(int sig)
{
   printf("Trapping floating point error, signal is: %d\n", sig);

   printf("Press a key to continue\n");
   getch();
   /* Reset the 8087 chip or emulator to */
   /* clear any extraneous garbage       */
   _fpreset();
   /* Return to the problem spot */
   longjmp(reenter, -1);
}

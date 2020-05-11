
/*                           */
/* Program Name : setblock.c */
/*                           */

#include <conio.h>
#include <dos.h>
#include <alloc.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
   unsigned int size, segp;
   int stat;

   clrscr();
   size = 64; /* (64 x 16) = 1024 bytes */
   stat = allocmem(size, &segp);
   if (stat == -1)
      printf("Allocated memory at segment: %X\n", segp);
   else
   {
      printf("Failed: maximum number of paragraphs \
               available is %d\n",
              stat);
      exit(1);
   }

   stat = setblock(segp, size * 2);
   if (stat == -1)
      printf("Expanded memory block at segment: %X\n",
              segp);
   else
      printf("Failed: maximum number of paragraphs \
              available is %d\n", stat);

   freemem(segp);

} /* main() */

/*                            */
/*  Program Name: _g_g_mem.c  */
/*                            */
#include <alloc.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>

#define DELAY_TIME  1500

int InGraph = 0;

void main(void)
{
   int GraphDriver = DETECT, GraphMode;

   initgraph(&GraphDriver, &GraphMode, "..\\BGI");

   /* To indicate it is in the graphics mode. */
   InGraph = 1;

   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
   outtextxy(0, 0, "C Bible");

   delay(DELAY_TIME);
   closegraph();
}

void far _graphfreemem(void far *ptr, unsigned size)
{
   printf("Free %u bytes memory.\a\n", size);
   delay(DELAY_TIME);
   farfree(ptr);
}

void far *far _graphgetmem(unsigned size)
{
   char OutText[81];

   /* Is in the graphics mode? */
   if(InGraph) {
      sprintf(OutText, "Allocate %u bytes memory!", size);
      outtextxy(0, 0, OutText);
      delay(DELAY_TIME);
      clearviewport();
   }
   else {
      printf("Allocate %u bytes memory!\a\n", size);
      delay(DELAY_TIME);
   }

   return (farmalloc(size));
}

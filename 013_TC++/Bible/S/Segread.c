
/*                          */
/* Program Name : segread.c */
/*                          */

#include <conio.h>
#include <stdio.h>
#include <dos.h>

void main()
{
   struct SREGS segs;

   clrscr();
   segread(&segs);
   printf("Current segment register value:\n\n");
   printf("DS=%X  ES=%X  SS=%X  CS=%X\n",segs.ds, segs.es,
                                         segs.ss, segs.cs);

} /* main() */

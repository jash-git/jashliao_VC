/*                        */
/* Program Name : mk_fp.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

void main()
{
   char keybuf[8];
   char *endptr; /* used by function strtol */
   int segment, offset;

   clrscr();

   printf("Please enter segment address in hexadecimal : ");
   gets(keybuf);
   segment = strtol(keybuf, &endptr, 16);

   printf("Please enter offset address in hexadecimal :");
   gets(keybuf);
   offset = strtol(keybuf, &endptr, 16);

   printf("The far address of segment:offset is %Fp\n",
          MK_FP(segment, offset));

   printf("\nPress any key to continue...");
   getch();
}

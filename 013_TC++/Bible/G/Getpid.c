/*                              */
/*    Program Name: getpid.c    */
/*                              */
#include <process.h>
#include <stdio.h>

void main( void )
{
   printf("This process ID of the program is %X\n", getpid()
         );
}

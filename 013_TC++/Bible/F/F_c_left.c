/*                                 */
/*    Program Name : f_c_left.c    */
/*                                 */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   printf( "There are %lu bytes available in memory.\n",
           farcoreleft() );
}

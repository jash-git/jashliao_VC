/*                                 */
/*    Program Name : coreleft.c    */
/*                                 */
#include <alloc.h>
#include <stdio.h>

void main( void )
{
   printf( "There are %u bytes available in memory.\n",
           coreleft() );
}

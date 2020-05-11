/*                                */
/*    Program Name: localeco.c    */
/*                                */
#include <locale.h>
#include <stdio.h>

void main( void )
{
   struct lconv *Locale ;

   Locale = localeconv();

   /*  Display the format information.  */
   printf( "Locale informations :\n" );
   printf( "Decimal Point          = %s\n",
           Locale->decimal_point );
   printf( "Thousands Separator    = %s\n",
           Locale->thousands_sep );
   printf( "Grouping               = %s\n",
           Locale->grouping );
   printf( "Positive sign position = %d\n",
           Locale->p_sign_posn );
   printf( "Negative sign position = %d\n",
           Locale->n_sign_posn );
}

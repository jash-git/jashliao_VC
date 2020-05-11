/*                                */
/*    Program Name : spawn-p.c    */
/*                                */
#include <conio.h>
#include <process.h>
#include <stdio.h>

void main( void )
{
   /*  The environment parameter table.  */
   char *envp[] = { "PATH = C:\\C_LIB",
                    NULL
                  };

   /*  The array of command line arguments.  */
   char *argv[] = { "SPAWN-C",
                    "spawnvpe",
                    "Arg1",
                    "Arg2",
                    NULL
                  };
   char Choice;

   printf( "Spawn Function.  Select the following one " );
   printf( "which you want :\n" );
   printf( "--------------------\n" );
   printf( "  1.spawnl\n" );
   printf( "  2.spawnle\n" );
   printf( "  3.spawnlp\n" );
   printf( "  4.spawnlpe\n" );
   printf( "  5.spawnv\n" );
   printf( "  6.spawnve\n" );
   printf( "  7.spawnvp\n" );
   printf( "  8.spawnvpe\n" );
   printf( "--------------------\n" );
   printf( "  Choice : " );

   do {
      Choice = getche();

      switch ( Choice ) {
         case '1' : spawnl( P_WAIT, "SPAWN-C", "SPAWN-C",
                            "spawnl", "Arg1", "Arg2",
                            NULL );
                    break;
         case '2' : spawnle( P_WAIT, "SPAWN-C", "SPAWN-C",
                             "spawnle", "Arg1", "Arg2",
                             NULL, envp );
                    break;
         case '3' : spawnlp( P_WAIT, "SPAWN-C", "SPAWN-C",
                             "spawnlp", "Arg1", "Arg2",
                             NULL );
                    break;
         case '4' : spawnlpe( P_WAIT, "SPAWN-C", "SPAWN-C",
                              "spawnlpe", "Arg1", "Arg2",
                              NULL, envp );
                    break;
         case '5' : argv[1][6] = '\0';
                    spawnv( P_WAIT, "SPAWN-C", argv );
                    break;
         case '6' : argv[1][6] = 'e';
                    argv[1][7] = '\0';
                    spawnve( P_WAIT, "SPAWN-C", argv,
                             envp );
                    break;
         case '7' : argv[1][7] = '\0';
                    spawnvp( P_WAIT, "SPAWN-C", argv );
                    break;
         case '8' : spawnvpe( P_WAIT, "SPAWN-C", argv,
                              envp );
                    break;
         default  : printf( "\a\b" );
      };
   } while( Choice < '1' || Choice > '8' );
   printf( "---------------------\n" );
   printf( "Return to parent process.\n" );
}

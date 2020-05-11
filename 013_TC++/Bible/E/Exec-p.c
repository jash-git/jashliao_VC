/*                              */
/*    Program Name: exec-p.c    */
/*                              */
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
   char *argv[] = { "EXEC-C",
                    "execvpe",
                    "Arg1",
                    "Arg2",
                    NULL
                  };
   char Choice;

   printf( "Exec Function.  Select the following one " );
   printf( "which you want :\n" );
   printf( "--------------------\n" );
   printf( "  1.execl\n" );
   printf( "  2.execle\n" );
   printf( "  3.execlp\n" );
   printf( "  4.execlpe\n" );
   printf( "  5.execv\n" );
   printf( "  6.execve\n" );
   printf( "  7.execvp\n" );
   printf( "  8.execvpe\n" );
   printf( "--------------------\n" );
   printf( "  Choice : " );

   do {
      Choice = getche();

      switch ( Choice ) {
         case '1' : execl( "EXEC-C", "EXEC-C", "execl",
                           "Arg1", "Arg2", NULL );
                    break;
         case '2' : execle( "EXEC-C", "EXEC-C", "execle",
                            "Arg1", "Arg2", NULL, envp );
                    break;
         case '3' : execlp( "EXEC-C", "EXEC-C", "execlp",
                            "Arg1", "Arg2", NULL );
                    break;
         case '4' : execlpe( "EXEC-C", "EXEC-C", "execlpe",
                             "Arg1", "Arg2", NULL, envp );
                    break;
         case '5' : argv[1][5] = '\0';
                    execv( "EXEC-C", argv );
                    break;
         case '6' : argv[1][5] = 'e';
                    argv[1][6] = '\0';
                    execve( "EXEC-C", argv, envp );
                    break;
         case '7' : argv[1][6] = '\0';
                    execvp( "EXEC-C", argv );
                    break;
         case '8' : execvpe( "EXEC-C", argv, envp );
                    break;
         default  : printf( "\a\b" );
      };
   } while( Choice < '1' || Choice > '8' );
   printf( "You can't see this message because the " );
   printf( "child process will not return to the " );
   printf( "parent process.\n" );
}

/*                          */
/* Program Name : getpass.c */
/*                          */

#include <stdio.h>
#include <conio.h>

void main()
{
  int try, passed = 0;
  char *userpass, *password = "test";

  clrscr();

  for (try = 0; try < 3 && !passed; try++) {
     userpass = getpass("Password :");
     if (strcmp(userpass, password) == 0)
        passed = 1;
     else
        printf("Not correct. Try again...\n");
  }

  if (passed)
     printf("\nYou are passed.\n");
  else
     printf("\nYou are not passed.\n");

   printf("\nPress any key to continue...");
   getch();
}

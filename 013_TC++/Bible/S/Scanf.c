/*                        */
/* Program Name : scanf.c */
/*                        */

#include <stdio.h>
#include <conio.h>

void main()
{
   int   integer;
   char  str[80], junk[80];
   float fnumber;

   clrscr();

   printf("Enter an integer :");
   scanf("%d", &integer);
   printf("The integer you entered is :\n");
   printf("  %4d : in decimal\n  %4x : in hexadecimal\n"
        "  %4o : in octal\n\n",  integer, integer, integer);
   gets(junk); /* Eat all characters in keyboard */

   printf("Enter an floating point number :");
   scanf("%f", &fnumber);
   printf("The floating point number you entered "
          "is %f\n\n", fnumber);
   gets(junk); /* Eat all characters in keyboard */

   printf("Enter 5 characters :");
   scanf("%5c", str);
   str[5] = '\0';
   printf("The 5 characters you entered are :"
          "%s\n\n", str);
   gets(junk); /* Eat all characters in keyboard */

   printf("Enter a string (Allowed characters: a to z)."
          "\n=>");
   scanf("%[a-z]", str);
   gets(junk); /* Eat all characters in keyboard */
   printf("The string you entered is : %s", str);

   printf("\n\nEnter a string (Except characters : a to "
          "z).\n=>");
   scanf("%[^a-z]", str);
   gets(junk); /* Eat all characters in keyboard */
   printf("The string you entered is : %s\n", str);

   printf("\nPress any key to continue...");
   getch();
}

/*                           */
/* Program Name : s_n_hndl.c */
/*                           */

#include <conio.h>
#include <iostream.h>
#include <new.h>
#include <stdlib.h>

void mem_handler()
{
   cout << "No sufficient memory space!";
   exit(1);
}

void main()
{
   char *ptr1, *ptr2;

   clrscr();

   set_new_handler(mem_handler);

   cout << "Allocate 256 bytes to ptr1...\n";
   ptr1 = new char[256];

   cout << "Allocate 64K bytes to ptr2...\n";
   ptr2 = new char[64000U];

   set_new_handler(0);

   cout << "\nPress any key to continue...";
   getch();
}

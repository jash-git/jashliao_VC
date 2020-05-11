/*                          */
/* Program Name : vsscanf.c */
/*                          */

#include <stdio.h>
#include <conio.h>

int myvsscanf(char *buffer, char *format, ...)
{
   va_list arglist;
   int     numbers;

   va_start(arglist, format);
   numbers = vsscanf(buffer, format, arglist);
   va_end(arglist);

   return numbers;
}

void main()
{
   char *raw_data = "John 91 89 86 83";
   char name[10];
   int  score[4];

   clrscr();

   printf("Raw data : %s\n", raw_data);
   printf("Use myvsscanf function to scan each of the data"
          " item...\n");
   myvsscanf(raw_data, "%s %d %d %d %d", name, &score[0],
             &score[1], &score[2], &score[3]);

   printf("Name    : %-s\n", name);
   printf("Chinese : %d\n", score[0]);
   printf("English : %d\n", score[1]);
   printf("DS      : %d\n", score[2]);
   printf("C Lang. : %d\n", score[3]);

   printf("\nPress any key to continue...");
   getch();
}

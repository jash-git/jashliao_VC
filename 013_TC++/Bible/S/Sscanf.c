/*                         */
/* Program Name : sscanf.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   char *raw_data = "Mary 90 88 87 80";
   char name[10];
   int  score[4];

   clrscr();

   printf("Raw data : %s\n", raw_data);
   printf("Use sscanf function to scan each of the data item...\n");
   sscanf(raw_data, "%s %d %d %d %d", name, &score[0], &score[1],
                                            &score[2], &score[3]);

   printf("Name    : %-s\n", name);
   printf("Chinese : %d\n", score[0]);
   printf("English : %d\n", score[1]);
   printf("DS      : %d\n", score[2]);
   printf("C Lang. : %d\n", score[3]);

   printf("\nPress any key to continue...");
   getch();
}

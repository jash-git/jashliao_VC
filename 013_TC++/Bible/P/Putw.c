/*                       */
/* Program Name : putw.c */
/*                       */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *stream;
   int  word;

   clrscr();
   if ((stream = fopen("test", "wb")) == NULL) {
      printf("Cannot create file 'test'.\n");
      exit(0);
   }

   printf("Please enter an integer:");
   scanf("%d", &word);

   printf("Write the inter %d to file 'test'...\n", word);
   putw(word, stream);

   if (ferror(stream) != 0)
      printf("Error to write to file 'test'.\n");
   else
      printf("Successful write to file.\n");

   fclose(stream);

   printf("Now reopen the file 'test'...\n");
   stream = fopen("test", "rb");

   word = getw(stream);

   if (ferror(stream))
      printf("Error to read from file 'test'.\n");
   else
      printf("Successfull read from file.\n");

   printf("The integer you wrote to the file is : %d\n", word);

   printf("\nPress any key to continue...");
   getch();
}

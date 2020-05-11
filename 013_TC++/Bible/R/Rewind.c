/*                         */
/* Program Name : rewind.c */
/*                         */

#include <stdio.h>
#include <conio.h>

void main()
{
   FILE *stream;
   char buffer[31];
   char *msg0 = "This is the message 0.";
   char *msg1 = "This is the message 1.";

   clrscr();
   if ((stream = fopen("test", "w+t")) == NULL) {
      printf("Cannot create file 'test'.\n");
      exit(0);
   }

   printf("Write the first message '%s' to file 'test'...\n", msg0);
   fprintf(stream , msg0);

   printf("Rewind the file pointer to the beginning of the file...\n");
   rewind(stream);

   printf("Write the second message '%s' to file 'test'...\n", msg1);
   fprintf(stream , msg1);

   rewind(stream);
   printf("The last content of file is :\n");
   fgets(buffer, 31, stream);
   printf(buffer);

   printf("\nPress any key to continue...");
   getch();
}

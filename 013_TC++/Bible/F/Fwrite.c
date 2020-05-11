/*                         */
/* Program Name : fwrite.c */
/*                         */

#include <stdio.h>
#include <conio.h>

struct stdnt {
   char name[10];
   int  score;
};

void main()
{
   FILE *outfile;
   struct stdnt student;

   strcpy(student.name, "Jerry");
   student.score = 80;

   clrscr();
   if ((outfile = fopen("test", "r+t")) == NULL) {
      printf("Cannot create file 'test'.\n");
      exit(0);
   }

   printf("Write the record to file 'test'...\n");
   fwrite(&student, sizeof(struct stdnt), 1, outfile);

   fseek(outfile, 0L, SEEK_SET);
   fread(&student, sizeof(struct stdnt), 1, outfile);
   printf("The contents of the file 'test'...\n");
   printf("Student name  : %s\n", student.name);
   printf("Student score : %d\n", student.score);
   fclose(outfile);

   printf("\nPress any key to continue...");
   getch();
}

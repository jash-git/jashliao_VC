/*                        */
/* Program Name : write.c */
/*                        */

#include <stdio.h>
#include <conio.h>
#include <fcntl.h>
#include <io.h>

struct stdnt {
   char name[10];
   int  score;
};

void main()
{
   int handle;
   struct stdnt student;

   strcpy(student.name, "Jerry");
   student.score = 80;

   clrscr();
   if ((handle = open("test", O_CREAT | O_TEXT | O_RDWR)
       ) == -1) {
      printf("Cannot create file 'test'.\n");
      exit(0);
   }

   printf("Write the record to file 'test'...\n");
   write(handle, &student, sizeof(struct stdnt));

   lseek(handle, 0L, SEEK_SET);
   read(handle, &student, sizeof(struct stdnt));
   printf("The contents of the file 'test'...\n");
   printf("Student name  : %s\n", student.name);
   printf("Student score : %d\n", student.score);
   close(handle);

   printf("\nPress any key to continue...");
   getch();
}

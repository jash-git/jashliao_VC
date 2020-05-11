/*                            */
/*  Program Name: _d_write.c  */
/*                            */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

struct stdnt {
   char name[10];
   int  score;
};

void main()
{
   int handle;
   unsigned count;
   struct stdnt student;

   strcpy(student.name, "Jerry");
   student.score = 80;

   clrscr();
   printf("Creat file 'test'...\n");
   if (_dos_creat("test", _A_NORMAL, &handle) != 0) {
      printf("Cannot create file 'test'.\n");
      exit(0);
   }

   printf("Write the record to file 'test'...\n");
   if (_dos_write(handle, &student, sizeof(struct stdnt), &count) != 0)
      printf("Write error occured!\n");
   else {
      printf("Total %d bytes written.\n", count);
      printf("Reading from the file 'test'...\n");
      lseek(handle, 0L, SEEK_SET);
	  if (_dos_read(handle, &student, sizeof(struct stdnt), &count) != 0)
         printf("Read error occured!\n");
	  else {
         printf("The contents of the file 'test'...\n");
         printf("Student name  : %s\n", student.name);
         printf("Student score : %d\n", student.score);
      }
   }
   _dos_close(handle);

   printf("\nPress any key to continue...\n");
   getch();
}

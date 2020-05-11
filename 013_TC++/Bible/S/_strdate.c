
/*                          */
/* Program Name: _strdate.c */
/*                          */
#include <time.h>
#include <stdio.h>
void main(void)
{
  char buffer_date[9];
  _strdate(buffer_date);
  printf("Date: %s\n",buffer_date);
}


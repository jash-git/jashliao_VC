
/*                          */
/* Program Name: _strtime.c */
/*                          */
#include <time.h>
#include <stdio.h>
void main(void)
{
  char buffer_time[9];
  _strtime(buffer_time);
  printf("Time: %s\n",buffer_time);
}


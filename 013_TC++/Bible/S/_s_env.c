/*                          */
/*  Program Name: _s_env.c  */
/*                          */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
   char FileNm[13], VarNm[80], Path[256];

   printf("Please input a filename you to search: ");
   strupr(gets(FileNm));

   printf("Please input a environment variable  : ");
   strupr(gets(VarNm));

   _searchenv(FileNm, VarNm, Path);
   if(Path[0] != '\0')
      printf("%s in %s.\n", FileNm, Path);
   else
      printf("%s not found!.\n", FileNm);
}

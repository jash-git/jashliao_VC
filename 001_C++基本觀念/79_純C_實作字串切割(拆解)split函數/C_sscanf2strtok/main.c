#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
strtok 是一個可快速切割字串的函數
另外sscanf也是可以用來拆解字串，但是用法就沒有strtok方便
*/
int main ()
{
    char str[] ="- This, a sample string.";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ,.-");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }
    return 0;
}

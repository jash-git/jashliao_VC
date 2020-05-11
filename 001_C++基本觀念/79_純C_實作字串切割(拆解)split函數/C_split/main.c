#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 void split(char **arr, char *str, const char *del)
 {
    char *s = strtok(str, del);
    while(s != NULL)
    {
        *arr++ = s;
        s = strtok(NULL, del);
    }
}
int main ()
{
    char str[] ="10,20,30";
    const char *del = ",";
    char *arr[3];
    split(arr, str, del);
    int i=0;
    while(i<3)
        printf("%s\n", *(arr+i++));

    return 0;
}

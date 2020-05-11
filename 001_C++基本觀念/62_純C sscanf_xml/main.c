#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("Hello world!\n");
    FILE *pf;
    char buf[513];
    char buf0[100],buf1[100];
    pf=fopen("123.xml","r");
    int i=1;
    while(fgets(buf,512,pf) != NULL)
    {

        switch(i)
        {
            case 3:
            case 4:
            case 5:
            case 6:
                printf("%i\t%s\n",i,buf);
                sscanf(buf," <%[^>]>%[^<]",buf0,buf1);//sscanf(buf,"<%[^>]>%[^<]",buf0,buf1);
                printf("%s:\t%s\n",buf0,buf1);
                break;

        }
        i++;
    }
    fclose(pf);
    return 0;
}

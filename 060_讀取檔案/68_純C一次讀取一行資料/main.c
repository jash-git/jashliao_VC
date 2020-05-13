#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("Hello world!\n");
    FILE *pf;
    int i=0;
    char buf[513];
    char buf0[100];
    pf=fopen("123.xml","r");
    while(fgets(buf,512,pf) != NULL)
    {
        printf("%d\t%s\n",i,buf);
        i++;
        switch(i)
        {
            //sscanf("name:john age:40 tel:082-313530", "name:%s age:%d tel:%s", name, &age, tel);
            case 2:
                sscanf(buf, "<Account>%s</Account>",buf0);
                printf("%d\t%s\n",i+1,buf0);
                break;
            case 3:
                sscanf(buf, "<Password>%s</Password>",buf0);
                printf("%d\t%s\n",i+1,buf0);
                break;
            break;
            case 4:
                sscanf(buf, "<ChannelName>%s</ChannelName>",buf0);
                printf("%d\t%s\n",i+1,buf0);
                break;
            break;
            case 5:
                sscanf(buf, "<Url>%s</Url>",buf0);
                printf("%d\t%s\n",i+1,buf0);
                break;
            break;
        }
    }
    fclose(pf);
    return 0;
}

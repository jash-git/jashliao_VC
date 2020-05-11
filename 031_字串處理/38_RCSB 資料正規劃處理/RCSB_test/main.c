#include <stdio.h>
#include <stdlib.h>
char buf[513];

void RCSB_normalize()
{
    char chara01[10];
    char chara02[10];
    char chara03[10];
    char chara04[10];
    char chara05[10];
    char chara06[10];
    char chara07[10];
    char chara08[10];
    char chara09[10];
    char chara10[10];
    char chara11[10];
    char chara12[10];
    char chdat[255];
    char last_b=0,now_b=0;
    int j=0;
    int i=0;
    for(i=0;i<sizeof(buf)/sizeof(char);i++)
    {
        now_b=buf[i];
        if(now_b!=32)
        {
            //save
            chdat[j]=now_b;
            j++;
        }
        else if(now_b==32&&last_b!=32)
        {
            chdat[j]=',';
            j++;

        }
        last_b=now_b;
    }
    chdat[j]='\0';
    if(chdat[0]=='A')
    {
        printf("%s\n",chdat);
        sscanf(chdat, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],",chara01,chara02,chara03,chara04,chara05,chara06,chara07,chara08,chara09,chara10,chara11,chara12);
        printf("%s\n",chara09);
        printf("%s\n",chara10);
        printf("%s\n",chara11);
    }
}
int main()
{
    FILE *pfin;

    //char buf0[100];

    pfin=fopen("QLC.txt","r");

    while(fgets(buf,512,pfin) != NULL)
    {
        RCSB_normalize();
    }
    fclose(pfin);
    return 0;
}

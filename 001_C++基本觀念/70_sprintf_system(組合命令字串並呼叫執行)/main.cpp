#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char buffer [1000];
    char Data[500];
    int n;
    FILE *pf;
    pf=fopen("world_channel.url","r");
    if(pf!='\0')
    {
        fgets(Data,499,pf);
    }
    n=strlen(Data);
    Data[(n-1)]='\0';
    fclose(pf);
    n=sprintf (buffer, "wget \"%s\" -O 123.txt", Data);
    system(buffer);
    cout << buffer << endl;
    return 0;
}

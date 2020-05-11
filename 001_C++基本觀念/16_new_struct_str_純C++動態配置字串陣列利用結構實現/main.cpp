#include <cstdlib>
#include <cstring>
#include <iostream>
struct FileData{
       int intnumber;
       char chrData[500];
};
using namespace std;

int main(int argc, char *argv[])
{
    FileData *FD;
    FD=new FileData[2];
    (FD+0)->intnumber=0;
    strcpy((FD+0)->chrData,"superjoeliao");
    (FD+1)->intnumber=1;
    strcpy((FD+1)->chrData,"jash.liao");
    int i=0;
    for(i=0;i<2;i++)
    {
       cout<<(FD+i)->intnumber<<":"<<(FD+i)->chrData<<"\n";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

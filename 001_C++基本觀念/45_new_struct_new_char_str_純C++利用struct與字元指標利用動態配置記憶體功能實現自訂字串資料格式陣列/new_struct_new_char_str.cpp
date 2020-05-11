#include <cstdlib>
#include <cstring>
#include <iostream>
struct FileData{
       int intnumber;
       char *chrData;
};
using namespace std;

int main(int argc, char *argv[])
{
    FileData *FD;
    FD=new FileData[2];
    (FD+0)->intnumber=0;
	(FD+0)->chrData=new char[100];
    strcpy((FD+0)->chrData,"superjoeliao");
    (FD+1)->intnumber=1;
	(FD+1)->chrData=new char[100];
    strcpy((FD+1)->chrData,"jash.liao");
    int i=0;
    for(i=0;i<2;i++)
    {
       cout<<(FD+i)->intnumber<<":"<<(FD+i)->chrData<<"\n";
    }
	(FD+0)->chrData[0]='S';
	(FD+0)->intnumber=2;
	(FD+1)->chrData[0]='J';
	(FD+1)->intnumber=3;
    for(i=0;i<2;i++)
    {
       cout<<(FD+i)->intnumber<<":"<<(FD+i)->chrData<<"\n";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

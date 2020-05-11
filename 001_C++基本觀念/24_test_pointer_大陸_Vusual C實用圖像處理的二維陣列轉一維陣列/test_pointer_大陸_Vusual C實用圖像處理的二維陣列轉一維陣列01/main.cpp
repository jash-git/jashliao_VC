#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int a[3][4];
    int i,j,k;
    int *pa;
    int xsize,ysize;
    k=0;
    xsize=3;
    ysize=4;
    for(i=0;i<xsize;i++)
       for(j=0;j<ysize;j++)
       {
          a[i][j]=++k;
       }
    for(i=0;i<xsize;i++)
    {
       for(j=0;j<ysize;j++)
       {
          cout<<a[i][j]<<"\t";
       }
       cout<<"\n";
    }
    cout<<"////////////////////////\n";
    pa=(int *)a;
    for(j=0;j<ysize;j++)
    {
       for(i=0;i<xsize;i++)
       {
          //cout<<*(pa+j*xsize+i)<<"\t";//書上的寫法且ㄧ定要先Y在X 
          cout<<*(pa+j+i*(j+1))<<"\t";//網路上的寫法 
       }
       cout<<"\n";
    }       
    system("PAUSE");
    return EXIT_SUCCESS;
}

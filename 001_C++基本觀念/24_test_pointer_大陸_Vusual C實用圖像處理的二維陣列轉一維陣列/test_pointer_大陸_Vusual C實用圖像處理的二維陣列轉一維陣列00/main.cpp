#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int a[3][3];
    int i,j,k;
    int *pa;
    int xsize,ysize;
    k=0;
    xsize=3;
    ysize=3;
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
          cout<<*(pa+j*xsize+i)<<"\t";
       }
       cout<<"\n";
    }       
    system("PAUSE");
    return EXIT_SUCCESS;
}

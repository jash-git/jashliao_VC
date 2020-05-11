#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int **intdata;//方陣
    int M;//方陣大小 
    int i,j;//迴圈旗標
    int intarry1;//一維陣列長度 
    int *intadd_del;//遞增或第減陣列
    int *intvalue;//每一次要寫的各數
    int intinsert;
    bool blnx_y_move=false;//Y=false;X=true
    cout<<"輸入方陣大小"<<"\t";
    cin>>M;
    ////////////////////////
    intdata=new int*[M];
    for(i=0;i<M;i++)
    {
       intdata[i]=new int[M];
    }
    for(i=0;i<M;i++)
    { 
       for(j=0;j<M;j++)
       {
          *(*(intdata+i)+j)=0;
          cout<<*(*(intdata+i)+j)<<"\t";
       }
       cout<<"\n";
    }
    /////////////////////////
    intarry1=(M-1)*2+1;
    intadd_del=new int[intarry1];
    j=0;
    for(i=0;i<intarry1;i++)
    {
       j++;
       if(j==1||j==2)
          intadd_del[i]=1;
       if(j==3||j==4)
          intadd_del[i]=-1;
       if(j==4)
          j=0;
       cout<<intadd_del[i]<<"\t";         
    }
    cout<<"\n";
    //////////////////////////
    intvalue=new int[intarry1];
    intvalue[0]=M;
    cout<<intvalue[0]<<"\t";
    intinsert=M-1;
    for(i=1;i<intarry1;i++)
    {
       intvalue[i]=intinsert;
       if(i%2==0)
          intinsert--;
       cout<<intvalue[i]<<"\t";   
    }
    cout<<"\n";
    ///////////////////////////
    int x,y,z;
    x=0;
    y=-1;//重點 
    z=0;
    int data=0;
    intarry1=(M-1)*2+1;
    cout<<intarry1<<"\n";
    for(i=0;i<intarry1;i++)
    {
       intinsert=intvalue[i];//每一個小迴圈的次數 
       z=intadd_del[i];
       for(j=0;j<intinsert;j++)
       {
          data++;
          if(blnx_y_move==false)//Y=false
          {
             y+=z;
          }
          else//X=true
          {
             x+=z;
          }
          *(*(intdata+x)+y)=data;
       }
       blnx_y_move=!blnx_y_move;
    }
    //////////////////////////////////// 
    for(i=0;i<M;i++)
    { 
       for(j=0;j<M;j++)
       {
          cout<<*(*(intdata+i)+j)<<"\t";
       }
       cout<<"\n";
    } 
    system("PAUSE");
    return EXIT_SUCCESS;
}

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
 int a,bit=0;
 int b[99];
 cin>>a;
 while(a>1){
  b[bit]=a%2;
  bit++;
  a=(int)a/2;
 }
    b[bit]=a;
 for(int i=bit;i>=0;i--)cout<<b[i];
 cout<<endl<<"²q¼Æ¦r"<<endl;
    srand(time(NULL));
 int c[4],d[4],e,ga,gb;
 for(i=0;i<4;i++)c[i]=rand()%10;
    do{
     cin>>e;
        d[0]=(int)(e/1000);
  e-=d[0]*1000;
  d[1]=(int)(e/100);
  e-=d[1]*100;
  d[2]=(int)(e/10);
  e-=d[2]*10;
  d[3]=e;
  ga=0;gb=0;
  for(i=0;i<4;i++){
   for(int j=0;j<4;j++){
    if(d[i]==c[j]){
     if(i==j)ga++;else gb++;
    }
   }
  }
  cout<<ga<<"A"<<gb<<"B"<<endl;
 }while(d[0]!=c[0]||d[1]!=c[1]||d[2]!=c[2]||d[3]!=c[3]);
 cout<<"Bingo!"<<endl;
 system("pause");
 return 0;
}

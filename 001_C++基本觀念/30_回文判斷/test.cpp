                    /*回文判斷   作者:smilediao*/
#include <iostream.h>
#include<string.h>
void main()
{
     int a=1;
     char smile[20];                   //定義最大字串的長度是20
     cout<<"請輸入你判斷的字串:";
     cin>>smile;
     int n=strlen(smile);               //判斷你輸入的字串的長度
     char *end=&smile[n-1],*start=&smile[0];
     for (;start<=end;start++,end--)
     {
     if (*end!=*start)                 //判斷對稱字元是否相同
     a=0;                         //不相同時將0付值給a
     }
     if (a==1)
     cout<<smile<<"是回文!"<<endl;
     else 
     cout<<smile<<"不是回文!"<<endl;
}
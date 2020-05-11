#include <iostream>
#include <stdio.h>>

using namespace std;

int main()
{
    char string1[]={'W','e','l','c','o','m','e'};
    char string2[]="Welcome";//系統會自動加上\0
    char StringArray[][6] ={"human","dog","cat","bird"};//C語言字串陣列，字串長度一定要定義(PS 這也是二維陣列在函數傳遞時為何要指定的特性)
    int a,b,c;
    a=sizeof(string1);
    b=sizeof(string2);
    c=sizeof(StringArray)/6;//計算字串陣列個數
    printf("%s,%d\n",string1,a);
    printf("%s,%d\n",string2,b);
    printf("%d\n",c);
    for(int i=0;i<c;i++)//依序印出字串陣列
    {
        printf("%s\n",StringArray[i]);
    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 1

int main()
{
    char chrValue;
    chrValue='\0';
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout<<"判斷字元種類\n";
        cout<<"請輸入要判斷的字元: \t";
        cin>>chrValue;
        if((chrValue>=48)&&(chrValue<=57))
        {
            cout<<"字元種類=數字\n";
        }
        else if((chrValue>=97)&&(chrValue<=122))
        {
            cout<<"字元種類=小寫英文\n";
            chrValue=chrValue-32;
            cout<<"小寫轉大寫後的結果:\t"<<chrValue<<endl;

        }
        else if((chrValue>=65)&&(chrValue<=90))
        {
            cout<<"字元種類=大寫英文\n";
            chrValue=chrValue+32;
            cout<<"大寫轉小寫後的結果:\t"<<chrValue<<endl;
        }
        else
        {
            cout<<"字元種類=其它\n";
        }
    #else
        printf("C mode:\n");
        printf("判斷字元種類\t");
        scanf("%c",&chrValue);
        if((chrValue>=48)&&(chrValue<=57))
        {
            printf("字元種類=數字\n");
        }
        else if((chrValue>=97)&&(chrValue<=122))
        {
            printf("字元種類=小寫英文\n");
            chrValue=chrValue-32;
            printf("小寫轉大寫後的結果:\t%c\n",chrValue);
        }
        else if((chrValue>=65)&&(chrValue<=90))
        {
            printf("字元種類=大寫英文\n");
            chrValue=chrValue+32;
            printf("大寫轉小寫後的結果:\t%c\n",chrValue);
        }
        else
        {
            printf("字元種類=其它\n");
        }
    #endif
    return 0;
}

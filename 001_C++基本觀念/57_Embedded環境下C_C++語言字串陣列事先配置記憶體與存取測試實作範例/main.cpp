#include <iostream>

using namespace std;
char *Embedded_C_String_Arry[]
{
  "Embedded",//0
  "環境下",
  "C/C++語言",
  "字串陣列",
  "事先配置記憶體",
  "與存取測試",//5
  "實作範例",
};
int String_Arry_count=7;//手動填寫
int main()
{
    int i;
    char **get_C_String_Arry;
    get_C_String_Arry=(char **)Embedded_C_String_Arry;

    for(i=0;i<String_Arry_count;i++)
    {
        cout << get_C_String_Arry[i];
    }
    cout << endl;
    return 0;
}

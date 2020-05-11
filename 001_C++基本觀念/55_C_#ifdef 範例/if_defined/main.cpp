#include <iostream>
//#define Compiled 1
//#define Compiled 0
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    #if defined(Compiled)//有定義就會動
        cout << "#if defined(Compiled)" << endl;
        #if(Compiled)//有定義且為真就會動
            cout << "#if(Compiled)" << endl;
            for(int i=0;i<9;i++)
                cout << "Hello world!" << endl;
        #endif
    #endif

    return 0;
}

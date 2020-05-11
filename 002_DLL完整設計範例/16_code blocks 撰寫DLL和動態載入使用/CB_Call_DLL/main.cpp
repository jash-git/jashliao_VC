#include <iostream>
//--
//http://www.infernodevelopment.com/simple-c-dll-loading-message-box
#include<windows.h>
typedef  void (*FuncPtr)(LPCTSTR);
//--
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    FuncPtr myDllFunc;
    BOOL linkSuccessFlag = FALSE, fFreeResult;
    HINSTANCE hinstLib = LoadLibrary("CB_DLL.dll");

    if (hinstLib != NULL) {
        myDllFunc = (FuncPtr) GetProcAddress(hinstLib, "SomeFunction");

        if (myDllFunc != NULL)
        {
            linkSuccessFlag = TRUE;
            myDllFunc("Hello, World! by jash");
        }
        fFreeResult = FreeLibrary(hinstLib);
    }
    system("pause");
    return 0;
}

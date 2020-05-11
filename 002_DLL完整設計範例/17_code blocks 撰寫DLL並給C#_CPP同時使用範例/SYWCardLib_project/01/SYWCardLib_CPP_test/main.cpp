#include <iostream>
#include <cstdio>

using namespace std;

//SYWCardLib_H start
#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

double DLL_EXPORT Add(double a, double b);//test_API
#ifdef __cplusplus
}
#endif
//SYWCardLib_H end

int main()
{
    cout << "Hello world!" << endl;
    cout << "3.1+6.9="<<Add(3.1,6.9)<< endl;

    cout <<"Press Enter key to continue..."<< endl;
    fgetc(stdin);
    return 0;
}

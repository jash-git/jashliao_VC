#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

int DLL_EXPORT initVar();
int DLL_EXPORT setVar(int a,int b);
int DLL_EXPORT addVar();
#ifdef __cplusplus
}
#endif

int main()
{
    initVar();
    setVar(5,4);
    cout << "5+4=" <<addVar()<< endl;
    system("pause");
    return 0;
}

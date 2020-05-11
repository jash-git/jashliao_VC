#include <iostream>

using namespace std;

//---
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
//---
int main()
{
    cout << "Hello world!" << "\t" <<Add(10,15)<< endl;
    return 0;
}

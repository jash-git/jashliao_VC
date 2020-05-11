#include "main.h"

#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;
// a sample exported function
static vector<int> g_v1;

// http://mropengate.blogspot.tw/2015/07/cc-vector-stl.html
int DLL_EXPORT initVar()
{
    g_v1.assign(2, 0); // v1 設 2 個 0
    return 0;
}
int DLL_EXPORT setVar(int a,int b)
{
    int data[2]={0,0};
    data[0]=a;
    data[1]=b;
    g_v1.assign(data, data+2); // 複製 array 前2個元素到 v1
    return 0;
}
int DLL_EXPORT addVar()
{
    return (g_v1[0]+g_v1[1]);
}
void DLL_EXPORT SomeFunction(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);

}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}

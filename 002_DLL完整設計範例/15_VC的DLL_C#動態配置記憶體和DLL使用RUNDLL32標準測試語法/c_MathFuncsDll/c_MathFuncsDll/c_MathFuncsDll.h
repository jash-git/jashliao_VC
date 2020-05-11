#ifndef c_MathFuncsDll_H
#define c_MathFuncsDll_H

#include <stdio.h>

typedef struct _Data
{
 bool bData;
 int nData;
 char strData[256];
} Data;

struct Bar
{
	public :
		int id;
		char* name;
};
extern "C"{
  __declspec(dllexport) int Test_AllocData(int count, Data*& res);
  __declspec(dllexport) int Test_FreeData(Data* d);
  __declspec(dllexport) int GetBar(Bar& bar);
  __declspec(dllexport) int SaveByteArray(BYTE * pArray, int nSize);
    // Returns a + b
  __declspec(dllexport) double Add(double a, double b);

  // Returns a - b
  __declspec(dllexport) double Subtract(double a, double b);

  // Returns a * b
  __declspec(dllexport) double Multiply(double a, double b);

  // Returns a / b
  __declspec(dllexport) double Divide(double a, double b);
  __declspec(dllexport) void EntryPoint(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow);
    }
#endif
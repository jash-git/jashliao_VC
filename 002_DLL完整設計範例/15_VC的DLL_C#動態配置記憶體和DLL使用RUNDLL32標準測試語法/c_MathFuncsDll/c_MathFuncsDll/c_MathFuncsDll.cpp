// c_MathFuncsDll.cpp : 定義 DLL 應用程式的匯出函式。
//

#include "stdafx.h"
#include <stdio.h>
#include "c_MathFuncsDll.h"

int Test_AllocData(int count, Data*& res)
{
	res = new Data[count];
	for(int i=0 ; i<count ; i++)
	{
		/*
		http://falldog7.blogspot.tw/2015/01/c-sharp-allocate-structure-buffer-array-dll.html
		*/
		res[i].bData = true;
		res[i].nData = 500 + i;
		sprintf_s(res[i].strData, "Test_AllocData(%d)", i);
	}
	return 0;
}
int Test_FreeData(Data* d)
{
	/*
	http://falldog7.blogspot.tw/2015/01/c-sharp-allocate-structure-buffer-array-dll.html
	*/
	if(d)
	{
		delete [] d;
	}
	return 0;
}
int GetBar(Bar& bar)
{
	/*
	http://www.cnblogs.com/yukaizhao/archive/2011/04/27/csharp_call_cpp_class_struct.html
	*/
	FILE *pf;
	pf=fopen("data.txt","a");
	fprintf(pf,"bar.id=%d\tbar.name=%s\n",bar.id,bar.name);
	fprintf(pf,"\n");
	fclose(pf);
	bar.id = 10;
    bar.name = "hi bar 中文了";
	return 0;
}
int SaveByteArray(BYTE * pArray, int nSize)
{
	/*
	https://social.msdn.microsoft.com/Forums/en-US/32f1a857-91d6-472d-b333-469ed7f6f6dd/passing-a-byte-array-to-a-c-dll-from-c?forum=csharplanguage
	*/
	FILE *pf;
	pf=fopen("data.txt","a");
	for (int i=0; i<nSize; i++)
	{
        fprintf(pf,"%d,", pArray[i]);
	}
	fprintf(pf,"\n");
	fclose(pf);
	return 0;
}
double Add(double a, double b)
{
    return a + b;
}

double Subtract(double a, double b)
{
    return a - b;
}

double Multiply(double a, double b)
{
    return a * b;
}

double Divide(double a, double b)
{
    if (b == 0)
    {
        return -1;
    }

    return a / b;
}
void EntryPoint(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow)//for RUNDLL32.EXE <dllname>,<entrypoint> <optional arguments>
{
	//https://support.microsoft.com/zh-tw/kb/164787
	/*
	原文說明

		RUNDLL.EXE SETUPX.DLL,InstallHinfSection 132 C:\WINDOWS\INF\SHELL.INF
	hwnd = (parent window handle)
	hinst = HINSTANCE of SETUPX.DLL
	lpszCmdLine = "132 C:\WINDOWS\INF\SHELL.INF"
	nCmdShow = (whatever the nCmdShow was passed to CreateProcess)
	*/
	//測試:RUNDLL32.EXE c_MathFuncsDll.dll,EntryPoint jash.liao
	FILE *pf;
	pf=fopen("123.txt","w");
	fprintf(pf,"%s",lpszCmdLine);
	fclose(pf);
}


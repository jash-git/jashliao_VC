// VirtualFunDemo1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
	[ base ]
	   |
	[ derived ]

     base 是否可以呼叫derived class 的function
*/
class CommPlatForm 
{
public:
	int BaseData;
	CommPlatForm()
	{
		BaseData=0;
	}
	void Algorithm(int data)
	{
		SetData(data);	// <-------------base 是否可以呼叫derived class 的function
	}
	/*
	    答案: Base 中的function 只能呼叫自己有定義的function.
		      若要呼叫Derived function,只能靠virtual function
	*/
	virtual void SetData(int data)
	{
		BaseData=data;
	}
	
};
class WindowsPlatForm:public CommPlatForm
{

public:
	int DerivedData;
	WindowsPlatForm():CommPlatForm()
	{
		DerivedData=0;
	}
	void SetData(int data)                //WindowsPlatForm 平台的SetData
	{
		DerivedData=data;
	}
};

int main(int argc, char* argv[])
{
	WindowsPlatForm MyWinAp;

	CommPlatForm *p=&MyWinAp;             // 利用共用平台執行
	p->Algorithm(1234);

    // MyWinAp.Algorithm(1234); 
    return 0;
}


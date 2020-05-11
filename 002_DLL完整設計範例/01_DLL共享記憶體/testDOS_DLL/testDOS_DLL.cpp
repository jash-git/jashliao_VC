#include <iostream>
int __declspec(dllexport) __stdcall jashGetValue ();
void __declspec(dllexport) __stdcall jashSetValue (int a);
int __declspec(dllexport) __stdcall KbdHookProc (int a, int b);
using namespace std;
void main(void)
{
	int a,b,c,d;
	a=10;
	b=30;
	c=KbdHookProc(a,b);
	cout << "c = "<< c <<"\n";
	jashSetValue(c);
	d=jashGetValue();
	cout << "d = "<< d <<"\n";
	system("pause");
}
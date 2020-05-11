#include <iostream>
#include <windows.h>
using namespace std;
void main()
{
	char a[16]={"\0"};
	int i=0;
	size_t length;
	DWORD data=0x75E03C61;
	//DWORD data01=0xFFFFFFFF;
	ltoa(data,a,16);
	cout << a << endl;
	length = strlen(a);
	for(i=0;i<length;i++)
		cout << a[i] << endl;
	system("pause");
}
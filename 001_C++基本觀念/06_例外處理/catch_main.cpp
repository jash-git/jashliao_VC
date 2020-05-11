#include <iostream>
using namespace std;
void main()
{
	int a=0;
	int b=0;
	float k=0.0f;
	cout <<"輸入年薪:";
	cin >>a;
	cout <<"輸入幾個月";
	cin >>b;
	try
	{
		if(a==0)
			throw 0;
		if(b==0)
			throw 1;
		cout<<"月薪= "<<(k=(float)a/(float)b)<<"\n";
	}
	catch(int err)
	{
		if(err==0)
			cout <<"沒有薪水，會餓死"<<"\n";
		else
			cout <<"搶來的，會判刑"<<"\n";
	}
}
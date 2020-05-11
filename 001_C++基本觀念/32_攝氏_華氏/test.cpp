#include <iostream>
using namespace std;
float oc(float i)     //攝氏轉華氏函數
{
	i = i * 9 / 5 + 32;
	return i;
}
float fc(float i)     //華氏轉攝氏函數
{
	i = (i - 32) * 5 / 9;
	return i;
}
void main()
{
	float fltInput,fltOutput;
	cout<<"輸入轉換數字"<<"\t";
	cin>>fltInput;
	fltOutput=oc(fltInput);
	cout<<"攝氏轉華氏 "<<fltOutput<<"\n";
	fltOutput=fc(fltInput);
	cout<<"華氏轉攝氏 "<<fltOutput<<"\n";

}
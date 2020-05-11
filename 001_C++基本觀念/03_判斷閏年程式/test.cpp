#include <iostream>
using namespace std;
void main(void)
{
	int intYears=0;
	cout<<"輸入要判斷的年份   ";
	cin >>intYears;
	if((intYears%4==0 && intYears%100!=0)||(intYears%400==0))
		cout<<"輸入是閏年"<<"\n";
	else
		cout<<"輸入不是閏年"<<"\n";
}
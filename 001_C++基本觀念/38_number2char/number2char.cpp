#include <iostream>
using namespace std;
char chrData;
void number2char(int intdata)
{
	if((intdata>=0) &&(intdata<10))
	{
		chrData=(48+intdata);//48->'0'
	}
	else
	{
		chrData=(97+(intdata-10));//97->a，數字10->a
	}
}
void main()
{
	int i;
	cout <<"輸入轉換數字"<<"\t";
	cin >>i;
	if(i<36)//0~35
	{
		number2char(i);
		cout <<"轉換結果"<<"\t"<<chrData<<"\n";
	}
	else
	{
		cout <<"不再轉換範圍"<<"\n";
	}
}
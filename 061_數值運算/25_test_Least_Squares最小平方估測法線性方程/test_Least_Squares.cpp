#include <iostream>
using namespace std;
void main()
{
	int i=0;
	int intnumber=0;
	double *pdblInput,*pdblOutput;
	double dblDenominator=0.0,dblNumerator=0.0,dblAnswer=0.0;
	cout <<"輸入資料比數"<<"\n";
	cin >>intnumber;
	pdblInput=new double [intnumber];
	pdblOutput=new double [intnumber]; 
	cout <<"請依序輸入每一組實驗數據(輸入 輸出)"<<"\n";
	for (i=0;i<intnumber;i++)
	{
		cout <<"請輸入第"<<(i+1)<<"組"<<"\n";
		cin >>pdblInput[i]>>pdblOutput[i];
		dblDenominator+=pdblInput[i]*pdblInput[i];
		dblNumerator+=pdblInput[i]*pdblOutput[i];
	}
	dblAnswer=dblNumerator/dblDenominator;
	cout<<"最佳參數解為Y="<<dblAnswer<<"X"<<"\n";
}
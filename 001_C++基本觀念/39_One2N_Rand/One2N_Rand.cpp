#include <iostream>
#include <stdlib.h> //srand() ,rand() ,system()
#include <time.h>   //time()
using namespace std;
/////////////////////////////////////////////////
int *DataArray;
void Rand_One2N(int intcount,int intrange,int intstart=1)
{
	int i;
	srand(time(NULL));
	for(i=0; i<intcount; i++)
	{
		DataArray[i]=intstart+(rand()%intrange);
	}
}
/////////////////////////////////////////////////
int main()
{
	int j;
	int n;
	cout <<"設定亂數個數"<<"\t";
	cin >>j;
	cout <<"設定範圍(1到N)"<<"\t";
	cin >>n;
	//////////////////////////////////
	DataArray=new int[j];
	//int rand ( void );
	//( value % 100 ) is in the range 0 to 99
	//( value % 100 + 1 ) is in the range 1 to 100
	//Rand_One2N(j,n,0);//0~(N-1)
	Rand_One2N(j,n);//1~N
	for(int i=0;i<j;i++)
	{
		cout << DataArray[i] << endl;
	}
	//**********************
	delete []DataArray;
	//////////////////////////////////
	system("PAUSE"); 
	return 0;
}

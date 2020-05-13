#include <fstream.h>
#include <stdio.h>
class A
{
public:
	void getdata();
	void showdata();
	A();
private:
	int number;
	float d1;
	char str1[20];
};
A::A()
{
	number=0;
	d1=0.0f;
}
void A::getdata()
{
	cout<< "input NO.";
	cin >> number;
	cout<< "Input a vale->";
	cin >> d1;
	cout<< "Input a string->";
	cin >> str1;
}
void A::showdata()
{
	cout <<"show NO.";
	cout <<number<<"\n";
	cout <<"show the value:";
	cout <<d1<<"\n";
	cout <<"show the string:";
	cout <<str1<<"\n";
}
void main()
{
	int number,i;
	A *data1;
	fstream File,File1;
	File.open("data.dat",ios::trunc|ios::out);
	cout <<"Input a value";
	cin >>number;
	data1=new A[number];
	File.write((char*)&number,sizeof(number)); 
	for(i=0;i<number;i++)
	{
		(data1+i)->getdata(); 
		File.write((char*)(data1+i),sizeof(A));
	}
	delete data1;
	File.close();
	i=0;
	number=0;
	File1.open("data.dat",ios::in);
	File1.read((char*)&number,sizeof(number));
	cout<<"amount:"<< number<<"\n";
	data1=new A[number];
	for(i=0;i<number;i++)
	{
		File1.read((char*)(data1+i),sizeof(A));
		(data1+i)->showdata(); 
	}
	File1.close();
	delete data1;
}

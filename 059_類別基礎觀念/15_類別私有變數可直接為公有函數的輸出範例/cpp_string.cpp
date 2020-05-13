#include <iostream>
#include <string>
/*
標準C++字串使用

*/
using namespace std;
class Student{
	public:
		Student(string name,string id,int english,int math,int chinese)
		{
			stname=name;
			stid=id;
			stenglish=english;
			stmath=math;
			stchinese=chinese;
		}
		string  getname()
		{
			return  stname;
		}
		string getid()
		{
			return stid;
		}
		int getchinese()
		{
			return stchinese;
		}
		int getmath()
		{
			return stmath;
		}
		int getenglish()
		{
			return stenglish;
		}
		int sum()
		{
			int sum;
			sum=getchinese()+getmath()+getenglish();
			return sum;
		}
	private:
		string stname;
		string stid;
		int stchinese;
		int stmath;
		int stenglish;
};
int main()
{
	Student student("john","U9624048",95,94,93);//constructor
	cout<<"the name:"<<student.getname()<<endl;
	cout<<"the id :"<<student.getid()<<endl;
	cout<<"the sum is :"<<student.sum()<<endl;
	system("pause");
	return 0;
}
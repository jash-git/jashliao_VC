/*
double GetValue()const;是確保值不會被修改
*/
#include <iostream>
using namespace std;
class test
{
	public :
		double x,y;
		test();
		void Calculate();
		void SetValue(double a,double b);
		double GetValue()const;
	protected:
		double z;
	private:
};
test::test()
{
	x=0;
	y=0;
}
void test::SetValue(double a,double b)
{
	x=a;
	y=b;
}
double test::GetValue() const
{	
	return z;
}
void test::Calculate()
{
	z=x+y;
}
void print(test &t)
{
	cout<< t.GetValue()<<"\n"; 
}
void main(void)
{
	test t1;
	t1.SetValue(20.0,300.0);
	t1.Calculate();
	print(t1);
}

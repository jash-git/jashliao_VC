#include <iostream>
using namespace std;
/*
ノ患癹よΑ―程そ计㎝―ㄤ程そ计
*/
int gcd_1(int a,int b)//―程そ计_1_劣锣搭猭
{
	if(a==b)
		return a;
	if(a>b)
		return gcd_1(a-b,b);
	return gcd_1(a,b-a);
}
int gcd_2(int a,int b)//―程そ计_2_劣锣埃猭
{
	int c=0;
	c=a%b;
	if(c==0)
		return b;
	return gcd_2(b,c);
}
int lcm(int a,int b)//―ㄤ程そ计
{
	return b/gcd_1(a,b)*a;
}
void main(void)
{
	int a,b,c;
	a=30,b=45;
	c=gcd_1(a,b);
	cout<<c<<"\t";
	c=gcd_2(a,b);
	cout<<c<<"\t";
	c=lcm(a,b);
	cout<<c<<"\t";

}
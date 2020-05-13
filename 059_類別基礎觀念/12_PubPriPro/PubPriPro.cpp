#include <stdio.h>
#include <iostream.h>
class father
{
public:
	int m_a;
	int getvalue();
	void setvalue(int a);
	father();
private:
	int m_b;
protected:
	int m_c;
};
int father::getvalue()
{
	return m_b;
}
void father::setvalue(int a)
{
	m_b=a;
}
father::father()
{
	m_a=0;
	m_b=0;
	m_c=0;
}
class child:public father
{
public :
	child();
	int getvalue();
	void setvalue(int a);
};
child::child() : father()
{
}
int child::getvalue()
{
	return m_c;
}
void child::setvalue(int a)
{
	m_c=a;
}
void main()
{
	int i;
	child c1;
	printf("%d\t%d\t%d\n",c1.m_a,c1.father::getvalue() ,c1.getvalue());  
	c1.m_a=10; 
	c1.setvalue(10);
	i=c1.getvalue();
	c1.father::setvalue(i);
	cout << c1.m_a << "\t"<< c1.father::getvalue()<< "\t" << c1.getvalue()<< "\n"; 
	
}
#include <stdio.h>
class Father
{
public:
	Father()
	{
	}
	~Father()
	{
	}
int FatherNumber;
};

class Mother
{
public:
	Mother()
	{
	}
	~Mother()
	{
	}
int MotherNumber;
};

class Son : public Father, public Mother
{
public:
	Son()
	{
	}
	~Son()
	{
	}
int SonNumber;
};

//使用Class的主程式部份(.cpp):
void main()
{
Father* pFather = new Son();
Mother* pMother = new Son();

delete ((Son*)pFather); // <= 執行時沒問題
delete ((Son*)pMother); // <= Debug Assertion Failed
} 
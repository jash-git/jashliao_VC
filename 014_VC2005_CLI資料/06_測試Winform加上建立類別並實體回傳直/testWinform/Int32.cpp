#include "StdAfx.h"
#include "Int32.h"

CInt32::CInt32(void)
{
	data=0;
}
CInt32::CInt32(int a)
{
	data=a;
}
CInt32% CInt32::operator+(CInt32 a)
{
	CInt32 temp;
	temp.data=data+a.data;
	return temp;
}
CInt32% CInt32::operator-(CInt32 a)
{
	CInt32 temp;
	temp.data=data-a.data;
	return temp;
}
CInt32% CInt32::operator*(CInt32 a)
{
	CInt32 temp;
	temp.data=data*a.data;
	return temp;
}
CInt32% CInt32::operator/(CInt32 a)
{
	CInt32 temp;
	temp.data=data/a.data;
	return temp;
}
CInt32% CInt32::operator+(int a)
{
	CInt32 temp;
	temp.data=data+a;
	return temp;
}
CInt32% CInt32::operator-(int a)
{
	CInt32 temp;
	temp.data=data-a;
	return temp;
}
CInt32% CInt32::operator*(int a)
{
	CInt32 temp;
	temp.data=data*a;
	return temp;
}
CInt32% CInt32::operator/(int a)
{
	CInt32 temp;
	temp.data=data/a;
	return temp;
}
void CInt32::operator++()
{
	data++;
}
void CInt32::operator--()
{
	data--;
}
void CInt32::operator+=(CInt32 a)
{
	data+=a.data; 
}
void CInt32::operator-=(CInt32 a)
{
	data-=a.data;
}
void CInt32::operator*=(CInt32 a)
{
	data*=a.data;
}
/*
void operator+=(int b)
{
	data+=b; 
}
void operator-=(int b)
{
	data-=b; 
}
void operator*=(int b)
{
	data*=b; 
}
void operator/=(int b)
{
	data/=b; 
}
*/
void CInt32::operator/=(CInt32 a)
{
	data/=a.data;
}
String^ CInt32::Int2ToString(void)
{

	return data.ToString();
}

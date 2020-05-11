#include "StdAfx.h"
#include "Int32.h"
#include <math.h>
#include <stdlib.h>
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
String^ CInt32::IntToString(void)
{

	return data.ToString();
}
String^ CInt32::Int10toInt2(void)
{
	double DValue,Dx,Dn;
	Dx=2.0;
	DValue=1.0;
	Dn=0.0;
	int i;
	div_t div1;
	int j=0;
	char *p;
	m_str="";
	if(data==0)
	{
		m_str="0";
	}
	else if(data==1)
	{
		m_str="1";
	}
	else
	{
		do
		{
			Dn+=1.0;
			DValue=pow(Dx,Dn);
		}while(DValue<=data);
		/////////////////////////////	
		i=(int)Dn;
		p=new char[i];
		////////////////////////////
		j=0;
		int Iv=((int)data);
		do
		{
			div1=div(Iv,2);
			if(div1.rem==1)
			{
				*(p+j)='1';
			}
			else
			{
				*(p+j)='0';
			}
			Iv=div1.quot;
			j++;
		}while(div1.quot!=0);
		//m_str=p;
		for(i=j-1;i>=0;i--)
		{
			if(*(p+i)=='1')
				m_str+="1";	
			else
				m_str+="0";	
		}
	}
	return m_str;
}

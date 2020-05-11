// CLRConsole.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PI 3.141596f
using namespace System;
using namespace System::Reflection;

ref class CPoint2D
{
public:
	float m_x,m_y;
	CPoint2D();
	CPoint2D(float x,float y);
	~CPoint2D();
	CPoint2D^ operator+(CPoint2D ^data);
	CPoint2D^ operator-(CPoint2D ^data);
	CPoint2D^ operator*(float data);
	CPoint2D^ operator/(float data);
	void SetData(float x,float y);
private:
protected:
};
CPoint2D::CPoint2D()
{
	m_x=0.0f;
	m_y=0.0f;
}
CPoint2D::CPoint2D(float x,float y)
{
	m_x=x;
	m_y=y;
}
void CPoint2D::SetData(float x,float y)
{
	m_x=x;
	m_y=y;
}
CPoint2D::~CPoint2D()
{
}
CPoint2D^ CPoint2D::operator +(CPoint2D ^data)
{
	CPoint2D ^temp;
	temp->m_x=m_x+data->m_x;  
	temp->m_y=m_y+data->m_y;  
	return temp;
}
CPoint2D^ CPoint2D::operator -(CPoint2D ^data)
{
	CPoint2D ^temp;
	temp->m_x=m_x-data->m_x;  
	temp->m_y=m_y-data->m_y;  
	return temp;
}
CPoint2D^ CPoint2D::operator *(float data)
{
	CPoint2D ^temp;
	temp->m_x=m_x*data;  
	temp->m_y=m_y*data;  
	return temp;
}
CPoint2D^ CPoint2D::operator /(float data)
{
	CPoint2D ^temp;
	temp->m_x=m_x/data;  
	temp->m_y=m_y/data;  
	return temp;
}
int main(array<System::String ^> ^args)
{
	CPoint2D ^Point2DX=gcnew CPoint2D();
	CPoint2D ^Point2DY=gcnew CPoint2D(20.0f,10.0f);
	CPoint2D ^Point2DZ=gcnew CPoint2D();
	Point2DX->SetData(10.0f,20.0f);
	Point2DZ=Point2DX+Point2DY;
	//array<Object^>^ myArray = gcnew array<Object^>(2);
	array <CPoint2D^>^ Point2DK=gcnew array<CPoint2D^>(2);
	Point2DK[0]->m_x=10.f;
	Point2DK[0]->m_y=10.f;
	Point2DK[1]->m_x=10.f;
	Point2DK[1]->m_y=10.f;
	Point2DZ=Point2DK[0]+Point2DK[1];
	Console::WriteLine(L"Hello World");
    return 0;
}

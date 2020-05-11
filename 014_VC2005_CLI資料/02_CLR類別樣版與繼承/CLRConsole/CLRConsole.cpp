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

template<class T> ref class CPoint2D
{
public:
	T m_x,m_y;
	CPoint2D();
	CPoint2D(T x,T y);
	~CPoint2D();
	CPoint2D<T>^ operator+(CPoint2D<T> ^data);
	CPoint2D<T>^ operator-(CPoint2D<T> ^data);
	CPoint2D<T>^ operator*(T data);
	CPoint2D<T>^ operator/(T data);
	void SetData(T x,T y);
private:
protected:
};
template<class T> CPoint2D<T>::CPoint2D()
{
}
template<class T> CPoint2D<T>::CPoint2D(T x,T y)
{
	m_x=x;
	m_y=y;
}
template<class T> void CPoint2D<T>::SetData(T x,T y)
{
	m_x=x;
	m_y=y;
}
template<class T> CPoint2D<T>::~CPoint2D()
{
}
template<class T> CPoint2D<T>^ CPoint2D<T>::operator +(CPoint2D<T> ^data)
{
	CPoint2D<T> ^temp;
	temp->m_x=m_x+data->m_x;  
	temp->m_y=m_y+data->m_y;  
	return temp;
}
template<class T> CPoint2D<T>^ CPoint2D<T>::operator -(CPoint2D<T> ^data)
{
	CPoint2D<T> ^temp;
	temp->m_x=m_x-data->m_x;  
	temp->m_y=m_y-data->m_y;  
	return temp;
}
template<class T> CPoint2D<T>^ CPoint2D<T>::operator *(T data)
{
	CPoint2D<T> ^temp;
	temp->m_x=m_x*data;  
	temp->m_y=m_y*data;  
	return temp;
}
template<class T> CPoint2D<T>^ CPoint2D<T>::operator /(T data)
{
	CPoint2D<T> ^temp;
	temp->m_x=m_x/data;  
	temp->m_y=m_y/data;  
	return temp;
}
ref class A{
public:
	float m_x,m_y;
	A();
	A(float x,float y);
	~A();
	A^ operator+(A ^data);
	A^ operator-(A ^data);
	A^ operator*(float data);
	A^ operator/(float data);
	void SetData(float x,float y);
};

A::A()
{
	m_x=0.0f;
	m_y=0.0f;
}
A::A(float x,float y)
{
	m_x=x;
	m_y=y;
}
void A::SetData(float x,float y)
{
	m_x=x;
	m_y=y;
}
A::~A()
{
}
A^ A::operator +(A ^data)
{
	A ^temp;
	temp->m_x=m_x+data->m_x;  
	temp->m_y=m_y+data->m_y;  
	return temp;
}
A^ A::operator -(A ^data)
{
	A ^temp;
	temp->m_x=m_x-data->m_x;  
	temp->m_y=m_y-data->m_y;  
	return temp;
}
A^ A::operator *(float data)
{
	A ^temp;
	temp->m_x=m_x*data;  
	temp->m_y=m_y*data;  
	return temp;
}
A^ A::operator /(float data)
{
	A ^temp;
	temp->m_x=m_x/data;  
	temp->m_y=m_y/data;  
	return temp;
}

template<class T> ref class CPoint3D: public CPoint2D<T>
{
	public:
	T m_z;
	CPoint3D();
	CPoint3D(T x,T y,T z);
	~CPoint3D();
	CPoint3D<T>^ operator+(CPoint3D<T>^ data);
	CPoint3D<T>^ operator-(CPoint3D<T>^ data);
	CPoint3D<T>^ operator*(T data);
	CPoint3D<T>^ operator/(T data);
	void SetData(T x,T y,T z);
};
template<class T> CPoint3D<T>::CPoint3D() : CPoint2D<T>()
{
}
template<class T> CPoint3D<T>::CPoint3D(T x,T y,T z) : CPoint2D<T>(x,y)
{
	m_z=z;
}
template<class T> void CPoint3D<T>::SetData(T x,T y,T z) 
{
	CPoint2D<T>::SetData(x,y);
	m_z=z;
}
template<class T> CPoint3D<T>::~CPoint3D()
{
	CPoint2D<T>::~CPoint2D(); 
}
template<class T> CPoint3D<T>^ CPoint3D<T>::operator+(CPoint3D<T>^ data)
{
	CPoint3D<T>^ temp;
	temp->m_x=m_x+data->m_x;  
	temp->m_y=m_y+data->m_y;
	temp->m_z=m_z+data->m_z;
	return temp;
}
template<class T> CPoint3D<T>^ CPoint3D<T>::operator-(CPoint3D<T>^ data)
{
	CPoint3D<T>^ temp;
	temp->m_x=m_x-data->m_x;  
	temp->m_y=m_y-data->m_y;
	temp->m_z=m_z-data->m_z;
	return temp;
}
template<class T> CPoint3D<T>^ CPoint3D<T>::operator*(T data)
{
	CPoint3D<T>^ temp;
	temp->m_x=m_x*data;  
	temp->m_y=m_y*data;
	temp->m_z=m_z*data;  
	return temp;
}
template<class T> CPoint3D<T>^ CPoint3D<T>::operator/(T data)
{
	CPoint3D^ temp;
	temp->m_x=m_x/data;  
	temp->m_y=m_y/data;
	temp->m_z=m_z/data;  
	return temp;
}

int main(array<System::String ^> ^args)
{
	CPoint2D<int> ^Point2DX=gcnew CPoint2D<int>();
	CPoint2D<int> ^Point2DY=gcnew CPoint2D<int>(10,10);
	CPoint2D<int> ^Point2DZ=gcnew CPoint2D<int>();

	CPoint3D<int> ^Point3DX=gcnew CPoint3D<int>();
	CPoint3D<int> ^Point3DY=gcnew CPoint3D<int>(10,10,10);
	CPoint3D<int> ^Point3DZ=gcnew CPoint3D<int>();
	Point2DX->SetData(10,20);
	Point2DZ=Point2DX+Point2DY;
	////array<Object^>^ myArray = gcnew array<Object^>(2);
	array <CPoint2D<int>^>^ Point2DK=gcnew array<CPoint2D<int>^>(2);
	Point2DK[0]->m_x=10;
	Point2DK[0]->m_y=10;
	Point2DK[1]->m_x=10;
	Point2DK[1]->m_y=10;	
	Point2DZ=Point2DK[0]+Point2DK[1];

	Point3DX->SetData(10,20,30);
	Point3DZ=Point3DX+Point3DY;
	array <CPoint3D<int>^>^ Point3DK=gcnew array<CPoint3D<int>^>(2);
	Point3DK[0]->m_x=10;
	Point3DK[0]->m_y=10;
	Point3DK[0]->m_z=10; 
	Point3DK[1]->m_x=10;
	Point3DK[1]->m_y=10;
	Point3DK[1]->m_z=10;
	Point3DZ=Point3DK[0]+Point3DK[1];
	Console::WriteLine(L"Hello World");
    return 0;
}

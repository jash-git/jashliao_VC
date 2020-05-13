#include <iostream.h>
#define PI 3.141596f
template<class T> class CPoint2D
{
public:
	T m_x,m_y;
	CPoint2D();
	CPoint2D(T x,T y);
	~CPoint2D();
	CPoint2D<T> operator+(CPoint2D<T> data);
	CPoint2D<T> operator-(CPoint2D<T> data);
	CPoint2D<T> operator*(T data);
	CPoint2D<T> operator/(T data);
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
template<class T> CPoint2D<T> CPoint2D<T>::operator +(CPoint2D<T> data)
{
	CPoint2D<T> temp;
	temp.m_x=m_x+data.m_x;  
	temp.m_y=m_y+data.m_y;  
	return temp;
}
template<class T> CPoint2D<T> CPoint2D<T>::operator -(CPoint2D<T> data)
{
	CPoint2D<T> temp;
	temp.m_x=m_x-data.m_x;  
	temp.m_y=m_y-data.m_y;  
	return temp;
}
template<class T> CPoint2D<T> CPoint2D<T>::operator *(T data)
{
	CPoint2D<T> temp;
	temp.m_x=m_x*data;  
	temp.m_y=m_y*data;  
	return temp;
}
template<class T> CPoint2D<T> CPoint2D<T>::operator /(T data)
{
	CPoint2D<T> temp;
	temp.m_x=m_x/data;  
	temp.m_y=m_y/data;  
	return temp;
}
template<class T> class CPoint3D : public CPoint2D<T>
{
public:
	T m_z;
	CPoint3D();
	CPoint3D(T x,T y,T z);
	~CPoint3D();
	CPoint3D<T> operator+(CPoint3D<T> data);
	CPoint3D<T> operator-(CPoint3D<T> data);
	CPoint3D<T> operator*(T data);
	CPoint3D<T> operator/(T data);
	void SetData(T x,T y,T z);
private:
protected:
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
	CPoint2D<T>::~CPoint2D<T>(); 
}
template<class T> CPoint3D<T> CPoint3D<T>::operator+(CPoint3D<T> data)
{
	CPoint3D<T> temp;
	temp.m_x=m_x+data.m_x;  
	temp.m_y=m_y+data.m_y;
	temp.m_z=m_z+data.m_z;
	return temp;
}
template<class T> CPoint3D<T> CPoint3D<T>::operator-(CPoint3D<T> data)
{
	CPoint3D<T> temp;
	temp.m_x=m_x-data.m_x;  
	temp.m_y=m_y-data.m_y;
	temp.m_z=m_z-data.m_z;
	return temp;
}
template<class T> CPoint3D<T> CPoint3D<T>::operator*(T data)
{
	CPoint3D<T> temp;
	temp.m_x=m_x*data;  
	temp.m_y=m_y*data;
	temp.m_z=m_z*data;  
	return temp;
}
template<class T> CPoint3D<T> CPoint3D<T>::operator/(T data)
{
	CPoint3D<T> temp;
	temp.m_x=m_x/data;  
	temp.m_y=m_y/data;
	temp.m_z=m_z/data;  
	return temp;
}
void main()
{
	CPoint2D <int> Point2D1,Point2D2,Point2D3;
	Point2D1.m_x=10;
	Point2D1.m_y=10;
	Point2D2.m_x=20;
	Point2D2.m_y=20;
	Point2D3.SetData(10,20);
	Point2D3=Point2D1+Point2D2;
	CPoint3D <int> Point3D1,Point3D2,Point3D3;
	Point3D1.m_x=10;
	Point3D1.m_y=10;
	Point3D1.m_z=10;
	Point3D2.m_x=20;
	Point3D2.m_y=20;
	Point3D2.m_z=20;
	Point3D3.SetData(10,20,30);
	Point3D3=Point3D1+Point3D2;
}
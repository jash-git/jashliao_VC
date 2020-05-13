#include <iostream>
#include<cmath>
#define size 10
using namespace std;
class Point
{
	public:
 		Point(float xx=0,float yy=0)
 		{
 		    X=xx;
 		    Y=yy;
        }
 		float GetX()
 		{
 		    return X;
        }
		float GetY()
		{
		    return Y;
        }
		friend float linefit(Point pp[], int n);
	private:
		float X,Y;
};
float linefit(Point pp[], int n)
{

	float avx,avy;
	float lxx,lyy,lxy;
	int i;

	avx=0;
	avy=0;
	lxx=0;
	lyy=0;
	lxy=0;
	for(i=0;i<n;i++)
	{
 		avx+=pp[i].X/n;
 		avy+=pp[i].Y/n;
	}

	for(i=0;i<n;i++)
	{
		lxx+=(pp[i].X-avx)*(pp[i].X-avx);
		lyy+=(pp[i].Y-avy)*(pp[i].Y-avy);
 		lxy+=(pp[i].X-avx)*(pp[i].Y-avy);
	}

	float a=lxy/lxx;
	float b=avy-a*avx;
	float r=lxy/sqrt(lxx*lyy);

	cout<<"該直線的線性回歸可表示為："<< endl << "y(x)=" << a << "x+" << b<< endl;
	cout<< "其中相關係數r為:" << endl<< "r=" << r << endl;

	return(1);
}
int main()
{
 	int a[size][2];
 	int g=0;
	cout<<"請在此區域輸入坐標：" << endl <<"--------------------------------------------------------------" << endl;

	for(g=0;g<size;g++)
		for(int h=0;h<2;h++)
 		{
			cin>>a[g][h];
		}
 	cout<<"--------------------------------------------------------------"<<endl<<"你輸入的座標如下："<< endl;

	for(g=0;g<size;g++)
	{
		cout<< "(" << a[g][0] << "," <<a[g][1] << ")" << endl;
	}

	Point p[size];
	for(g=0;g<size;g++)
		p[g]=Point(a[g][0],a[g][1]);

	linefit( p,size);

    cout<<"輸入任何字元程式結束";
	char b;
	cin>>b;
    return 0;
}

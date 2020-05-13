#include <iostream>
using namespace std;
namespace space1
{
	class rect
	{
		private:
			int width;
			int height;
		public:
			rect(int w,int h)
			{
				width = w;
				height = h;
			}
			int area()
			{
				return width * height;
			}
	};
}
void main(void)
{
	using namespace space1;
	rect Rectarea(20,20);
	//space1::rect Rectarea(20,20);
	cout<<"Rectarea = "<<Rectarea.area()<<endl;
	system("PAUSE");
}

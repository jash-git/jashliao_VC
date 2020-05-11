#include <iostream>
using namespace std; 
int main()
 {     
	int num = 1;     
	cout << "2的0次：" << num << endl;     
	num = num << 1;     
	cout << "2的1次：" << num << endl;     
	num = num << 1;     
	cout << "2的2次：" << num << endl;     
	num = num << 1;     
	cout << "2的3次：" << num << endl;
	num = num >> 1;     
	cout << "2的2次：" << num << endl; 
	num = num >> 1; 
	cout << "2的1次：" << num << endl;     
	num = num >> 1;
	cout << "2的0次：" << num << endl; 
	return 0;
}

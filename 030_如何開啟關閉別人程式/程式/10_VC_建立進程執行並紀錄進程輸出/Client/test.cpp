#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	for (int i = 0; i < 1000; i++)
	{
		printf("i = %d\n", i);
		cout << "標準輸出" << i << endl;
		cerr << "標準除錯輸出" << i << endl;
	}
	return 0;
}


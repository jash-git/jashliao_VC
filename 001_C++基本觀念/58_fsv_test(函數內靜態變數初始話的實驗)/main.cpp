#include <iostream>

using namespace std;
int fsv_test();//function static variable
int main()
{
    cout << "Hello world!" << endl;
    cout << "fsv_test_called 01=" <<fsv_test()<< endl;
    cout << "fsv_test_called 02=" <<fsv_test()<< endl;
    return 0;
}
int fsv_test()
{
   static int  intfsv=0;
   //intfsv=0;
   intfsv++;
   return intfsv;
}

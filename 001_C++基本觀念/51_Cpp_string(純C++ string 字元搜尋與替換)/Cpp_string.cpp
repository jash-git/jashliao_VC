// Cpp_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// string::find
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string str ("http://127.0.0.1:9999/888.mp4");
  string str2 (".mp4");
  size_t found;
  string str3;
  found=str.find(str2);
  cout << found <<endl;
  str3=str;
  cout << str3 <<endl;
  str3.replace(found,4,"");
  cout << str3 <<endl;
system("pause");
  return 0;
}

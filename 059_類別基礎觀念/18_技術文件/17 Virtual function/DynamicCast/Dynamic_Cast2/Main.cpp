// 使用小麥草公司的軟體
// 1. empolyee.obj
// 2. manager.obj
// 3. program.obj

#include "..\DynamicCastDemo\program.h"
#include <iostream>
using namespace std;

// 因為我們沒有 program 類別的source code
// 但是我們卻可以新增加一個 method bonus()
void programmer::bonus(){
	cout << "Programer 新增的method" << endl;
}
void main(){
	programmer obj;

	obj.bonus();

	empolyee *p=&obj;
	p->salary();
}
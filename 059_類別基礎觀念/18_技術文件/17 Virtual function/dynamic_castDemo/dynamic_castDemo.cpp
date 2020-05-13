// 使用 dynamic_cast的範例: 將 base class 的指標轉成衍生類別的指標
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Base
    {
        public:
            virtual ~Base(){};
    };
class Derived: public Base
    {
        public:
            char const *toString()
            {
                return ("Derived object");
            }
	};
    int main()
    {
        Base   *bp,b;
        Derived  *dp,   d;

        bp = &d;
		//bp=&b;  // 無法轉換的ex

        if ((dp = dynamic_cast<Derived *>(bp)))
            cout << dp->toString() << endl;
        else
            cout << "dynamic cast conversion failed\n";

        return (0);
    }


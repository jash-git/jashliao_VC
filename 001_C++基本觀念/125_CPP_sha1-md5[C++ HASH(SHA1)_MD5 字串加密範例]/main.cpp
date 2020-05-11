#include <iostream>
#include "md5.h"
#include "sha1.h"

using namespace std;
/*
資料來源: https://blog.csdn.net/u011334621/article/details/79665614

線上驗證:
https://www.ez2o.com/App/Coder/MD5/
https://www.ez2o.com/App/Coder/SHA/
*/
int main()
{
    std::string str = "abc";
    printf("%s\n",str.c_str());

    SHA1 sha1;

    char buffer[41];

    sha1.SHA_GO(str.c_str(),buffer);

    printf("sha1:%s\n",buffer);

    //sha1调用
    //===================================================
    //MD5调用


    MD5 md5(str);

    std::string result = md5.md5();


    printf("md5:%s\n",result.c_str());
    return 0;
}

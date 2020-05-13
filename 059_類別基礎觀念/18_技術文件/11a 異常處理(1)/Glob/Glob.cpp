// 全域變數內容則不變範例

#pragma hdrstop
#include <condefs.h>


//---------------------------------------------------------------------------
#pragma argsused
#include <iostream.h>
class EXCEPT{
 public:
     int data;
     EXCEPT()
     {
         data=134;
     }
     set(int arg)
     {         data=arg;   }
};

EXCEPT myerrobj;    // 目前myerrobj=134;
void fun2();
void fun3();
void fun1()
{
   fun2();

}
void fun2()
{
    fun3();
}
void fun3()
{
    throw myerrobj;
}
int main(int argc, char* argv[])
{

        try{
            fun1();
        }
        catch(EXCEPT &errObj)
        {   errObj.set(1234);    //目前修改errObj=1234;
            int x;               // 是否更改 myerrobj ?
            x++;                 // No! 只改了 errObj.
                                 // 因為 throw 複製了myerrobj -> errObj
        }

        return 0;
}

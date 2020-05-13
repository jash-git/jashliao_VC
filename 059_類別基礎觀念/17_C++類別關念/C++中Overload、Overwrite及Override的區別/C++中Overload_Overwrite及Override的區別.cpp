/*
C++中Overload、Overwrite及Override的區別
Overload(重載)：在C++程式中，可以將語義、功能相似的幾個函數用同一個名字表示，但參數或返回值不同（包括類型、順序不同），即函數重載。
（1）相同的範圍（在同一個類中）；
（2）函數名字相同；
（3）參數不同；
（4）virtual 關鍵字可有可無。
PS.類似功能同時存在，依照傳入參數不同來區分「jash.liao 註解 2015/02/07 」

Override(覆蓋)：是指派生類函數覆蓋基類函數，特徵是：
（1）不同的範圍（分別位於派生類與基類）；
（2）函數名字相同；
（3）參數相同；
（4）基類函數必須有virtual 關鍵字。
ps.當子物件強制轉換成父類型時，會呼叫子類別功能，因為已經被覆蓋

Overwrite(重寫)：是指派生類的函數遮罩了與其同名的基類函數，規則如下：
（1）如果派生類的函數與基類的函數同名，但是參數不同。此時，不論有無virtual關鍵字，基類的函數將被隱藏（注意別與重載混淆）。
（2）如果派生類的函數與基類的函數同名，並且參數也相同，但是基類函數沒有virtual關鍵字。此時，基類的函數被隱藏（注意別與覆蓋混淆）。
ps.當子物件強制轉換成父類型時，會呼叫父類別功能，因為只是被遮罩
*/
#include <cstdio>  
#include <iostream>

using namespace std;  

class Parent  
{  
public:  
    void F()  
    {  
        printf("Parent.F()\n");  
    }  
    virtual void G()  
    {  
        printf("Parent.G()\n");  
    }
	//重載(overload)Add函數
    int Add(int x, int y)  
    {  
        return x + y;  
    }  
    float Add(float x, float y)  
    {  
        return x + y;  
    }  
};  
  
class ChildOne: public Parent  
{  
 public:   
    void F()  
    {  
        printf("ChildOne.F()\n");   
    }  
    
    void G()  
    {  
        printf("ChildOne.G()\n");  
    }  
};  
  
  
int main()  
{  
    ChildOne childOne;// = new ChildOne();
    childOne.F();//指明呼叫子類別
    childOne.G();//指明呼叫子類別
    childOne.Parent::F();//指明呼叫父類別
    childOne.Parent::G();//指明呼叫父類別
    Parent* p = (Parent*)&childOne;  
    p->F();//子類轉換成父類，但F()是Overwrite(重寫)，所以會呼叫到父類別功能  
    p->G();//子類轉換成父類，但G()是Override(覆蓋)，所以會呼叫到子類別功能  
    Parent* p2 = new Parent(); 
    p2->F();//父類別功能
    p2->G();//父類別功能
    printf("%d\n",p2->Add(1, 2)); //重載(overload)Add函數 
    printf("%f\n",p2->Add(3.4f, 4.5f));//重載(overload)Add函數  
    delete p2;  
      
    return 0;  
}  
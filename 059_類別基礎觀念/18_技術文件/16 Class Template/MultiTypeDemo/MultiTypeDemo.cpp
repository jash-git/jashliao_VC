// MultiTypeDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <class Type1, class Type2> 
class Matrix {
private:
      int Row,Col;
      Type1 **Buffer;                    // 第一種資料實體
      Type2 **Buffer2;				     // 第二種資料實體
public:
       Matrix(int Row,int Col);
};
template <class Type1,class Type2> 
Matrix<Type1,Type2>::Matrix(int Row,int Col)      // <<<---- 注意: 要求編譯器產生(Type1,Type2)版本建構子
{
    int y;
	// 配置第一資料實體    
		Buffer=new Type1*[Row];
        for(y=0;y<Row;y++)
                Buffer[y]=new Type1[Col];
	// 配置第二資料實體 
		Buffer2=new Type2*[Row];
        for(y=0;y<Row;y++)
                Buffer2[y]=new Type2[Col];
}

int main(int argc, char* argv[])
{
	Matrix<int,char> MyMatrix(2,3);
	return 0;
}


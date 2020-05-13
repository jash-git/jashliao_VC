// TemplateMatrixClass.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
template <typename Type> 
class Matrix {
	private:
		int Row,Col;
		Type **Buffer;
	public:
		Matrix(int Row,int Col);
};
template <typename Type> 
Matrix<Type>::Matrix(int Row,int Col)
{
	Buffer=new Type*[Row];
	for(int y=0;y<Row;y++)
		Buffer[y]=new Type[Col];
}

int main(int argc, char* argv[])
{
	Matrix<int> obj(2,3);
	return 0;
}


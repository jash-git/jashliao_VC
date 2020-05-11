// Matrix.h: interface for the CMatrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIX_H__252F1FEF_F0A7_4E2A_9DFC_DE56FB93288C__INCLUDED_)
#define AFX_MATRIX_H__252F1FEF_F0A7_4E2A_9DFC_DE56FB93288C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMatrix  
{
public:
	 ////
	////
	////构造与解析
	CMatrix();//缺省值的构造函数
	CMatrix(int nRows,int nCols);//指定行列
	CMatrix(int nRows,int nCols,double value[]);//指定数据构造函数
	CMatrix(int nSize);//方阵构造函数
	CMatrix(int nSize,double value[]);//指定数据结构的方阵构造函数
	CMatrix(const CMatrix &other);//拷贝构造函数
	virtual ~CMatrix();//析构函数
	bool Init(int nRows,int nCols);//初始化矩阵
	bool MakeUnitMatrix(int nSize);//将方阵初始化为单位阵
	//////
	/////
	/////输入与显示
	//将字符串转换为矩阵数据
	//将矩阵转换为字符串
	//将矩阵指定行转换为字符串
	//将矩阵指定列转换为字符串///待补
	/////
	////
	////元素与值操作
	//设置指定元素的值
	bool SetElement(int nRow, int nCol, double value);
	double GetElement(int nRow,int nCol)const;//获取指定元素的值
	void SetData(double value[]);//设置矩阵的值
	int GetNumCols() const;//获取矩阵列数
	int GetNumRows() const;//获取矩阵行数
	double *GetData() const;//获取矩阵的值
	int GetRowVector(int nRow,double *pVector)const;//获取指定的行向量放在数组pVector中，返回元素个数
	int GetColVector(int nCol,double *pVector)const;//获取指定的列向量放在数组pVector中，返回元素个数
	
	///
	///
	///数学运算符
	CMatrix& operator=(const CMatrix &other);
	bool operator==(const CMatrix &other)const;
	bool operator!=(const CMatrix &other)const;
	CMatrix operator+(const CMatrix &other)const;
	CMatrix operator-(const CMatrix &other)const;
	CMatrix operator*(double value)const;
	CMatrix operator*(const CMatrix &other)const;
	CMatrix Transpose()const;//转置
	CMatrix Invert();//矩阵求逆
	CMatrix Eigenv();//矩阵求特征值和特征根，返回矩阵，第一行为特征值，其他行为对应特征向量
	CMatrix Eigenv2();//矩阵求特征值和特征根第二种方法，返回矩阵，第一行为特征值，其他行为对应特征向量
protected:
	int m_NumRows;//列数
	int m_NumCols;//行数
	double *m_pData;//数据缓冲区
private:
	bool InvertGaussJordan();
	bool JacobiEigenv(double EigenValue[], CMatrix &EigenVector,int nMaxIt=60,double eps=0.000001);
	bool JacobiEigenv2(double EigenValue[], CMatrix &EigenVector,int nMaxIt=60,double eps=0.000001);
	void Swape(void);//对矩阵按第一行由大到小排序

};

#endif // !defined(AFX_MATRIX_H__252F1FEF_F0A7_4E2A_9DFC_DE56FB93288C__INCLUDED_)

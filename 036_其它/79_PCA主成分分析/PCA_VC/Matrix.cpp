// Matrix.cpp: implementation of the CMatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ProGram2.h"
#include "Matrix.h"
#include "math.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMatrix::CMatrix()
{
	m_NumCols=1;
	m_NumRows=1;
	m_pData=NULL;
	Init(m_NumRows,m_NumCols);
}

CMatrix::CMatrix(int nRows, int nCols)
{////////////指定行列构造函数
	m_NumCols=nCols;
	m_NumRows=nRows;
	m_pData=NULL;
	Init(m_NumRows,m_NumCols);
}
CMatrix::CMatrix(int nRows,int nCols, double value[])
{//、、、、指定值构造函数
	m_NumCols=nCols;
	m_NumRows=nRows;
	m_pData=NULL;
	Init(m_NumRows,m_NumCols);
	SetData(value);
	
}
CMatrix::CMatrix(int nSize)
{//方阵构造函数
	m_NumCols=nSize;
	m_NumRows=nSize;
	m_pData=NULL;
	Init(nSize,nSize);
}
CMatrix::CMatrix(int nSize,double value[])
{//指定值的方阵构造函数
	m_NumCols=nSize;
	m_NumRows=nSize;
	m_pData=NULL;
	Init(nSize,nSize);
	SetData(value);
}
CMatrix::CMatrix(const CMatrix &other)
{
	m_NumCols=other.m_NumCols;
	m_NumRows=other.m_NumRows;
	m_pData=NULL;
	Init(m_NumRows,m_NumCols);
	memcpy(m_pData,other.m_pData,sizeof(double)*m_NumRows*m_NumCols);
}
////
////
////初始化//生成0矩阵
bool CMatrix::Init(int nRows,int nCols)
{
	if(m_pData)
	{
		delete[] m_pData;
		m_pData=NULL;
	}
	m_NumRows=nRows;
	m_NumCols=nCols;
	int nSize=nRows*nCols;
	if(nSize<0)
		return false;

	//分配内存
	m_pData=new double[nSize];
	if(m_pData==NULL)
		return false;
	if(IsBadReadPtr(m_pData,sizeof(double)*nSize))////////////
		return false;
	memset(m_pData,0,sizeof(double)*nSize);
	return true;
}
bool CMatrix::MakeUnitMatrix(int nSize)
{
	if(!Init(nSize,nSize))//初始化为0矩阵
		return false;
	for(int i=0;i<nSize;i++)
		SetElement(i,i,1);
	return true;
}
///
///
///析构函数
CMatrix::~CMatrix()
{
	if(m_pData)
	{
		delete[] m_pData;
		m_pData=NULL;
	}
}
//////////////////////////////////////////////////////////
///
///
///元素与值操作////////////
///
///
///设置矩阵各个元素的值
void CMatrix::SetData(double value[])
{
	memset(m_pData,0,sizeof(double)*m_NumRows*m_NumCols);//设置空值
	memcpy(m_pData,value,sizeof(double)*m_NumRows*m_NumCols);
}
///
///
///设置指定元素的值
bool CMatrix::SetElement(int nRow,int nCol,double value)
{
	if(nCol<0 ||nRow<0 ||nCol>m_NumCols || nRow>m_NumRows)
		return false;
	if(m_pData==NULL)
		return false;
	m_pData[nCol+nRow*m_NumCols]=value;
	return true;
}
///
///
///获取指定元素的值
double CMatrix::GetElement(int nRow,int nCol)const
{
	ASSERT(nCol>=0 && nRow>=0 && nCol<m_NumCols && nRow<m_NumRows);
	ASSERT(m_pData);
	return m_pData[nCol+nRow*m_NumCols];
}
///
///
///获取行列数
int CMatrix::GetNumCols()const
{
	return m_NumCols;
}
int CMatrix::GetNumRows()const
{
	return m_NumRows;
}
///
///
///获取矩阵的数据
double *CMatrix::GetData()const
{
	return m_pData;
}    
///
///
///获取指定行的向量
int CMatrix::GetRowVector(int nRow,double *pVector)const
{
	if(m_pData==NULL)
		delete pVector;
	pVector = new double[m_NumCols];
	ASSERT(pVector!=NULL);
	for(int j=0;j<m_NumCols;j++)
		pVector[j]=GetElement(nRow,j);
	return m_NumCols;
}                                          
///
///
///获取指定列的向量
int CMatrix::GetColVector(int nCol,double *pVector)const
{
	if(m_pData==NULL)
		delete pVector;
	pVector = new double[m_NumRows];
	ASSERT(pVector!=NULL);
	for(int j=0;j<m_NumRows;j++)
		pVector[j]=GetElement(j,nCol);
	return m_NumCols;	
}
////////////////////////////////////////////
///
///
///数学运算符重载
///
///
///'='号，赋值
CMatrix &CMatrix::operator=(const CMatrix &other)
{
	if(&other!=this)
	{
		m_NumRows=other.GetNumRows();
		m_NumCols=other.GetNumCols();
		Init(m_NumRows,m_NumCols);
		memcpy(m_pData,other.GetData(),sizeof(double)*m_NumRows*m_NumCols);////////改动
	}
	return *this;

}
///
///
///'=='号，判断相等
bool CMatrix::operator==(const CMatrix &other)const
{
	if(m_NumRows!=other.GetNumRows() || m_NumCols!=other.GetNumCols())
		return false;
	for(int i=0;i<m_NumRows;i++)
	{
		for(int j=0;j<m_NumCols;j++)
		{
			if(GetElement(i,j)!=other.GetElement(i,j))
				return false;
		}
	}
	return true;
}
///
///
///'!='号，判断不等
bool CMatrix::operator!=(const CMatrix &other)const
{
	return !(*this==other);
}
///
///
///'+'号，矩阵相加
CMatrix CMatrix::operator+(const CMatrix &other)const
{
	ASSERT(m_NumRows==other.GetNumRows() || m_NumCols==other.GetNumCols());
	CMatrix result(*this);
	for(int i=0;i<m_NumRows;i++)
	{
		for(int j=0;j<m_NumCols;j++)
		{
			result.SetElement(i,j,result.GetElement(i,j)+other.GetElement(i,j));
		}
	}
	return result;
}
///
///
///'-'号，矩阵相减
CMatrix CMatrix::operator-(const CMatrix &other)const
{
	ASSERT(m_NumRows==other.GetNumRows() || m_NumCols==other.GetNumCols());
	CMatrix result(*this);

	for(int i=0;i<m_NumRows;i++)
	{
		for(int j=0;j<m_NumCols;j++)
		{
			result.SetElement(i,j,result.GetElement(i,j)-other.GetElement(i,j));
		}
	}
	return result;
}
///
///
///'*'号，矩阵乘以double数值
CMatrix CMatrix::operator*(double value)const
{
	ASSERT(m_NumRows==this->GetNumRows() || m_NumCols==this->GetNumCols());
	CMatrix result(*this);

	for(int i=0;i<m_NumRows;i++)
	{
		for(int j=0;j<m_NumCols;j++)
		{
			result.SetElement(i,j,result.GetElement(i,j)*value);
		}
	}
	return result;
}
///
///
///'*'号，矩阵相乘
CMatrix CMatrix::operator*(const CMatrix &other)const
{
	ASSERT(m_NumCols==other.GetNumRows());
	CMatrix result(m_NumRows,other.GetNumCols());
	double value;
	for(int i=0;i<result.GetNumRows();i++)
	{
		for(int j=0;j<result.GetNumCols();j++)
		{
			value=0.0;
			for(int k=0;k<m_NumCols;k++)
			{
				value+=GetElement(i,k)*other.GetElement(k,j);
			}
			result.SetElement(i,j,value);
		}
	}
	return result;
}

///
///
///公共函数，求矩阵的逆，返回逆矩阵
CMatrix CMatrix::Invert()
{
	CMatrix result(*this);
	if(result.InvertGaussJordan())
		return result;
}
///
///
///矩阵转置
CMatrix CMatrix::Transpose()const
{
	CMatrix trans(m_NumCols,m_NumRows);
	for(int i=0;i<m_NumRows;i++)
	{
		for(int j=0;j<m_NumCols;j++)
			trans.SetElement(j,i,GetElement(i,j));
	}
	return trans;
}
///
///
///私有函数，高斯列主元求矩阵的逆
bool CMatrix::InvertGaussJordan()
{
	int *pnRow,*pnCol,i,j,k,l,u,v;
	double d=0.0, p=0.0;

	//分配内存
	pnRow=new int[m_NumCols];
	pnCol=new int[m_NumCols];
	if(pnRow==NULL || pnCol==NULL)
		return false;

	//消元
	for(k=0;k<m_NumCols;k++)
	{
		d=0.0;
		for(i=k;i<m_NumCols;i++)
		{
			for(j=k;j<m_NumCols;j++)
			{
				l=i*m_NumCols+j;
				p=fabs(m_pData[l]);
				if(p>d)
				{
					d=p;
					pnRow[k]=i;
					pnCol[k]=j;
				}
			}
		}

		//失败
		if(d==0.0)
		{
			delete[] pnRow;
			delete[] pnCol;
			return false;
		}
		if(pnRow[k]!=k)
		{
			for(j=0;j<m_NumCols;j++)
			{
				u=k*m_NumCols+j;
				v=pnRow[k]*m_NumCols+j;
				p=m_pData[u];
				m_pData[u]=m_pData[v];
				m_pData[v]=p;
			}
		}
		if(pnCol[k]!=k)
		{
			for(i=0;i<m_NumCols;i++)
			{
				u=i*m_NumCols+k;
				v=i*m_NumCols+pnCol[k];
				p=m_pData[u];
				m_pData[u]=m_pData[v];
				m_pData[v]=p;
			}			
		}
		l=k*m_NumCols+k;
		m_pData[l]=1.0/m_pData[l];
		for(j=0;j<m_NumCols;j++)
		{
			if(j!=k)
			{
				u=k*m_NumCols+j;
				m_pData[u]=m_pData[u]*m_pData[l];
			}
		}
		for(i=0;i<m_NumCols;i++)
		{
			if(i!=k)
			{
				for(j=0;j<m_NumCols;j++)
				{
					if(j!=k)
					{
						u=i*m_NumCols+j;
						m_pData[u]=m_pData[u]-m_pData[i*m_NumCols+k]*m_pData[k*m_NumCols+j];
					}
				}
			}
		}
		for(i=0;i<m_NumCols;i++)
		{
			if(i!=k)
			{
				u=i*m_NumCols+k;
				m_pData[u]=-m_pData[u]*m_pData[l];
			}
		}
	}
	//调整恢复行列次序
	for(k=m_NumCols-1;k>=0;k--)
	{
		if(pnCol[k]!=k)
		{
			for(j=0;j<m_NumCols;j++)
			{
				u=k*m_NumCols+j;
				v=pnCol[k]*m_NumCols+j;
				p=m_pData[u];
				m_pData[u]=m_pData[v];
				m_pData[v]=p;
			}
		}
		if(pnRow[k]!=k)
		{
			for(i=0;i<m_NumCols;i++)
			{
				u=i*m_NumCols+k;
				v=i*m_NumCols+pnRow[k];
				p=m_pData[u];
				m_pData[u]=m_pData[v];
				m_pData[v]=p;
			}			
		}
	}
	//清理内存
	delete[] pnCol;
	delete[] pnRow;
	//成功返回
	return true;
}
///
///
///私有函数，求对称矩阵的特征值与特征根
bool CMatrix::JacobiEigenv(double EigenValue[],CMatrix &EigenVector,int nMaxIt,double eps)
{

	int i,j,p,q,u,w,t,s,l;
	double fm, cn, sn,omega,x,y,d;
	if(!EigenVector.Init(m_NumCols,m_NumCols))
		return false;
	l=1;
	for(i=0;i<m_NumCols;i++)
	{
		EigenVector.m_pData[i*m_NumCols+i]=1.0;
		for(j=0;j<m_NumCols;j++)
			if(i!=j)
				EigenVector.m_pData[i*m_NumCols+j]=0.0;
	}
	while(1)
	{
		fm=0.0;
		for(i=1;i<m_NumCols;i++)
		{
			for(j=0;j<i;j++)
			{
				d=fabs(m_pData[i*m_NumCols+j]);
				if((i!=j) && (d>fm))
				{
					fm=d;
					p=i;
					q=j;
				}
			}
		}
		if(fm<eps)
		{
			for(i=0;i<m_NumCols;++i)
				EigenValue[i]=GetElement(i,i);
			return true;
		}
		if(l>nMaxIt)
			return false;
		l=l+1;
		u=p*m_NumCols+q;
		w=p*m_NumCols+p;
		t=q*m_NumCols+p;
		s=q*m_NumCols+q;
		x=-m_pData[u];
		y=(m_pData[s]-m_pData[w])/2.0;
		omega=x/sqrt(x*x+y*y);

		if(y<0.0)
			omega=-omega;
		sn=1.0+sqrt(1.0-omega*omega);
		sn=omega/sqrt(2.0*sn);
		cn=sqrt(1.0-sn*sn);
		fm=m_pData[w];
		m_pData[w]=fm*cn*cn+m_pData[s]*sn*sn+m_pData[u]*omega;
		m_pData[s]=fm*sn*sn+m_pData[s]*cn*cn-m_pData[u]*omega;
		m_pData[u]=0.0;
		m_pData[t]=0.0;
		for(j=0;j<m_NumCols;j++)
		{
			if((j!=p) && (j!=q))
			{
				u=p*m_NumCols+j;
				w=q*m_NumCols+j;
				fm=m_pData[u];
				m_pData[u]=fm*cn+m_pData[w]*sn;
				m_pData[w]=-fm*sn+m_pData[w]*cn;
			}
		}
		for(i=0;i<m_NumCols;i++)
		{
			if((i!=p) && (i!=q))
			{
				u=i*m_NumCols+p;
				w=i*m_NumCols+q;
				fm=m_pData[u];
				m_pData[u]=fm*cn+m_pData[w]*sn;
				m_pData[w]=-fm*sn+m_pData[w]*cn;
			}
		}
		for(i=0;i<m_NumCols;i++)
		{
			u=i*m_NumCols+p;
			w=i*m_NumCols+q;
			fm=EigenVector.m_pData[u];
			EigenVector.m_pData[u]=fm*cn+EigenVector.m_pData[w]*sn;
			EigenVector.m_pData[w]=-fm*sn+EigenVector.m_pData[w]*cn;
		}
	}
	for(i=0;i<m_NumCols;++i)
		EigenValue[i]=GetElement(i,i);
	return true;
}
///
///
///私有函数，求矩阵特征值和特征向量的第二种方法
bool CMatrix::JacobiEigenv2(double EigenValue[],CMatrix &EigenVector,int nMaxIt,double eps)
{
	int i,j,p,q,u,w,t,s;
	double ff,fm,cn,sn,omega,x,y,d;
	if(!EigenVector.Init(m_NumCols,m_NumCols))
		return false;
	for(i=0;i<m_NumCols;i++)
	{
		EigenVector.m_pData[i*m_NumCols+i]=1.0;
		for(j=0;j<m_NumCols;j++)
			if(i!=j)
				EigenVector.m_pData[i*m_NumCols+j]=0.0;
	}
	ff=0.0;
	for(i=1;i<m_NumCols;i++)
	{
		for(j=0;j<i-1;j++)
		{
			d=m_pData[i*m_NumCols+j];
			ff=ff+d*d;
		}
	}
	ff=sqrt(2.0*ff);
Loop_0:
	ff=ff/(1.0*m_NumCols);
Loop_1:
	for(i=1;i<m_NumCols;i++)
	{
		for(j=0;j<i;j++)
		{
			d=fabs(m_pData[i*m_NumCols+j]);
			if(d>ff)
			{
				p=i;
				q=j;
				goto Loop_2;
			}
		}
	}
	if(ff<eps)
	{
		for(i=0;i<m_NumCols;i++)
			EigenValue[i]=GetElement(i,i);
		return true;
	}
	goto Loop_0;
Loop_2:
	u=p*m_NumCols+q;
	w=p*m_NumCols+p;
	t=q*m_NumCols+p;
	s=q*m_NumCols+q;
	x=-m_pData[u];
	y=(m_pData[s]-m_pData[w])/2.0;
	omega=x/sqrt(x*x+y*y);
	if(y<0.0)
		omega=-omega;
	sn=1.0+sqrt(1.0-omega*omega);
	sn=omega/sqrt(2.0*sn);
	cn=sqrt(1.0-sn*sn);
	fm=m_pData[w];
	m_pData[w]=fm*cn*cn+m_pData[s]*sn*sn+m_pData[u]*omega;
	m_pData[s]=fm*sn*sn+m_pData[s]*cn*cn-m_pData[u]*omega;
	m_pData[u]=0.0;
	m_pData[t]=0.0;
	for(j=0;j<m_NumCols;j++)
	{
		if((j!=p)&&(j!=q))
		{
			u=p*m_NumCols+j;
			w=q*m_NumCols+j;
			fm=m_pData[u];
			m_pData[u]=fm*cn+m_pData[w]*sn;
			m_pData[w]=-fm*sn+m_pData[w]*cn;
		}
	}
	for(i=0;i<m_NumCols;i++)
	{
		if((i!=p)&&(i!=q))
		{
			u=i*m_NumCols+p;
			w=i*m_NumCols+q;
			fm=m_pData[u];
			m_pData[u]=fm*cn+m_pData[w]*sn;
			m_pData[w]=-fm*sn+m_pData[w]*cn;
		}
	}
	for(i=0;i<m_NumCols;i++)
	{
		u=i*m_NumCols+p;
		w=i*m_NumCols+q;
		fm=EigenVector.m_pData[u];
		EigenVector.m_pData[u]=fm*cn+EigenVector.m_pData[w]*sn;
		EigenVector.m_pData[w]=-fm*sn+EigenVector.m_pData[w]*cn;
	}
	goto Loop_1;
}
CMatrix CMatrix::Eigenv()
{
	ASSERT(m_NumCols==m_NumRows);
	CMatrix result(*this);
	double *EigenValue=new double[m_NumCols];
	CMatrix EigenVector;
	if(result.JacobiEigenv(EigenValue,EigenVector))
	{
		result.Init(m_NumRows+1,m_NumCols);
		for(int i=0;i<m_NumCols;i++)
		{
			result.SetElement(0,i,EigenValue[i]);
			for(int j=1;j<=m_NumRows;j++)
			{
				result.SetElement(j,i,EigenVector.GetElement(j-1,i));
			}
		}
		 result.Swape();
		 return result;
	}

}
CMatrix CMatrix::Eigenv2()
{
	ASSERT(m_NumCols==m_NumRows);
	CMatrix result(*this);
	double *EigenValue=new double[m_NumCols];
	CMatrix EigenVector;
	if(result.JacobiEigenv2(EigenValue,EigenVector))
	{
		result.Init(m_NumRows+1,m_NumCols);
		for(int i=0;i<m_NumCols;i++)
		{
			result.SetElement(0,i,EigenValue[i]);
			for(int j=1;j<=m_NumRows;j++)
			{
				result.SetElement(j,i,EigenVector.GetElement(j-1,i));
			}
		}
		 result.Swape();
		 return result;
	}

}
void CMatrix::Swape(void)
{
	ASSERT(*this!=NULL);
	double ch;
	for(int i=0;i<m_NumCols-1;i++)
	{
		for(int j=i+1;j<m_NumCols;j++)
		{
			if(GetElement(0,i)<GetElement(0,j))
			{
				for(int k=0;k<m_NumRows;k++)
				{
					ch=GetElement(k,i);
					SetElement(k,i,GetElement(k,j));
					SetElement(k,j,ch);
				}
			}
		}
	}
}


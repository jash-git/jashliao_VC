#include <iostream>
#include <cmath>
using namespace std;
/*
Gauss-Jordan 消去法解線性代數方程
a[]:輸入時為A矩陣，結束時為A的反矩陣
b[]:輸入時為B矩陣，結束時為解答X
n:A矩陣的階數
*/
void gaussj(double a[], int n, double b[])
{
	int i,j,k,l,ll,irow,icol;
	double big,pivinv,dum;
    int ipiv[50], indxr[50], indxc[50];
    for (j=0;j<=n-1;j++)
	{
        ipiv[j]=0;
    }
    for (i=0;i<=n-1;i++)
	{
        big=0.0;
        for (j=0;j<=n-1;j++)
		{
            if(ipiv[j]!=1)
			{
                for(k=0;k<=n-1;k++)
				{
					if(ipiv[k]==0)
					{
						if(fabs(a[j*n+k])>=big)
						{
							big=fabs(a[j*n+k]);
							irow=j;
							icol=k;
						}
						else if(ipiv[k]>1)
						{
							cout<<"singular matrix";
						}
					}
                }
            }
        }
        ipiv[icol]=ipiv[icol]+1;
        if(irow!=icol)
		{
            for(l=0;l<=n-1;l++)
			{
                dum=(a[irow*n+l]);
                a[irow*n+l]=a[icol*n+l];
                a[icol*n+l]=dum;
            }
            dum=b[irow];
            b[irow]=b[icol];
            b[icol]=dum;
		}
        indxr[i]=irow;
        indxc[i]=icol;
        if(a[icol*n+icol]==0.0)
		{
			cout<< "singular matrix.";
		}
        pivinv=1.0/(a[icol*n+icol]);
        a[icol*n+icol]=1.0;
        for(l=0;l<=n-1;l++)
		{
            a[icol*n+l]=a[icol*n+l]*pivinv;
        }
        b[icol]=b[icol]*pivinv;
        for(ll=0;ll<=n-1;ll++)
        {
            if(ll!=icol)
			{
                dum=a[ll*n+icol];
                a[ll*n+icol]=0.0;
                for(l=0;l<=n-1;l++)
				{
                    a[ll*n+l]=a[ll*n+l]-a[icol*n+l]*dum;
                }
                b[ll]=b[ll]-b[icol]*dum;
            }
        }
	}	
    for(l=n-1;l<=0;l--)
	{
        if(indxr[l]!=indxc[l])
		{
            for(k=0;k<=n-1;k++)
			{
                dum=a[k*n+indxr[l]];
                a[k*n+indxr[l]]=a[k*n+indxc[l]];
                a[k*n+indxr[l]]=dum;
            }
        }
    }
}

 void main()
 {
 int i,j,l,n;
 n=3;
 double a[3][3],b[3],a1[9],b1[3];
 //已知方誠是係數
 a[0][0]=2;a[0][1]=1;a[0][2]=2;
 a[1][0]=5;a[1][1]=-1;a[1][2]=1;
 a[2][0]=1;a[2][1]=-3;a[2][2]=-4;
 b[0]=5;
 b[1]=8;
 b[2]=-4;
 cout<<b[0]<<endl;
 cout<<b[1]<<endl;
 cout<<b[2]<<endl;
 cout<<endl;
 for(i=0;i<n;i++)
 {
	for(j=0;j<n;j++)
	{
		a1[(i*n+j)]=0;
		a1[(i*n+j)]=a[i][j];
	}
 }
 gaussj(a1,n,b);
 cout<<b[0]<<endl;
 cout<<b[1]<<endl;
 cout<<b[2]<<endl;
 }
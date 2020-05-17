#include <iostream>

#include <cstdio>
#include <cmath>
#define N 5//N個點	輸入的X和Y的筆數
#define T 4 //T次擬合 設定轉移函數的階數
#define W 1//權函數
#define PRECISION 0.00001

//資料來源 http://blog.pfan.cn/weiyutian/41873.html

using namespace std;

float pow_n(float a,int n)//a^n a的n次方
{
	int i;
	if(n==0)
	{
		return(1);
	}

	float res=a;
	for(i=1;i<n;i++)
	{
		res*=a;
	}
	return(res);
}
void multiple(float a[][N],float b[][T+1],float c[][T+1])
{
	float res=0;
	int i,j,k;
	for(i=0;i<T+1;i++)
	{
		for(j=0;j<T+1;j++)
		{
			res=0;
			for(k=0;k<N;k++)
			{
				res+=a[i][k]*b[k][j];
				c[i][j]=res;
			}
		}
	}
}
void matrix_trans(float a[][T+1],float b[][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<T+1;j++)
		{
			b[j][i]=a[i][j];
		}
	}
}
void init(float x_y[][2],int n)
{
	int i;
	printf("請輸入%d個已知點：\n",N);
	for(i=0;i<n;i++)
	{
		printf("(x%d y%d):",i,i);
		scanf("%f %f",&x_y[i][0],&x_y[i][1]);
	}
}
void get_A(float matrix_A[][T+1],float x_y[][2],int n)
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<T+1;j++)
		{
			matrix_A[i][j]=W*pow_n(x_y[i][0],j);
		}
	}
}
void print_array(float array[][T+1],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<T+1;j++)
		{
			printf("%-g\t",array[i][j]);
		}
		printf("\n");
	}
}
void convert(float argu[][T+2],int n)
{
	int i,j,k,p,t;
	float rate,temp;
	for(i=1;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(argu[i-1][i-1]==0)
			{
				for(p=i;p<n;p++)
				{
					if(argu[p][i-1]!=0)
						break;
				}
				if(p==n)
				{
					printf("方程組無解!\n");
					return ;
				}
				for(t=0;t<n+1;t++)
				{
					temp=argu[i-1][t];
					argu[i-1][t]=argu[p][t];
					argu[p][t]=temp;
				}
			}
			rate=argu[j][i-1]/argu[i-1][i-1];
			for(k=i-1;k<n+1;k++)
			{
				argu[j][k]-=argu[i-1][k]*rate;
				if(fabs(argu[j][k])<=PRECISION)
				argu[j][k]=0;
			}
		}
	}
}
void compute(float argu[][T+2],int n,float root[])
{
	int i,j;
	float temp;
	for(i=n-1;i>=0;i--)
	{
		temp=argu[i][n];
		for(j=n-1;j>i;j--)
		{
			temp-=argu[i][j]*root[j];
		}
		root[i]=temp/argu[i][i];
	}
}
void get_y(float trans_A[][N],float x_y[][2],float y[],int n)
{
	int i,j;
	float temp;
	for(i=0;i<n;i++)
	{
		temp=0;
		for(j=0;j<N;j++)
		{
			temp+=trans_A[i][j]*x_y[j][1];
		}
		y[i]=temp;
	}
}
void cons_formula(float coef_A[][T+1],float y[],float coef_form[][T+2])
{
	int i,j;
	for(i=0;i<T+1;i++)
	{
		for(j=0;j<T+2;j++)
		{
			if(j==T+1)
				coef_form[i][j]=y[i];
			else
				coef_form[i][j]=coef_A[i][j];
		}
	}
}
void print_root(float a[],int n)
{
	int i,j;
	printf("%d個點的%d次擬合的多項式係數為:\n",N,T);
	for(i=0;i<n;i++)
	{
		printf("a[%d]=%g,",i+1,a[i]);
	}
	printf("\n");
	printf("擬合曲線方程為:\ny(x)=%g",a[0]);
	for(i=1;i<n;i++)
	{
		printf(" + %g *X^%d",a[i],i);
		/*
		for(j=0;j<i;j++)
		{
			printf("*X");
		}
		*/
	}
	printf("\n");
}
void process()
{
	float x_y[N][2],matrix_A[N][T+1],trans_A[T+1][N],coef_A[T+1][T+1],coef_formu[T+1][T+2],y[T+1],a[T+1];
	init(x_y,N);
	get_A(matrix_A,x_y,N);
	printf("矩陣A為：\n");
	print_array(matrix_A,N);
	matrix_trans(matrix_A,trans_A);
	multiple(trans_A,matrix_A,coef_A);
	printf("法矩陣為：\n");
	print_array(coef_A,T+1);
	get_y(trans_A,x_y,y,T+1);
	cons_formula(coef_A,y,coef_formu);
	convert(coef_formu,T+1);
	compute(coef_formu,T+1,a);
	print_root(a,T+1);
}
int main()
{
	process();
	return 0;
}
/*
你可以改一下
不從終端輸入,直接在程式中給出參數
請輸入5個已知點：
(x0 y0):-2 -0.1
(x1 y1):-1 0.1
(x2 y2):0 0.4
(x3 y3):1 0.9
(x4 y4):2 1.6
矩陣A為：
1         -2        4         -8
1         -1        1         -1
1         0         0         0
1         1         1         1
1         2         4         8
法矩陣為：
5         0         10        0
0         10        0         34
10        0         34        0
0         34        0         130
5個點的3次擬合的多項式係數為:
a[1]=0.408571,    a[2]=0.391667,    a[3]=0.0857143, a[4]=0.00833333,
擬合曲線方程為:
y(x)=0.408571 + 0.391667*X + 0.0857143*X*X + 0.00833333*X*X*X
*/

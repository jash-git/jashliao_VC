#include "mathfunc.h"
#include "stdlib.h"
#include "malloc.h"
#include "memory.h"
#include "string.h"
//#include "wi.h"
#define TAPEDDATADIM 1024


void lowpassfilter(double *data,double threshold,unsigned long dataLen)
{
	int r=0;
	unsigned long i,mask=0xffffffff;
	while(mask&dataLen)
	{
		mask<<=1;
		r++;
	}
	unsigned long count = 1<<r;
	complex *com1,*com2;
	com1 = (complex *)malloc(sizeof(complex)*count);
	com2 = (complex *)malloc(sizeof(complex)*count);
	//Initiallize
	for (i = 0; i < count; i++)
	{
		com1[i].r = i>=dataLen?0:data[i];
		com1[i].i = 0.0;
	}

	fft(com1,com2, r);
	
	for(i = (int)((threshold/2)*count); i< count; i++)
	{
		com2[i].r = 0.0;
	}

	ifft (com2,com1, r);
	
	for(i = 0;i<dataLen;i++)
	{
		data[i] = com1[i].r;
	}

}


void  fft(complex *td, complex *fd, int r)
{
	// ����Ҷ�任����
	long	count;
	
	// ѭ������
	int		i,j,k;
	
	// �м����
	int		bfsize,p;
	
	// �Ƕ�
	double	angle;
	
	complex *w,*x1,*x2,*x;
	
	// ���㸶��Ҷ�任����
	count = 1 << r;
	
	// ������������洢��
	w = (complex *)malloc(sizeof(complex)*count/2);
	x1 = (complex *)malloc(sizeof(complex)*count);
	x2 = (complex *)malloc(sizeof(complex)*count);
	
	// �����Ȩϵ��
	for(i = 0; i < count / 2; i++)
	{
		angle = -i * PI * 2 / count;
		w[i].r = cos(angle);
		w[i].i = sin(angle);
	}
	
	// ��ʱ���д��X1
	memcpy(x1, td, sizeof(complex) * count);
	
	// ���õ����㷨���п��ٸ���Ҷ�任
	for(k = 0; k < r; k++)
	{
		for(j = 0; j < 1 << k; j++)
		{
			bfsize = 1 << (r-k);
			for(i = 0; i < bfsize / 2; i++)
			{
				p = j * bfsize;
				x2[i + p].r = x1[i + p].r + x1[i + p + bfsize / 2].r;
				x2[i + p].i = x1[i + p].i + x1[i + p + bfsize / 2].i;
				x2[i + p + bfsize / 2].r = (x1[i + p].r - x1[i + p + bfsize / 2].r) * w[i * (1<<k)].r
										  -(x1[i + p].i - x1[i + p + bfsize / 2].i) * w[i * (1<<k)].i;
				x2[i + p + bfsize / 2].i = (x1[i + p].i - x1[i + p + bfsize / 2].i) * w[i * (1<<k)].r
										  +(x1[i + p].r - x1[i + p + bfsize / 2].r) * w[i * (1<<k)].i;
			}
		}
		x  = x1;
		x1 = x2;
		x2 = x;
	}
	
	// ��������
	for(j = 0; j < count; j++)
	{
		p = 0;
		for(i = 0; i < r; i++)
		{
			if (j&(1<<i))
			{
				p+=1<<(r-i-1);
			}
		}
		fd[j]=x1[p];
	}
	
	// �ͷ��ڴ�
	free(w);
	free(x1);
	free(x2);
}

void ifft(complex *fd, complex *td, int r)
{
	// ����Ҷ�任����
	long 	count;
	
	// ѭ������
	int		i;
	
	complex  *x;
	
	// ���㸶��Ҷ�任����
	count = 1 << r;
	
	// ������������洢��
	x = (complex *)malloc(sizeof(complex)*count);
	// ��Ƶ���д��X
	memcpy(x, fd, sizeof(complex) * count);
	
	// ����
	for(i = 0; i < count; i++)
	{
		x[i].r = x[i].r;
		x[i].i = -x[i].i;
	}
	
	// ���ÿ��ٸ���Ҷ�任
	fft(x, td, r);
	
	// ��ʱ���Ĺ���
	for(i = 0; i < count; i++)
	{
		td[i].r = td[i].r/count;
		td[i].i = -td[i].i/count;
	}
	
	// �ͷ��ڴ�
	free(x);
}


float MinFloat(float a,float b)
{
	if(a<=b)
		return a;
	else 
		return b;
}

float AbsFloat(float a)
{
	if(a<0)
		return -a;
	else
		return a;
}

int AbsInt(int a)
{
	if(a<0)
		return -a;
	else 
		return a;
}

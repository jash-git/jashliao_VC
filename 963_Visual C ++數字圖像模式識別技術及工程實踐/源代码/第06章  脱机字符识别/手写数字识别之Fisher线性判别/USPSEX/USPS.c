/*Fisher.C
*recognition of handwritten numerals with Fishier Linear Classifier
*/
/*
*˵����һ������16X16���أ�ÿ�������ǻҶ�ֵ��
*��һ��Ϊ-1��1��˫���ȸ�����
*
*struct Sample
*{
*	double data[RAWDATADIM];	//һ���������Ϊ8 byte
*	double feature[FEADIM];		//��������
*	int trueClass;	//��ʵ���
*	int classifiedClass[10]; //��ʶ��ķ��࣬��Ӧλ��1
*	int isClassified; // 1 for true and -1 for false
*};
*���� 6 ��Ӧ��classifiedClass[10]Ϊ��-1-1-1-1-1-11-1-1-1
*
*/

#include <stdio.h>
#include "math.h"
#include "stdlib.h"

#define TRAININGSNUM	 7291	//ѵ��������
#define TESTINGSNUM		 2007	//����������
#define RAWDATADIM		 256	//ÿ�����ֵ���������
#define FEADIM			 60	//��ȡ������ά��

#define SUCCESSFUL		 0
#define FAIL			 -1

struct Sample
{
	double data[RAWDATADIM];	//һ���������Ϊ8 byte
	double feature[FEADIM];		//��������
	int trueClass;	//��ʵ���
	int classifiedClass[10]; //��ʶ��ķ��࣬��Ӧλ��1
	int isClassified; // 1 for true and -1 for false
};

struct Sample trainingSample[TRAININGSNUM];	//ѵ������
struct Sample testingSample[TESTINGSNUM];	//��������

int points[FEADIM][2];	//������
double dirToMap[FEADIM][1];	//ӳ������
double meanC1, meanC2;	//��һ�࣬�ڶ���ӳ���ľ�ֵ
int nC1, nC2;	//�����ѵ��������

/*******************************************************************
 *�����������
 *������A��B��C
 *      A[m,n]��B[n,k]��C[m,k]
 */
void brmul(a, b, m, n, k, c)
int m, n, k;
double a[], b[], c[];
{
	int i, j, l, u;
	for (i=0; i<=m-1; i++)
		for (j=0; j<=k-1; j++)
		{ 
			u = i*k+j; 
			c[u] = 0.0;
			for (l=0; l<=n-1; l++)
				c[u] = c[u] + a[i*n+l]*b[l*k+j];
		}
		
	return;
}

/****************************************************************
 *��������
 *������A������
 *      n�������ά��
 */
int brinv(a, n)
int n;
double a[];
{ 
	int *is, *js, i, j, k, l, u, v;
	double d, p;
	is = (int *) malloc(n*sizeof(int));
	js = (int *) malloc(n*sizeof(int));

	for (k=0; k<=n-1; k++)
	{ 
		d=0.0;
		for (i=k; i<=n-1; i++)
			for (j=k; j<=n-1; j++)
			{ 
				l=i*n+j; 
				p=fabs(a[l]);
				if (p>d) 
				{ 
					d=p; 
					is[k]=i; 
					js[k]=j;
				}
			}

		if (d+1.0==1.0)
		{ 
			free(is); 
			free(js); 
			printf("err**not inv\n");
			return(0);
		}
		if (is[k]!=k)
			for (j=0; j<=n-1; j++)
			{ 
				u=k*n+j; 
				v=is[k]*n+j;
				p=a[u]; 
				a[u]=a[v]; 
				a[v]=p;
			}
        
		if (js[k]!=k)
			for (i=0; i<=n-1; i++)
			{ 
				u=i*n+k; 
				v=i*n+js[k];
				p=a[u]; 
				a[u]=a[v]; 
				a[v]=p;
			}
				
		l=k*n+k;
		a[l]=1.0/a[l];
		for (j=0; j<=n-1; j++)
			if (j!=k)
			{ 
				u=k*n+j; 
				a[u]=a[u]*a[l];
			}
				
		for (i=0; i<=n-1; i++)
			if (i!=k)
				for (j=0; j<=n-1; j++)
					if (j!=k)
					{ 
						u=i*n+j;
						a[u]=a[u]-a[i*n+k]*a[k*n+j];
					}
        
		for (i=0; i<=n-1; i++)
			if (i!=k)
			{ 
				u=i*n+k; 
				a[u]=-a[u]*a[l];
			}
	}
    
	for (k=n-1; k>=0; k--)
	{ 
		if (js[k]!=k)
			for (j=0; j<=n-1; j++)
			{ 
				u=k*n+j; 
				v=js[k]*n+j;
				p=a[u]; 
				a[u]=a[v]; 
				a[v]=p;
			}
        
		if (is[k]!=k)
			for (i=0; i<=n-1; i++)
			{ 
				u=i*n+k; 
				v=i*n+is[k];
				p=a[u]; 
				a[u]=a[v]; 
				a[v]=p;
			}
	}
	
	free(is); 
	free(js);
	return(1);
}

/*
*retrieveSample (s, n, dfname, cfname)

*funtion to retrieve data from binary data file
*s: ���������ͷָ�룬trainingSample or testingSample
*n: number of samples
*dfname: file name of sample data
*cfname: file name of information on true class
*
*/
int retrieveSample (s, n, dfname, cfname)
struct Sample *s;
int n;
char *dfname, *cfname;
{
	FILE *fdf, *fcf;
	
	int sclass[10];

	int i, j;
	//open datafile
	if	((fdf = fopen (dfname, "rb")) == NULL)
	{
		printf ("Can't open file %s\n", dfname);
		return FAIL;
	}
	
	//open classfile
	if ((fcf = fopen (cfname, "rb")) == NULL)
	{
		printf ("Can't open file %s\n", cfname);
		return FAIL;
	}
	
	for (i = 0; i < n; i++)
	{
		fread (s[i].data, sizeof (double), RAWDATADIM, fdf);//retrieve gray data
		fread (sclass, sizeof (int), 10, fcf);
		for (j = 0; j < 10; j++)
		{
			(*(s + i)).classifiedClass[j] = -1; //initiate -1
			if (sclass[j] == 1)
				(*(s + i)).trueClass = j;  //load trueClass
		}
		(*(s + i)).isClassified = -1;//have not been classified

	}

	fclose (fdf);
	fclose (fcf);
	return SUCCESSFUL;
}

/*
int selPoints (serial1,serial2)
ѡȡ������
serial1:��һ�����
serial2:�ڶ������
*/

int selPoints (serial1,serial2)

int serial1;
int serial2;

{
	double sumC1[RAWDATADIM], sumC2[RAWDATADIM],diff[RAWDATADIM];
	int i,j;
	int n1, n2;

	double uBound, lBound;
	int index;

	n1 = n2 = 0;
	for (i = 0; i < RAWDATADIM; i++)
	{
		sumC1[i] = 0;
		sumC2[i] = 0;
	}

	for (i = 0; i < TRAININGSNUM; i++)
	{
		if (trainingSample[i].trueClass == serial1)
		{
			n1++;
			for (j = 0; j < RAWDATADIM; j++)
				sumC1[j] += trainingSample[i].data[j];
		}
		else if(trainingSample[i].trueClass == serial2) 
		{
			n2++;
			for (j =0; j < RAWDATADIM; j++)
				sumC2[j] += trainingSample[i].data[j];
		}
	}

	if (n1 == 0 || n2 == 0)
		return FAIL;

	for (i = 0; i < RAWDATADIM; i++)
	{
		sumC1[i] = sumC1[i]/n1;
		sumC2[i] = sumC2[i]/n2;
		diff[i] = fabs(sumC1[i] - sumC2[i]);
	}
	
	//����Ѱ�ҵ�һ��͵ڶ���ƫ����С�ĵ�Ϊ������

	lBound = 0; uBound = 3;
	//lBoundָʾ��ǰһ�ֵ����ֵ��uBoundָʾǰһ�ֵ����ֵ
	for (j = 0; j < FEADIM; j++)
	{
		for (i = 0; i < RAWDATADIM; i++)
			if (lBound < diff[i] && uBound > diff[i])
			{
				lBound = diff[i];//find the Maximum
				index = i;
			}
		uBound = lBound;
		lBound = 0;
		points[j][0] = index / ((int)sqrt (RAWDATADIM));
		points[j][1] = index % ((int)sqrt (RAWDATADIM));
	}
	return SUCCESSFUL;
}


/*
void genFeature (s,n)
������ȡ
s:�����ṹstruct Sample��ָ�룬 trainingSample or testingSample
n:number of samples
*/
void genFeature (s,n)
struct Sample *s;
int n;

{
	int i, j, t;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < FEADIM; j++)
		{
			t = points[j][0] * (int)sqrt(RAWDATADIM) + points[j][1];
			s[i].feature[j] = s[i].data[t];
		}
	}
	return;
}


/*
int Fisher (serial1,serial2)

serial1��һ�����ţ�serial2�ڶ�������
1������ͶӰ����double dirToMap[FEADIM][1]���Ѷ�ά�ռ�ӳ�䵽һά�ռ�
2������meanC1,meanC2��������ľ�ֵ
3������nC1,nC2���������������
*/
int Fisher (serial1, serial2)
int serial1;
int serial2;

{
	struct Sample *s;
	double meanVector1[FEADIM], meanVector2[FEADIM], diffVector[FEADIM];
	double sumC1[FEADIM], sumC2[FEADIM];

	double SW[FEADIM][FEADIM];//������������ɢ�Ⱦ���
	double tempMtrx[FEADIM][FEADIM];
	double tempV1[FEADIM][1];
	double tempV2[1][FEADIM];
	double tempV[1][1];

	int i, j, k;
	int flag;

	s = trainingSample;

	nC1 = nC2 = 0;//��ʼ��
	
	for (j = 0; j < FEADIM; j++)
	{
		sumC1[j] = 0;
		sumC2[j] = 0;
		for (k = 0; k < FEADIM; k++)
			SW[j][k] = 0;
	}

	for (i = 0; i < TRAININGSNUM; i++)
	{
		if (s[i].trueClass == serial1)
		{
			++nC1;//��һ����������1
			for (j = 0; j < FEADIM; j++)
			{
				sumC1[j] += s[i].feature[j]; 
			}
		}
		if (s[i].trueClass == serial2) 
		{
			++nC2;//�ڶ�����������1
			for (j = 0; j < FEADIM; j++)
			{
				sumC2[j] += s[i].feature[j]; 
			}
		}
	}

	if (nC1 == 0 || nC2 == 0)//ĳһ��û�����������ش���
	{
		return FAIL;
	}

	for (j = 0; j < FEADIM; j++)
	{
		meanVector1[j] = sumC1[j]/nC1;
		meanVector2[j] = sumC2[j]/nC2;
		diffVector[j] = meanVector1[j] - meanVector2[j];
	}

	for (i = 0; i < TRAININGSNUM; i++)
	{
		if (s[i].trueClass == serial1 || s[i].trueClass == serial2)
		{
			if (s[i].trueClass == serial1)
				for (j = 0; j < FEADIM; j++)
				{
					tempV1[j][0]  = s[i].feature[j] - meanVector1[j];
					tempV2[0][j] = tempV1[j][0];
				}
			if (s[i].trueClass == serial2) 
				for (j = 0; j < FEADIM; j++)
				{
					tempV1[j][0] = s[i].feature[j] - meanVector2[j];
					tempV2[0][j] = tempV1[j][0];
				}

		//�����������һ����������ɢ�Ⱦ���
		//	tempMtrx[FEADIM][FEADIM] = tempV1 * tempV2 
		
			brmul(tempV1,tempV2,FEADIM,1,FEADIM,tempMtrx);
		
			for (j = 0; j < FEADIM; j++)
				for (k = 0; k < FEADIM; k++)
					SW[j][k] =SW[j][k] + tempMtrx[j][k];
		}

	}

	//��һ��SW�����������������̫С������������������
	for (j = 0; j <FEADIM; j++)
		for (k = 0; k < FEADIM; k++)
			SW[j][k] = SW[j][k] / (nC1 + nC2);


	//������dirToMap, meanC1, meanC2
	//dirToMap = SW- * (meanVector1 - meanVector2)
	//meanC1 = T(dirToMap) * meanVector1
	//meanC2 = T(dirToMap) * meanVector2
	for (j = 0; j < FEADIM; j++)
		tempV1[j][0] = diffVector[j];
	
	//��������
	flag = brinv(SW,FEADIM);
	if (flag != 1)
		return FAIL;

	brmul(SW, tempV1, FEADIM, FEADIM, 1, dirToMap);//�õ�dirToMap

	for (j = 0; j < FEADIM; j++)
	{
		tempV2[0][j] = dirToMap[j][0];//ת��
		tempV1[j][0] = meanVector1[j];
	}
	brmul(tempV2, tempV1, 1, FEADIM, 1, tempV);
	meanC1 = tempV [0][0];//�õ�meanC1

	for (j = 0; j < FEADIM; j++)
	{
		tempV1[j][0] = meanVector2[j];
	}
	brmul(tempV2, tempV1, 1, FEADIM, 1, tempV);
	meanC2 = tempV[0][0];//�õ�meanC2

	return SUCCESSFUL;
}


/*
classifier (s)
s: certain testing sample
classifying using
dirToMap ,meanC1,meanC2, feature
����ʱ�Ѷ�������ת��Ϊ�������⣬��������������Ϊ�о����
�磺0���1��Ƚϣ������Դ���ٺ�3��Ƚϣ���������
*/
int classifier (s)
struct Sample *s;
{
	
	int serial1;
	int serial2;

	int flag;//�ɹ����ı�ʶ
	double critical;//�о��ٽ�ֵ
	double tempV[1][1];
	double tempV1[FEADIM][1],tempV2[1][FEADIM];
	int count, j;
	
	serial1 =0;//��һ���ʼ��Ϊ0

	for (count = 1; count < 10; count++)
	{
		serial2 = count;

		//ѡ��������
		flag = selPoints (serial1, serial2);
		if (flag == FAIL)
			return FAIL;

		//��ȡ����
		genFeature (trainingSample, TRAININGSNUM);
		genFeature (testingSample, TESTINGSNUM);

		//���������
		if (Fisher (serial1, serial2) != SUCCESSFUL)
			return FAIL;


		//��ʼ�б�

		if (nC1 ==0 || nC2 ==0)
			return FAIL;

		critical = (meanC1 * nC1 + meanC2 * nC2) / (nC1 + nC2);

		for (j = 0; j < FEADIM; j++)
		{
			tempV2[0][j] = dirToMap[j][0];//ת��
			tempV1[j][0] = (*s).feature[j];
		}

		brmul(tempV2, tempV1, 1, FEADIM, 1, tempV);
	
		if (tempV[0][0] < critical)
			serial1 = serial2;
	}
				
	(*s).isClassified = 1;
	(*s).classifiedClass[serial1] = 1;

	return SUCCESSFUL;
}


/*
void ftestingSample (resultf)
char *resultf���������ļ�����
����classifier ()�����о���������
*/
void ftestingSample (resultf)

char *resultf;
{
	struct Sample *s;
	FILE *rf;
	
	int flag;
	int i, j, k, tempClass;
	int rightNum, errorNum;
	double ratio;
		
	s = testingSample;

	if	((rf = fopen (resultf, "a")) == NULL)
	{
		printf ("Can't open file %s\n", resultf);
		return;
	}

	errorNum = 0;
	for (i = 899; i < TESTINGSNUM; i++)
	{	
		flag = classifier (s + i);//�е�i����������
		if (flag == FAIL)
			return;
			
		fprintf (rf, "Sample %d (%d):\n", i, s[i].trueClass);
		fprintf (rf, "Classified to :");
		
		printf ("Sample %d (%d):\n", i, s[i].trueClass);
		printf ("Classified to :");

		k = 0;

		for (j = 0; j < 10; j++)
		{
			if (s[i].classifiedClass[j] == 1)
			{
				k++;
				tempClass = j;
				fprintf (rf, "%d ", j);
				printf ("%d ", j);
			}
		}
		
		if (k !=1 || tempClass != s[i].trueClass)
		{
			fprintf (rf, "\nError\n\n");
			printf ("Error\n");
			errorNum++;
		}	
		else
		{
			fprintf (rf, "\n\n\n");
			printf ("\n");
		}	
	}
	
	//ͳ��			
	rightNum = TESTINGSNUM - errorNum;
	ratio =  (double)rightNum/(double)TESTINGSNUM;
	fprintf (rf, "\n\nStatistics\n");
	fprintf (rf, "------------------------------------------\n\n");
	fprintf (rf,"Right :%d		Error:%d	Ratio:%f\n",
		rightNum, errorNum, ratio);

	fclose (rf);
	return;
}


void main (void)
{
	char *dfname1 = "D:\\usps\\trainData.bina";
	char *cfname1 = "D:\\usps\\trainDataResult.bina";
	char *dfname2 = "D:\\usps\\testData.bina";
	char *cfname2 = "D:\\usps\\testDataResult.bina";
	char *resultf = "D:\\usps\\result.txt";

	int flag;

	//��ȡ����
	flag = retrieveSample (
		trainingSample, TRAININGSNUM, dfname1, cfname1);
	if (flag != SUCCESSFUL) return;
	
	flag = retrieveSample (
		testingSample, TESTINGSNUM, dfname2, cfname2);
	if (flag != SUCCESSFUL) return;

	//��������
	ftestingSample (resultf);
}

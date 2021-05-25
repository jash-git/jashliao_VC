// Wi.cpp: implementation of the CWi class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WiRecognition.h"
#include "Wi.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWi::CWi()
{
	InitHMM(&hmm, 10, VQ_M, 12);		//��ʼ��ģ�Ͳ���	
}
/****************************************************************************/
/*�������� �ͷ�Ϊ�����������ݶ�������ڴ�
/*
/****************************************************************************/
CWi::~CWi()
{
	int iCount = trainSampleArray.GetSize ();
	//TRACE("iCount = %d\n", iCount);
	int i = 0;
	while (i < iCount)
	{
		struct Sample *s = (struct Sample *)trainSampleArray.GetAt (i);
		free(s);
		i++;
	}
	iCount = testSampleArray.GetSize ();
	i = 0;
	while (i < iCount)
	{
		struct Sample *s = (struct Sample *)testSampleArray.GetAt (i);
		free(s);
		i++;
	}


}

/****************************************************************************/
/*	���ļ�����ӵ� trainSetDataFilePath �� testSetDataFilePath
/*	strPath ��Ҫ������ļ���
/*  flag = 0 �ļ�����trainSetDataFilePath flag = 1 ʱ �ļ�����trainSetDataFilePath
/****************************************************************************/
void CWi::AddSampleSetPath (CString strPath, int flag)
{
	if (flag == 0)			//train set
		trainSetDataFilePath.Add (strPath);
	else
		testSetDataFilePath.Add (strPath);
}
/****************************************************************************/
/*	ɾ�������е������ļ�
/*	flag = 0 ɾ�� trainSetDataFilePath 
/*  flag = 1 ɾ�� testSetDataFilePath
/****************************************************************************/
void CWi::DelSampleSetPath (int flag)
{
	if (flag == 0)			//train set
		trainSetDataFilePath.RemoveAll();
	else
		testSetDataFilePath.RemoveAll();
}
/****************************************************************************/
/*���ļ��ж�ȡ����
/* s �����ļ����ݵĽṹ��ָ��	
/* filePath �ļ���
/****************************************************************************/
void CWi::ParseDataFromFile1 (CWi::Sample *s, CString filePath)
{
	FILE *fdf;
	
	int i;
	int baseA,baseB,baseC;
	//open datafile
	if	((fdf = fopen (filePath, "rb")) == NULL)
	{
		TRACE(_T("Can't open file %s\n"), filePath);
		return;
	}

	fseek (fdf, 0, SEEK_SET);
	
	unsigned char firstByte, secondByte;
	unsigned int firstByteInt, secondByteInt;
	i = 0;
	while ((i < RAWDATADIM) && (!feof (fdf)))
	{
		fread (&firstByte, 1, 1, fdf);//retrieve gray data
		fread (&secondByte, 1, 1, fdf);
		firstByteInt = (int)firstByte;
		secondByteInt = (int)secondByte;
		if(i==0)
			baseC = ((firstByteInt >> 6) | (secondByteInt << 2));
		s->pressC[i] = (double) ((firstByteInt >> 6) | (secondByteInt << 2))-baseC;
		
		fread (&firstByte, 1, 1, fdf);//retrieve gray data
		fread (&secondByte, 1, 1, fdf);
		firstByteInt = (int)firstByte;
		secondByteInt = (int)secondByte;
		if(i==0)
			baseA = ((firstByteInt >> 6) | (secondByteInt << 2));
		s->pressA[i] = (double) ((firstByteInt >> 6) | (secondByteInt << 2))-baseA;
	
		fread (&firstByte, 1, 1, fdf);//retrieve gray data
		fread (&secondByte, 1, 1, fdf);
		firstByteInt = (int)firstByte;
		secondByteInt = (int)secondByte;
		if(i==0)
			baseB = ((firstByteInt >> 6) | (secondByteInt << 2));
		s->pressB[i] = (double) ((firstByteInt >> 6) | (secondByteInt << 2))-baseB;
		i++;	
			 
	}
	
	/*for (i = 0; i < RAWDATADIM; i++)
		TRACE("No. %d: c = %f, a = %f, b = %f\n", 
				i, s->pressC[i], s->pressA[i], s->pressB[i]);
	*/	
	
}

/****************************************************************************/
/* ���ܣ���ǩ���ļ��ж�ȡ����
/* ������s��������������
/*       filepath���ļ�·��
/****************************************************************************/
void CWi::ParseDataFromFile2 (CWi::Sample *s, CString filePath)
{
	FILE *fdf;
	
	int i;
	long length;
	//open datafile
	if	((fdf = fopen (filePath, "rb")) == NULL)
	{
		TRACE(_T("Can't open file %s\n"), filePath);
		return;
	}

	fseek (fdf, 0, SEEK_SET);
	fread (&length,sizeof(long),1,fdf);
	for(i = 0;i<RAWDATADIM;i++)
	{
		s->xLoc2[i]=s->yLoc2[i]=0.0;
		s->pressTotal2[i]=s->pressTotal[i]=0.0;
	}
	i = 0;
	while ((i < length) && (!feof (fdf)))
	{
		fread(&s->point[i],sizeof(PenPoint),1,fdf);			
		s->xLoc[i] = s->xLoc2[i] = s->point[i].x;
		s->yLoc[i] = s->yLoc2[i] = s->point[i].y;
		s->pressTotal[i] = s->pressTotal2[i] = s->point[i].pressure;
		i++;
	}
	s->effectDataNum = length;
	if(!feof(fdf))
		return;
	for( i = length; i<RAWDATADIM;i++)
	{
		s->xLoc[i] = s->xLoc2[i] = 0;
		s->yLoc[i] = s->yLoc2[i] = 0;
		s->pressTotal[i] = s->pressTotal2[i] = 0;
	}
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
void CWi::ParseDataFromFile3 (CWi::Sample *s, CString filePath)
{
	FILE *fdf;
	
	int i;
	//open datafile
	if	((fdf = fopen (filePath, "rb")) == NULL)
	{
		TRACE(_T("Can't open file %s\n"), filePath);
		return;
	}

	fseek (fdf, 0, SEEK_SET);
	
	unsigned char firstByte;
	i = 0;
	while ((i < RAWDATADIM) && (!feof (fdf)))
	{
		fread (&firstByte, 1, 1, fdf);	//retrieve gray data
		s->pressC[i] = (double) firstByte;
		
		fread (&firstByte, 1, 1, fdf);	//retrieve gray data
		s->pressA[i] = (double) firstByte;
	
		fread (&firstByte, 1, 1, fdf);	//retrieve gray data
		s->pressB[i] = (double) firstByte;
		i++;	
	}
	
	for (i = 0; i < RAWDATADIM; i++)
		TRACE("No. %d: c = %f, a = %f, b = %f\n", 
				i, s->pressC[i], s->pressA[i], s->pressB[i]);
}
/****************************************************************************/
/* ���ܣ���һ���ļ��ж�ȡ����
/* ������samplePathArrayRef���ļ�·������
/*       sampleArrayRef�������ļ����ݵ�����
/****************************************************************************/
void CWi::RetrieveSample (CStringArray* samplePathArrayRef, 
							 CPtrArray* sampleArrayRef)
{
	int sampleNum;//������
	int i;
	sampleArrayRef->RemoveAll ();
	sampleNum = samplePathArrayRef->GetSize ();

	for (i = 0; i < sampleNum; i++)
	{
		CString sampleDataFilePath = samplePathArrayRef->GetAt (i);//·����
		struct Sample *s = (struct Sample*) malloc (STRUCTSAMPLELEN);
		ParseDataFromFile2 (s, sampleDataFilePath);//��ȡ����
		/*��ֵ�˲�******/
		MedianFilter(s->pressA,RAWDATADIM);
		MedianFilter(s->pressB,RAWDATADIM);
		MedianFilter(s->pressC,RAWDATADIM);

		lowpassfilter(s->pressTotal2,0.6,s->effectDataNum);		

		//ConstructTotal (s);
		sampleArrayRef->Add (s);//��������
		Rotation(s->xLoc, s->yLoc,RAWDATADIM,(1+1.0/3.0)*3.1415);
	}
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
void CWi::ConstructTotal (CWi::Sample* s)
{
	int i; 
	for (i = 0; i < RAWDATADIM; i++)
	{
		s->pressTotal2[i] = s->pressTotal[i] = s->pressA[i] + s->pressB[i] + s->pressC[i];
		s->xLoc[i] = (0.5 * (s->pressB[i]) + (s->pressC[i]))/s->pressTotal[i] ;			
		s->yLoc[i] =s->pressB[i] / s->pressTotal[i];
	}

}


/****************************************************************************/
/* ���ܣ������ֵ
/* ������data������
/*       datalen�����鳤��
/****************************************************************************/
double CWi::CalculateAverage(double *data,int dataLen)
{
	double temp=0.0;
	int i;
	for(i = 0;i<dataLen;i++)
	{
		temp+=data[i];
	}
	return (temp/dataLen);
}

/****************************************************************************/
/* ���ܣ���ֵ��һ��
/* ������ data������
/*        datalen�����鳤��
/*        ��ֵ
/****************************************************************************/
void CWi::AverageNormalize(double *data,int dataLen,double value)
{
	double average;
	int i;
	average = CalculateAverage(data,dataLen);
	for(i = 0;i<dataLen;i++)
	{
		data[i] = (data[i]*value)/average;
	}
}

/****************************************************************************/
/* ���ܣ����䷶Χ��һ��
/* ������data������
/*       datalen�����鳤��
/****************************************************************************/
void CWi::NormalizeSample (double *data, int dataLen)
{
	int i;
	double dbMax, dbMin;
	dbMax = dbMin =data [0];
	for (i = 1; i < dataLen; i++)
	{
		if (dbMax < data [i])
			dbMax = data [i];
		if (dbMin > data [i])
			dbMin = data [i];
	}
	for (i = 0; i < dataLen; i++)
	{
		data [i] = (data [i] - dbMin) * 255 / (dbMax - dbMin);
	}
}

/****************************************************************************/
/* ���ܣ����䷶Χ��һ����ͬʱ��������Сֵ
/* ������data������
/*       max��������������ֵ
/*       min�������������Сֵ
/*       datalen������ĳ���
/****************************************************************************/

void CWi::NormalizeSample (double *data, double& max, double& min, 
								int dataLen)
{
	int i;
	double dbMax, dbMin;
	dbMax = dbMin =data [0];

	for (i = 1; i < dataLen; i++)
	{
 
		if (dbMax < data [i])
			dbMax = data [i];
		if (dbMin > data [i])
			dbMin = data [i];
	}

	for (i = 0; i < dataLen; i++)
	{
		data [i] = (data [i] - dbMin) * 255 / (dbMax - dbMin);
	//	TRACE("diff1data[%d] = %f \n", i, data[i]);
	}
	max = dbMax;
	min = dbMin;
}
/****************************************************************************/
/* ���ܣ���ǩ��������ͼ����й�һ��
/* ������s��ǩ������
/****************************************************************************/
void CWi::NormalizeImage (CWi::Sample* s)
{
	int j;
	double maxXLoc, maxYLoc, minXLoc, minYLoc;
	maxXLoc = s->xLoc2[0];
	maxYLoc = s->yLoc2[0];
	minXLoc = s->xLoc2[0];
	minYLoc = s->yLoc2[0];
	int dataNum = s->effectDataNum;
	for (j = 0; j < dataNum; j++)
	{
		if (maxXLoc < s->xLoc2[j])
			maxXLoc = s->xLoc2[j];
		if (minXLoc > s->xLoc2[j])
			minXLoc = s->xLoc2[j];
		if (maxYLoc < s->yLoc2[j])
			maxYLoc = s->yLoc2[j]; 
		if (minYLoc > s->yLoc2[j])
			minYLoc = s->yLoc2[j];
	}

	for (j = 0; j < dataNum; j++)
	{
		s->xLoc2[j] = (((s->xLoc2[j] -minXLoc) / (maxXLoc - minXLoc)) * IMAGEWIDTH)-1;
		s->yLoc2[j] = (((s->yLoc2[j] -minYLoc) / (maxYLoc - minYLoc)) * IMAGEHEIGHT)-1;
	}
	s->width = maxXLoc - minXLoc;
	s->height = maxYLoc - minYLoc;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::FTSample (double* dataSource, double* dataDest)
{

	int i;
	double* pr = dataDest;
	double pi[TAPEDDATADIM];
	//	double fr[TAPEDDATADIM];
	//	double fi[TAPEDDATADIM];

	//Initiallize
	for (i = 0; i < TAPEDDATADIM; i++)
	{
		pr [i] = dataSource[i];
		pi [i] = 0.0;
	}

	//����ʱpr���DFT��ģ��pi��ŷ���]
	//mth.kkfft (pr, pi, TAPEDDATADIM, 10, fr, fi, 0, 1);
	//NormalizeSample (pr, TAPEDDATADIM);
}

/****************************************************************************/
/* ���ܣ�����
/* ������dataSource��ԭ����
/*       dataDest��������������
/*       dataLen������ĳ���
/****************************************************************************/
void CWi::DiffSample (double* dataSource, double* dataDest, int dataLen)
{
	int i;
	
	for (i = dataLen - 1; i >0; i--)
		dataDest[i] = dataSource[i] - dataSource[i-1];//����
	dataDest[0] = dataDest[1];
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::FilterNoise (CWi::Sample* s, int critical)
{
	int i, j;

	j = 0;
	for (i = 0; i < RAWDATADIM; i++)
	{
		if (s->pressA[i] > critical && s->pressB[i] > critical && s->pressC[i] >critical )
		{
			s->pressTotal2[j] = s->pressTotal[i];		
			j++;
		}
		else
			s->pressTotal2[i] = 0; 

		s->xLoc2[j] = s->xLoc[i];
		s->yLoc2[j] = s->yLoc[i];
	
	}
	s->effectDataNum = j;
}

/****************************************************************************/
/* ���ܣ�����ǩ����������ͼ��
/* ������sampleArrayRef������ǩ������
/****************************************************************************/
void CWi::ConstructImage (CPtrArray* sampleArrayRef)
{
	int sampleNum = sampleArrayRef->GetSize ();
	int i, j, k, t;
	struct Sample *s;

	for (i = 0; i < sampleNum; i++)
	{
		s = (struct Sample *)sampleArrayRef->GetAt (i);

		for (j = 0; j < IMAGEWIDTH; j++)
			for (k = 0; k < IMAGEHEIGHT; k++)
				s->imgPixel[j][k] = 255.0;

		for (t = 0; t < RAWDATADIM; t++)
		{
			s->imgPixel[(int)s->xLoc2[t]][(int)s->yLoc2[t]] =255.0-s->pressTotal2[t];
		}
	}			

}

/****************************************************************************/
/*���ܣ���������������Ԥ����
/*������sampleArrayRef������ǩ������
/*      flag����������־
/****************************************************************************/
void CWi::PreProcSample(CPtrArray* sampleArrayRef, int flag)
{
	int sampleNum;
	int count;
	double max,min;
	sampleNum = sampleArrayRef->GetSize();

	for (count = 0; count < sampleNum; count++)
	{
		struct Sample *s;
		s = (Sample *)sampleArrayRef->GetAt (count);
		
		NormalizeSample (s->pressTotal2, max, min, s->effectDataNum);	//������һ��
		AverageNormalize(s->pressTotal2,s->effectDataNum,200.0);
		NormalizeImage (s);
	}

	ConstructImage(sampleArrayRef);
}

/****************************************************************************/
/* ���ܣ����ǩ��ÿ�����ݵ���ٶ�
/* ������s������ǩ������
/****************************************************************************/
void CWi::SpeedCurve(CWi::Sample* s)
{
	int num = s->effectDataNum;
	int subx,suby;
	double dis;
	for(int i = 0; i < num - 1; i++)
	{
		subx = s->point[i+1].x - s->point[i].x;
		suby = s->point[i+1].y - s->point[i].y;
		dis = SQUARE(subx) + SQUARE(suby);
		dis = sqrt(dis);
		s->speed[i] = dis;
	}
	s->speed[num-1] = s->speed[num-2];
	NormalizeSample(s->speed, s->effectDataNum);
}

/****************************************************************************/
/* ���ܣ���ǩ����������ת��Ϊʸ���������õ�����
/* ������sampleArrayRef������ǩ������
/****************************************************************************/
void CWi::GenVector(CPtrArray* sampleArrayRef)
{
	int sampleNum;
	int i,count;
 	sampleNum = sampleArrayRef->GetSize();

	for (count = 0; count < sampleNum; count++)
	{
		struct Sample *s;
		s = (Sample *)sampleArrayRef->GetAt (count);
		SpeedCurve(s);
		for(i = 0; i < s->effectDataNum; i++)
		{
			s->dataVec[i].num = 4;
			s->dataVec[i].data[0] = s->pressTotal2[i];
			s->dataVec[i].data[1] = s->xLoc2[i];
			s->dataVec[i].data[2] = s->yLoc2[i];
			s->dataVec[i].data[3] = s->speed[i];
		}
	}
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::GenVQVector(CPtrArray* sampleArrayRef)
{
	int sampleNum;
	int i,count;
 	sampleNum = sampleArrayRef->GetSize();

	for (count = 0; count < sampleNum; count++)
	{
		struct Sample *s;
		s = (Sample *)sampleArrayRef->GetAt (count);
		SpeedCurve(s);
		for(i = 0; i < s->effectDataNum; i++)
		{
			s->vq_vector[i].Data = (double *)malloc(sizeof(double)*4);
			s->vq_vector[i].nDimension = 4;
			s->vq_vector[i].Data[0] = s->pressTotal2[i];
			s->vq_vector[i].Data[1] = s->xLoc2[i];
			s->vq_vector[i].Data[2] = s->yLoc2[i];
			s->vq_vector[i].Data[3] = s->speed[i];
			s->vq_vector[i].nCluster = 0;     //��������ֵ 0
		}
	}

}

/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::GenVQVector()
{
	int i;
	for(i = 0; i < templenvec; i++)
	{
		vq_vector[i].Data = (double *)malloc(sizeof(double)*4);
		vq_vector[i].nDimension = 4;
		vq_vector[i].Data[0] = dtwtemplatev[i].data[0];
		vq_vector[i].Data[1] = dtwtemplatev[i].data[1];
		vq_vector[i].Data[2] = dtwtemplatev[i].data[2];
		vq_vector[i].Data[3] = dtwtemplatev[i].data[3];
		vq_vector[i].nCluster = 0;     //��������ֵ 0
	}

}

/****************************************************************************/
/* ���ܣ�����VQ�����ģ��
/****************************************************************************/
void CWi::GenVQTemplate()
{
	GenTemplateVector();
	GenVQVector();
	VQCluster();
	GenHMM();
	int num = trainSampleArray.GetSize();
	double posi;
	double min_pos = 0.0;
	double max_pos = -10000.0;
	for(int i = 0; i < num; i++)
	{
		CWi::Sample *s = (CWi::Sample *)trainSampleArray.GetAt(i);
		posi = PoHMM(s);
		if((posi < min_pos) && (posi > -10000.0))
			min_pos = posi;
		if(posi > max_pos)
			max_pos = posi;
	}
	threshold = thresholdhmm = min_pos;// - (max_pos - min_pos) / 2;
}

/****************************************************************************/
/* ���ܣ�ʸ������
/****************************************************************************/
void CWi::VQCluster()
{
	int i;
	for(i = 0; i < VQ_M; i++)
	{
		vq_center[i].nDimension = 1;
		vq_center[i].Data = (double *)malloc(sizeof(double) * 1);
		vq_center[i].Num = 0;	   //��ʼ��Ϊ 0
	}
	LBGCluster(vq_vector,templenvec , vq_center, VQ_M);
	for(i = 0; i < templenvec; i++)
	{
		vq_vector[i].nCluster++;
		vq_feature[i] = vq_vector[i].nCluster;
	}
}

/****************************************************************************/
/*���ܣ�ѵ��HMMģ��
/****************************************************************************/
void CWi::GenHMM()
{
	int niter;
	double logprobinit, logprobfinal;

	double **alpha = dmatrix(1, templenvec, 1, hmm.N);
	double **beta = dmatrix(1, templenvec, 1, hmm.N);
	double **gamma = dmatrix(1, templenvec, 1, hmm.N);

	BaumWelch(&hmm, templenvec, vq_feature, alpha, beta, gamma, &niter, &logprobinit, &logprobfinal);

	free_dmatrix(alpha, 1, templenvec, 1, hmm.N);
	free_dmatrix(beta, 1, templenvec, 1, hmm.N);
	free_dmatrix(gamma, 1, templenvec, 1, hmm.N);
}

/****************************************************************************/
/*���ܣ�����HMMģ�ͽ���ʶ��
/*������distance���������������ģ��ľ���
/*      index�������������±�
/****************************************************************************/
int CWi::RecogHMM(double *distance,int index)
{
	CWi::Sample *s = (CWi::Sample *)testSampleArray.GetAt(index);
	double pprob = PoHMM(s);
	*distance = pprob;
	if(pprob > thresholdhmm)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

/****************************************************************************/
/*���ܣ�������������ĳ��ָ���
/*������s����������
/****************************************************************************/
double CWi::PoHMM(CWi::Sample *s)
{
	VQClassify(s);
	double pprob;
	int *q = ivector(1,s->effectDataNum);
	double **delta = dmatrix(1, s->effectDataNum, 1, hmm.N);
	int **psi = imatrix(1, s->effectDataNum, 1, hmm.N);
	Viterbi(&hmm, s->effectDataNum, s->vq_feature, delta, psi,q, &pprob);
	if(pprob != 0)
		pprob = log(pprob)/(s->effectDataNum * log(VQ_M));
	else 
		pprob = -10000.0;
	return pprob;
}

/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::VQClassify(CWi::Sample *s)
{
	int i;
	for(i = 0; i < s->effectDataNum; i++)
	{
		s->vq_vector[i].nCluster = VQClassify(&vq_vector[i], vq_center);
		s->vq_feature[i] = s->vq_vector[i].nCluster;
	}

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

int CWi::VQClassify(struct VQ_VECTOR *vq, struct VQ_CENTER *vc)
{
	int i,j,min_index = -1;
	double distance = 0.0,temp = 0.0;
	double min_dis = 1000000.0;			//��ʼֵ
	for(i = 0; i < VQ_M; i++)
	{	
		distance = 0.0;
		for(j = 0; j < vq->nDimension; j++)
		{
			temp = vc[i].Data[j] - vq->Data[j];
			temp = SQUARE(temp);
			distance += temp;
		}
		distance = sqrt(distance);
		if(distance < min_dis)
		{
			min_dis = distance;
			min_index = i;
		}

	}

	min_index++;
	return min_index;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::SamplePress1(double *src,double *dst,int datalen,int inter)
{
	int i;
	for(i = 0;i<datalen;i++)
	{
		dst[i]= src[i];
	}
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::SamplePress2(double *src,double *dst,int datalen,int inter)
{
	int i,j;
	double temp=0.0;
	for(i = 0;i<datalen-1;i++)
	{
		for(j = 0; j<inter ;j++)
		{
			temp+=src[i*inter+j];
		}
		temp/=inter;
		dst[i] = temp;
		temp = 0.0;

	}
	dst[datalen-1] = src[datalen-1]; 

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

//��ȡ���壬���ȵ���Ϣ threshold Ϊ��ֵ
int CWi::WaveCrest(double *src,double *dst,int *pos,int datalen,int threshold)
{
	int i,count=0;
	int num =0;
	double temp1=0.0,temp2=0.0;
	double *diff = (double *)malloc(sizeof(double)*datalen);
 	DiffSample (src, diff, datalen);	//΢��
	for(i = 0;i<datalen-1;i++)
	{
		if(diff[i]*diff[i+1]<=0)
		{
			pos[count] = i;
			count++;
		}
	}
	for(i = 0;i<count;i++)
	{
		if((src[(pos[i]-threshold)>0?(pos[i]-threshold):0]-src[pos[i]])
			*(src[(pos[i]+threshold)<datalen?(pos[i]+threshold):datalen]-src[pos[i]])<0)
		{
			pos[i] = -1;
			continue;
		}
		dst[num] = src[pos[i]];
		num++;

	}

	return num;
}

/****************************************************************************/
/* ���ܣ���ת
/* ������posX��X��������
/*       posY��Y��������
/*       datalen�����еĳ���
/*       rotAngle�����еĳ���
/****************************************************************************/
void CWi::Rotation(double *posX, double *posY,int dataLen,double rotAngle)
{
	int i;
	double tempX,tempY;
	double cosa = cos(rotAngle);
	double sina = sin(rotAngle);
	for(i = 0; i<dataLen;i++)
	{
		tempX = posX[i]*cosa+posY[i]*sina;
		tempY = posY[i]*cosa-posX[i]*sina;
		posX[i] = tempX;
		posY[i] = tempY;
	}
}

/****************************************************************************/
/*���ܣ���ֵ�˲�
/*������data����������
/*      datalen�����鳤��
/****************************************************************************/
void CWi::MedianFilter(double *data,int dataLen)
{

	int i;
	double temp;
	for(i = 2; i<dataLen-2;i++)
	{
		temp = (data[i-2]+data[i-1]+data[i+1]+data[i+2])/4;
		if(ABS(data[i]-temp)>1.0)
			data[i]=temp;
	}
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::ProjectionFeature(CWi::Sample* s, int num)
{
	int i,j,fea,count = 0;
	double hor[IMAGEWIDTH],ver[IMAGEHEIGHT],total=0.0,piece=0.0;
	s->imgPixel[0][0]=0.0;
	for(i = 0;i<IMAGEWIDTH;i++)
	{
		hor[i] = 0.0;
	}
	for(i = 0;i<IMAGEHEIGHT;i++)
	{
		ver[i] = 0.0;
	}
	for(i = 0;i<IMAGEWIDTH;i++)
	{
		for(j = 0;j<IMAGEHEIGHT;j++)
		{
			hor[i]+=(255.0-s->imgPixel[i][j]);
			ver[j]+=(255.0-s->imgPixel[i][j]);
			total+=(255.0-s->imgPixel[i][j]);
		}
	}
	total/=num;
	fea = 0;
	for(i = 0;i<IMAGEWIDTH;i++)
	{	
		count++;
		piece+=hor[i];
		if(piece>=total)
		{
			s->feature[fea]=count;
			fea++;
			count = 0;
			piece=0;
		}
	}
	if(piece<total)
		s->feature[fea]=count;
	fea++;
	count = 0;
	piece = 0;
	for(i = 0;i<IMAGEHEIGHT;i++)
	{	
		count++;
		piece+=ver[i];
		if(piece>=total)
		{
			s->feature[fea]=count;
			fea++;
			count = 0;
			piece = 0;
		}
	}
	if(piece<total)
		s->feature[fea]=count;

}

/****************************************************************************/
/*���ܣ����㷽��ֲ�
/*������angle�����淽�����Ľ��
/*      xLog��X��������
/*      yLog��Y��������
/*      datalen�����г���
/****************************************************************************/
void CWi::CalDirection(double *angle,double *xLoc,double *yLoc,int dataLen)
{	
	int i;
	double *diff0 = (double *)malloc(sizeof(double)*dataLen);
	double *diff1 = (double *)malloc(sizeof(double)*dataLen);
	DiffSample (xLoc, diff0, dataLen);	//΢��
	DiffSample (yLoc, diff1, dataLen);
	for(i = 0;i<dataLen;i++)
	{
		if(diff0[i] == 0)
		{
			if(diff1[i]>0)
				angle[i] = 90+90;
			if(diff1[i]<0)
				angle[i] = -90+90;
		}
		else
			angle[i] = 180*(atan(diff1[i]/diff0[i])/PI)+90;
	}
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::Direction(int sample)
{

	CWi::Sample *s0 =(CWi::Sample*)trainSampleArray.GetAt(sample);

	CalDirection(s0->direction,s0->xLoc2,s0->yLoc2,s0->effectDataNum);
}

/****************************************************************************/
/*���ܣ���ͨ�˲�
/*������data����������
/*      threshold����ֵ
/*      datalen�����鳤��
/****************************************************************************/
void CWi:: lowpassfilter(double *data,double threshold,unsigned long dataLen)
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

/****************************************************************************/
/*���ܣ�fft�㷨
/*������td������
/*	    fd�����
/*      r��ά��
/****************************************************************************/
void CWi::fft(complex *td, complex *fd, int r)
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

/****************************************************************************/
/*���ܣ���fft�任
/*������fd������
/*      td�����
/*      r��ά��
/****************************************************************************/
void CWi::ifft(complex *fd, complex *td, int r)
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

/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::OriginalDistance(int sample1,int sample2)
{
	//unsigned char Path[DTWRESULTNUM][DTWRESULTNUM];
	CWi::Sample *s0 =(CWi::Sample*)trainSampleArray.GetAt(sample1);
	CWi::Sample *s1 =(CWi::Sample*)trainSampleArray.GetAt(sample2);
	//SamplePress2(s0->pressTotal2,s0->pressTotal,s0->effectDataNum/4,4);
	//SamplePress2(s1->pressTotal2,s1->pressTotal,s1->effectDataNum/4,4);
	//double result = DTWDistanceCompute(s0->pressTotal,s0->effectDataNum/4,
	//									 s1->pressTotal,s1->effectDataNum/4);
	double result = DTWDistanceFun(s0->pressTotal2,s0->effectDataNum,
								s1->pressTotal2,s1->effectDataNum,100);
	return result;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::WaveCrestPosDistance(int sample1,int sample2)
{
	//unsigned char Path[DTWRESULTNUM][DTWRESULTNUM];
	
	int num0,num1;
	int pos[1000];
	double temp1[1000],temp2[1000];
	CWi::Sample *s0 =(CWi::Sample*)trainSampleArray.GetAt(sample1);
	CWi::Sample *s1 =(CWi::Sample*)trainSampleArray.GetAt(sample2);
 	num0 = WaveCrest(s0->pressTotal2,s0->pressTotal,pos,s0->effectDataNum,5);
	for(int i=0;i<num0-1;i++)
	{
		temp1[i] = pos[i+1]-pos[i];
	}
	num1 = WaveCrest(s1->pressTotal2,s1->pressTotal,pos,s1->effectDataNum,5);
	for(i=0;i<num1-1;i++)
	{
		temp2[i] = pos[i+1]-pos[i];
	}
	
	double result = DTWDistanceFun(temp1,num0-1,temp2,num1-1,100);
									 
	return result;

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::WaveCrestDistance(int sample1,int sample2)
{
	 
	int pos[500];
	int num0,num1;
 	CWi::Sample *s0 =(CWi::Sample*)trainSampleArray.GetAt(sample1);
	CWi::Sample *s1 =(CWi::Sample*)trainSampleArray.GetAt(sample2);
 	num0=WaveCrest(s0->pressTotal2,s0->pressTotal,pos,s0->effectDataNum,5);
	num1=WaveCrest(s1->pressTotal2,s1->pressTotal,pos,s1->effectDataNum,5);
 
	
	double result = DTWDistanceFun(s0->pressTotal,num0,s1->pressTotal,num1,100);
	return result;

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::XposDistance(int sample1,int sample2)
{
	CWi::Sample *s0 =(CWi::Sample*)trainSampleArray.GetAt(sample1);
	CWi::Sample *s1 =(CWi::Sample*)trainSampleArray.GetAt(sample2);
	double result = DTWDistanceFun(s0->xLoc2,s0->effectDataNum,
										 s1->xLoc2,s1->effectDataNum,100);
	return result;

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::YposDistance(int sample1,int sample2)
{
	CWi::Sample *s0 =(CWi::Sample*)trainSampleArray.GetAt(sample1);
	CWi::Sample *s1 =(CWi::Sample*)trainSampleArray.GetAt(sample2);
 	double result = DTWDistanceFun(s0->yLoc2,s0->effectDataNum,
										 s1->yLoc2,s1->effectDataNum,100);
	return result;

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::XYposDistance(int sample1,int sample2)
{

	CWi::Sample *s0 =(CWi::Sample*)trainSampleArray.GetAt(sample1);
	CWi::Sample *s1 =(CWi::Sample*)trainSampleArray.GetAt(sample2);

	double *diff0 = (double *)malloc(sizeof(double)*(s0->effectDataNum));
	double *diff1 = (double *)malloc(sizeof(double)*(s1->effectDataNum));
	double *dis0 = (double *)malloc(sizeof(double)*(s0->effectDataNum));
	double *dis1 = (double *)malloc(sizeof(double)*(s1->effectDataNum));
	
	DiffSample (s0->xLoc2, diff0, s0->effectDataNum);	//΢��
	DiffSample (s0->yLoc2, diff1, s0->effectDataNum);
	for(int i = 0;i<s0->effectDataNum;i++)
	{
		dis0[i] = SQUARE(diff0[i])+SQUARE(diff1[i]);
	}
	DiffSample (s1->xLoc2, diff0, s1->effectDataNum);	//΢��
	DiffSample (s1->yLoc2, diff1, s1->effectDataNum);

	for(i = 0;i<s1->effectDataNum;i++)
	{
		dis1[i] = SQUARE(diff0[i])+SQUARE(diff1[i]);
	}

	double result = DTWDistanceFun(dis0,s0->effectDataNum,dis1,s1->effectDataNum,100);

	return result;

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::GenTemplatePress()
{
	int num = trainSampleArray.GetSize();
	int retval;
	CWi::Sample *s0 = (CWi::Sample *)trainSampleArray.GetAt(0);
	CWi::Sample *s1 = (CWi::Sample *)trainSampleArray.GetAt(1);
	templen = DTWTemplate(s0->pressTotal2,s0->effectDataNum,s1->pressTotal2,s1->effectDataNum,dtwtemplate,1,20,&threshold);
	if(templen == -1)
	{
		return -1;
	}
	for(int i = 2 ;i<num;i++)
	{
		CWi::Sample *s = (CWi::Sample *)trainSampleArray.GetAt(i);
		retval = DTWTemplate(dtwtemplate,templen,s->pressTotal2,s->effectDataNum,dtwtemplate,i,20,&threshold);
		if(templen == -1)
		{	
			return -1;
		}
	}

	return retval;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

int  CWi::RecogTemplatePress(double *distance,int index)
{
	double retval;
	CWi::Sample *s = (CWi::Sample *)testSampleArray.GetAt(index);
	retval = DTWDistanceFun(dtwtemplate,templen,s->pressTotal2,s->effectDataNum,100);
	*distance = retval;
	if(retval >=threshold*1.0)
	{
		return -1;
	}
	else
	{
		return 1;
	}


}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::GenTemplateXpos()
{
	int num = trainSampleArray.GetSize();
	int retval;
	CWi::Sample *s0 = (CWi::Sample *)trainSampleArray.GetAt(0);
	CWi::Sample *s1 = (CWi::Sample *)trainSampleArray.GetAt(1);
	templenx = DTWTemplate(s0->xLoc2,s0->effectDataNum,s1->xLoc2,s1->effectDataNum,dtwtemplatex,1,20,&thresholdx);
	if(templenx == -1)
	{
		return -1;
	}
	for(int i = 2 ;i<num;i++)
	{
		CWi::Sample *s = (CWi::Sample *)trainSampleArray.GetAt(i);
		retval = DTWTemplate(dtwtemplatex,templenx,s->xLoc2,s->effectDataNum,dtwtemplatex,i,20,&thresholdx);
		if(templenx == -1)
		{	
			return -1;
		}
	}
	threshold = thresholdx;
	return retval;
}

/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
int  CWi::RecogTemplateXpos(double *distance,int index)
{
	double retval;
	CWi::Sample *s = (CWi::Sample *)testSampleArray.GetAt(index);
	retval = DTWDistanceFun(dtwtemplate,templen,s->xLoc2,s->effectDataNum,100);
	*distance = retval;
	if(retval >=threshold*1.0)
	{
		return -1;
	}
	else
	{
		return 1;
	}


}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::GenTemplateYpos()
{
	int num = trainSampleArray.GetSize();
	int retval;
	CWi::Sample *s0 = (CWi::Sample *)trainSampleArray.GetAt(0);
	CWi::Sample *s1 = (CWi::Sample *)trainSampleArray.GetAt(1);
	templeny = DTWTemplate(s0->yLoc2,s0->effectDataNum,s1->yLoc2,s1->effectDataNum,dtwtemplatey,1,20,&thresholdy);
	if(templeny == -1)
	{
		return -1;
	}
	for(int i = 2 ;i<num;i++)
	{
		CWi::Sample *s = (CWi::Sample *)trainSampleArray.GetAt(i);
		retval = DTWTemplate(dtwtemplatey,templeny,s->yLoc2,s->effectDataNum,dtwtemplatey,i,20,&thresholdy);
		if(templeny == -1)
		{	
			return -1;
		}
	}
	
	threshold = thresholdy;
	return retval;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

double CWi::GenTemplateVector()
{
	int num = trainSampleArray.GetSize();
	int retval;
	CWi::Sample *s0 = (CWi::Sample *)trainSampleArray.GetAt(0);
	CWi::Sample *s1 = (CWi::Sample *)trainSampleArray.GetAt(1);
	templenvec = VDTWTemplate(s0->dataVec,s0->effectDataNum,s1->dataVec,s1->effectDataNum,dtwtemplatev,1,50,&thresholdvec);
	if(templen == -1)
	{
		return -1;
	}
	for(int i = 2 ;i<num;i++)
	{
		CWi::Sample *s = (CWi::Sample *)trainSampleArray.GetAt(i);
		retval = VDTWTemplate(dtwtemplatev,templenvec,s->dataVec,s->effectDataNum,dtwtemplatev,i,50,&thresholdvec);
		if(templen == -1)
		{	
			return -1;
		}
	}
	
	threshold = thresholdvec;
	return retval;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

int  CWi::RecogTemplateVec(double *distance,int index)
{
	double retval;
	CWi::Sample *s = (CWi::Sample *)testSampleArray.GetAt(index);
	retval = VDTWDistanceFun(dtwtemplatev,templenvec,s->dataVec,s->effectDataNum,100);
	*distance = retval;
	if(retval >= thresholdvec*1.05)
	{
		return -1;
	}
	else
	{
		return 1;
	}

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/


int  CWi::RecogTemplateYpos(double *distance,int index)
{
	double retval;
	CWi::Sample *s = (CWi::Sample *)testSampleArray.GetAt(index);
	retval = DTWDistanceFun(dtwtemplate,templen,s->yLoc2,s->effectDataNum,100);
	*distance = retval;
	if(retval >=threshold*1.0)
	{
		return -1;
	}
	else
	{
		return 1;
	}

}

/****************************************************************************/
/*���ܣ��ܺ�����X��Y��������ģ��
/****************************************************************************/
double CWi::GenTemplateXY()
{
	int num = trainSampleArray.GetSize();
	int retval;
	CWi::Sample *s0 = (CWi::Sample *)trainSampleArray.GetAt(0);
	CWi::Sample *s1 = (CWi::Sample *)trainSampleArray.GetAt(1);
	templeny = DTWTemplate(s0->yLoc2,s0->effectDataNum,s1->yLoc2,s1->effectDataNum,dtwtemplatey,1,20,&thresholdy);
	if(templeny == -1)
	{
		return -1;
	}
	for(int i = 2 ;i<num;i++)
	{
		CWi::Sample *s = (CWi::Sample *)trainSampleArray.GetAt(i);
		retval = DTWTemplate(dtwtemplatey,templeny,s->yLoc2,s->effectDataNum,dtwtemplatey,i,20,&thresholdy);
		if(templeny== -1)
		{	
			return -1;
		}
	}
	templenx = DTWTemplate(s0->xLoc2,s0->effectDataNum,s1->xLoc2,s1->effectDataNum,dtwtemplatex,1,20,&thresholdx);
	if(templenx == -1)
	{
		return -1;
	}
	for(i = 2 ;i<num;i++)
	{
		CWi::Sample *s = (CWi::Sample *)trainSampleArray.GetAt(i);
		retval = DTWTemplate(dtwtemplatex,templenx,s->xLoc2,s->effectDataNum,dtwtemplatex,i,20,&thresholdx);
		if(templenx == -1)
		{	
			return -1;
		}
	}
	thresholdxy = SQUARE(thresholdx)+SQUARE(thresholdy);
	templenxy = templeny;
	threshold = thresholdxy;
	return retval;
}

/****************************************************************************/
/*���ܣ��ۺ�����X�����Y�������ʶ��
/*������distance������ʶ�������ģ��ľ���
/*      index����ʶ��Ķ����ڲ��Լ��ֵ��±�
/*����ֵ��1 ���� ��1 �ܾ�
/****************************************************************************/
int CWi::RecogTemplateXY(double *distance,int index)
{
	double disx,disy;
	double retval;
	CWi::Sample *s = (CWi::Sample *)testSampleArray.GetAt(index);
	disx = DTWDistanceFun(dtwtemplatex,templenx,s->xLoc2,s->effectDataNum,100);
	disy = DTWDistanceFun(dtwtemplatey,templeny,s->yLoc2,s->effectDataNum,100);
	retval = SQUARE(disx)+SQUARE(disy);
	*distance = retval;
	if(retval>=threshold*1.0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
int CWi::RecogMovement(double *distance,int index)
{
	FEAGURE_MV fm;
	double retval;
	CWi::Sample *s = (CWi::Sample *)testSampleArray.GetAt(index);
	compute_feagure_ex(s->xLoc,s->yLoc,s->pressTotal,s->effectDataNum,&fm);
	retval = feagure_distance(&feat,&fm);
	*distance = retval;
	if(retval>=thresholdfeat*1.3)
	{
		return -1;
	}
	else
	{
		return 1;
	}

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

int	CWi::RegDih(double *distance,int index)
{
	DIHFQ fq;
	double retval;
	CWi::Sample *s = (CWi::Sample *)testSampleArray.GetAt(index);
	int *dir = (int *)malloc(sizeof(int)*s->effectDataNum);
	dih_compute_direction(s->xLoc2,s->yLoc2,dir,s->effectDataNum);
    //dih_compute_frequency_dist(dir,s->xLoc2,s->yLoc2,s->effectDataNum,&fq);
    //dih_compute_frequency_pressure(dir,s->pressTotal2,s->effectDataNum,&fq);
    dih_compute_frequency_dp(dir,s->pressTotal2,s->xLoc2,s->yLoc2,s->effectDataNum,&fq);
	//dih_compute_frequency(dir,s->effectDataNum,&fq);
	retval = dih_dist_compute(&freq,&fq);
	*distance = retval;
	if(retval>=thresholdfreq*1.3)
	{
		return -1;
	}
	else
	{
		return 1;
	}

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::OnDirection() 
{
	int num = trainSetDataFilePath.GetSize();
	DIHFQ *fq = (DIHFQ *)malloc(sizeof(DIHFQ)*num);
	double total = 0.0;
	DIHFQ frequence;
	frequence.f0 = 0.0;
	frequence.f1 = 0.0;
	frequence.f2 = 0.0;
	frequence.f3 = 0.0;

	for(int i = 0;i<num;i++)
	{
		CWi::Sample *s = (CWi::Sample *)trainSampleArray.GetAt(i);
		int *dir = (int *)malloc(sizeof(int)*s->effectDataNum);
		dih_compute_direction(s->xLoc2,s->yLoc2,dir,s->effectDataNum);
        //dih_compute_frequency_dist(dir,s->xLoc2,s->yLoc2,s->effectDataNum,&fq[i]);
        //dih_compute_frequency_pressure(dir,s->pressTotal2,s->effectDataNum,&fq[i]);
        dih_compute_frequency_dp(dir,s->pressTotal2,s->xLoc2,s->yLoc2,s->effectDataNum,&fq[i]);
		//dih_compute_frequency(dir,s->effectDataNum,&fq[i]);

		frequence.f0+=fq[i].f0;
		frequence.f1+=fq[i].f1;
		frequence.f2+=fq[i].f2;
		frequence.f3+=fq[i].f3;

	}

	frequence.f0/=num;
	frequence.f1/=num;
	frequence.f2/=num;
	frequence.f3/=num;
	for(i = 0;i<num;i++)
	{
		total+=dih_dist_compute(&freq,&fq[i]);
	}
	total/=num;
	freq = frequence;
	thresholdfreq = total;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::OnMovement() 
{
	int num = trainSetDataFilePath.GetSize();
	PFEAGURE_MV fm = (PFEAGURE_MV)malloc(sizeof(FEAGURE_MV)*num);
	double total = 0.0;
	FEAGURE_MV feature;

	feature.f1 = 0.0;
	feature.f2 = 0.0;
	feature.f3 = 0.0;
	feature.f4 = 0.0;
	feature.f5 = 0.0;
	feature.f6 = 0.0;
	feature.f7 = 0.0;
	feature.f8 = 0.0;

	for(int i = 0;i<num;i++)
	{
		CWi::Sample *s = (CWi::Sample *)trainSampleArray.GetAt(i);
		compute_feagure_ex(s->xLoc,s->yLoc,s->pressTotal,s->effectDataNum,&fm[i]);

		feature.f1+=fm[i].f1;
		feature.f2+=fm[i].f2;
		feature.f3+=fm[i].f3;
		feature.f4+=fm[i].f4;
		feature.f5+=fm[i].f5;
		feature.f6+=fm[i].f6;
		feature.f7+=fm[i].f7;
		feature.f8+=fm[i].f8;

	}

	feature.f1/=num;
	feature.f2/=num;
	feature.f3/=num;
	feature.f4/=num;
	feature.f5/=num;
	feature.f6/=num;
	feature.f7/=num;
	feature.f8/=num;
	for(i = 0;i<num;i++)
	{
		total += feagure_distance(&feature,&fm[i]);
	}
	total/=num;
	feat = feature;
	thresholdfeat = total;
}

/****************************************************************************/
/* ���ܣ�������ѹ��Ϊ����ʱ��ģ��
/* ������FileName��ģ���ļ���
/****************************************************************************/
void CWi::SaveTemplatePress(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"ab+");
	head.length = templen;
	head.threshold = threshold;
	head.method = METHOD_PRES;
	fwrite(&head,sizeof(head),1,fp);
	fwrite(dtwtemplate,sizeof(double),templen,fp);
	fclose(fp);
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::SaveTemplateXpos(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"ab+");
	head.length = templenx;
	head.threshold = thresholdx;
	head.method = METHOD_X;
	fwrite(&head,sizeof(head),1,fp);
	fwrite(dtwtemplatex,sizeof(double),templenx,fp);
	fclose(fp);
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::SaveTemplateYpos(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"ab+");
	head.length = templeny;
	head.threshold = thresholdy;
	head.method = METHOD_Y;
	fwrite(&head,sizeof(head),1,fp);
	fwrite(dtwtemplatey,sizeof(double),templeny,fp);
	fclose(fp);
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::SaveTemplateXY(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"ab+");
	head.length = templenxy;
	head.threshold = thresholdxy;
	head.method = METHOD_XY;
	fwrite(&head,sizeof(head),1,fp);
	fwrite(dtwtemplatex,sizeof(double),templenx,fp);
	fwrite(dtwtemplatey,sizeof(double),templeny,fp);
	fclose(fp);
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::SaveMovement(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"ab+");
	head.length = 0;
	head.threshold = thresholdfeat;
	head.method = METHOD_MOVE;
	fwrite(&head,sizeof(head),1,fp);
	fwrite(&feat,sizeof(FEAGURE_MV),1,fp);
	fclose(fp);
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/

void CWi::SaveDih(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"ab+");
	head.length = 0;
	head.threshold = thresholdfreq;
	head.method = METHOD_DIH;
	fwrite(&head,sizeof(head),1,fp);
	fwrite(&freq,sizeof(DIHFQ),1,fp);
	fclose(fp);

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
void CWi::SaveTemplateVec(char * FileName)
{

	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"ab+");
	head.length = templenvec;
	head.threshold = thresholdvec;
	head.method = METHOD_VEC;
	fwrite(&head,sizeof(head),1,fp);
	fwrite(dtwtemplatev,sizeof(mvector),templenvec,fp);
 	fclose(fp);
}
/****************************************************************************/
/*���ܣ�������HMMģ��ʱ��ģ��
/*������FileName��ģ���ļ���
/****************************************************************************/
void CWi::SaveHMM(char * FileName)
{
	FILE *fp;
	fp = fopen(FileName,"ab+");
	PrintHMM(fp, &hmm);
	fclose(fp);
}

/****************************************************************************/
/*���ܣ�װ����ѹ��Ϊ������ģ��
/*������FileName���ļ���
/****************************************************************************/
int CWi::LoadTemplatePress(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"rb");
	fread(&head,sizeof(head),1,fp);
	if(head.method != METHOD_PRES)
	{
		fclose(fp);
		return -1;
	}
	fread(dtwtemplate,sizeof(double),templen,fp);
	templen = head.length;
	threshold = head.threshold;
	fclose(fp);
	return 0;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
int CWi::LoadTemplateXpos(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"rb");
	fread(&head,sizeof(head),1,fp);
	if(head.method != METHOD_X)
	{
		fclose(fp);
		return -1;
	}
	fread(dtwtemplatex,sizeof(double),templenx,fp);
	templenx = head.length;
	threshold = thresholdx = head.threshold;
	fclose(fp);
	return 0;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
int CWi::LoadTemplateYpos(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"rb");
	fread(&head,sizeof(head),1,fp);
	if(head.method != METHOD_Y)
	{
		fclose(fp);
		return -1;
	}
	fread(dtwtemplatey,sizeof(double),templeny,fp);
	templeny = head.length;
	threshold = thresholdy = head.threshold;
	fclose(fp);
	return 0;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
int CWi::LoadTemplateXY(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"rb");
	fread(&head,sizeof(head),1,fp);
	if(head.method != METHOD_XY)
	{
		fclose(fp);
		return -1;
	}
	fread(dtwtemplatex,sizeof(double),templenx,fp);
	fread(dtwtemplatey,sizeof(double),templeny,fp);
	templenxy = head.length;
	thresholdxy = head.threshold;
	fclose(fp);
	return 0;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
int CWi::LoadMovement(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"rb");
	fread(&head,sizeof(head),1,fp);
	if(head.method != METHOD_MOVE)
	{
		fclose(fp);
		return -1;
	}
	fread(&feat,sizeof(FEAGURE_MV),1,fp);
	thresholdfeat = head.threshold;
	fclose(fp);
	return 0;
}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
int CWi::LoadDih(char * FileName)
{
	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"rb");
	fread(&head,sizeof(head),1,fp);
	if(head.method != METHOD_DIH)
	{
		fclose(fp);
		return -1;
	}
	fread(&freq,sizeof(DIHFQ),1,fp);
	thresholdfreq = head.threshold;
	fclose(fp);
	return 0;

}
/****************************************************************************/
/*
/*	
/*  
/****************************************************************************/
int CWi::LoadTemplateVec(char * FileName)
{

	TempHeader head;
	FILE *fp;
	fp = fopen(FileName,"rb");
	fread(&head,sizeof(head),1,fp);
	if(head.method != METHOD_VEC)
	{
		fclose(fp);
		return -1;
	}
	fread(dtwtemplatev,sizeof(mvector),templenvec,fp);
	templenvec = head.length;
	thresholdvec = head.threshold;
	fclose(fp);
	return 0;
}

/****************************************************************************/
/*���ܣ�װ������HMMģ��ʱ��ģ���ļ�
/*������FileName��ģ���ļ���
/****************************************************************************/
int CWi::LoadHMM(char * FileName)
{
	FILE *fp;
	fp = fopen(FileName,"rb");
	ReadHMM(fp, &hmm);
	fclose(fp);
	return 0;
}

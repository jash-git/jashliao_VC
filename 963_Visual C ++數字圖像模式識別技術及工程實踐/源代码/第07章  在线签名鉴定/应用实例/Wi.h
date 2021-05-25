// Wi.h: interface for the CWi class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WI_H__4C7EAE8A_D523_47A7_BDB0_1FD3D8756BCB__INCLUDED_)
#define AFX_WI_H__4C7EAE8A_D523_47A7_BDB0_1FD3D8756BCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "movement.h"
#include "dih.h"
#include "dtwrecoge.h"
#include "vdtwrecoge.h"
#include "Clustering.h"
#include "hmm.h"
#include "nrutils.h"


#define MAXTRAINSETNUM		1000	//���ѵ��������
#define MAXTESTSETNUM		200		//������������
#define CLASSNUM			2		//������
#define RAWDATADIM			2000	//ԭʼ����ά��
#define TAPEDDATADIM		1024
#define FEADIM				20		//�������ά��
#define TRAINSETFLAG		0		//ѵ��������־
#define TESTSETFLAG			1		//����������־

#ifndef MYRECOGE_H
#define MYRECOGE_H
#define DTWRESULTNUM	300	/*���嶯̬ʱ�������������ĳ���*/
#endif

#define MAXTOTALPRESSURE 255
#define IMAGEHEIGHT	128
#define IMAGEWIDTH	256

#define STRUCTSAMPLELEN sizeof(struct CWi::Sample)

#define PI    3.14159265358979323846
#define ZERO 1.0
#define THRESHOLD 5.0  //��ֵ
#define SQUARE(x) x*x

#define VQ_M 16


#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct tagPenPoint{
	int		x;  //X����
	int		y;  //Y����
	int		pressure;  //ѹ��
	DWORD	time;  //ʱ��
}PenPoint; //�����ļ��е�Ľṹ

typedef struct {
	int		length;
	int		method;		
	double	threshold;
}TempHeader; //ʶ�𷽷����ļ�ͷ�ṹ

//������һЩ�꣬��ʾ�����õķ���
#define METHOD_PRES 0
#define METHOD_X	1
#define METHOD_Y	2
#define METHOD_XY   3
#define METHOD_MOVE 4
#define METHOD_DIH  5
#define METHOD_VEC  6
#define METHOD_HMM  7

typedef struct {
	double r, i;
} complex; //�����ṹ


class CWi : public CObject  
{
public:
	CWi();
	virtual ~CWi();

public:
	struct Sample
	{
		double pressTotal[RAWDATADIM]; //�ܵ�ѹ��
		double pressTotal2[RAWDATADIM];
		double xLoc[RAWDATADIM];			//��ʱ��˳�������
		double yLoc[RAWDATADIM];			//��ʱ��˳�������
 		double xLoc2[RAWDATADIM];
		double yLoc2[RAWDATADIM];
		double pressA[RAWDATADIM];		//A��ѹ������
		double pressB[RAWDATADIM];		//B��ѹ������
		double pressC[RAWDATADIM];		//C��ѹ������
		double press[TAPEDDATADIM];		//�������ѹ������
		double direction[RAWDATADIM];  //����
		double imgPixel[IMAGEWIDTH][IMAGEHEIGHT];

		double speed[RAWDATADIM]; //�ٶ�
		PenPoint point[RAWDATADIM]; //��
		mvector  dataVec[RAWDATADIM];
		struct   VQ_VECTOR  vq_vector[RAWDATADIM];
		int	   vq_feature[RAWDATADIM];

		int    effectDataNum;
		double width;
		double height;
		double maxPressTotal;
		//PenPoint point[RAWDATADIM];
		
		double feature[FEADIM];		//��������		
		int    trueClass;	//��ʵ���
		int    classifiedClass[CLASSNUM]; //��ʶ��ķ��࣬��Ӧλ��1
		int    isClassified; // 1 for true and -1 for false
	};

	CStringArray trainSetDataFilePath;	//ѵ�����������ļ�·��
	CStringArray testSetDataFilePath;	//�������������ļ�·��

	CPtrArray trainSampleArray;			//struct Sample ��Ԫ��
	CPtrArray testSampleArray;			//struct Sample ��Ԫ��
	double dtwtemplate[RAWDATADIM];
	double dtwtemplatex[RAWDATADIM];
	double dtwtemplatey[RAWDATADIM];

	mvector dtwtemplatev[RAWDATADIM];
	int		templenvec;
	double thresholdvec;

	struct   VQ_VECTOR  vq_vector[RAWDATADIM];
	int	   vq_feature[RAWDATADIM];

	double threshold;
	double thresholdx;
	double thresholdy;
	double thresholdxy;
	double thresholdhmm;
	int	   templenx;
	int    templeny;
	int	   templenxy;
	int    templen;
	FEAGURE_MV feat;
	DIHFQ  freq;
	double thresholdfeat;
	double thresholdfreq;

	struct VQ_CENTER	vq_center[VQ_M];
	HMM	   hmm;
	
// Operations
public:
	void   AddSampleSetPath (CString strPath, int flag); //0 for trainset, 1 for testset
	void   DelSampleSetPath (int flag); //0 for trainset, 1 for testset
	
	void   ParseDataFromFile1 (CWi::Sample *s, CString filePath); //��Բ�ͬ�ĸ�ʽ��ȡ�ļ�
	void   ParseDataFromFile2 (CWi::Sample *s, CString filePath);
	void   ParseDataFromFile3 (CWi::Sample *s, CString filePath);
	void   RetrieveSample (CStringArray* samplePathArrayRef, 
							 CPtrArray* sampleArrayRef);
	void   ConstructTotal (CWi::Sample* s);//������ѹ������
	void   NormalizeSample (double* data, int dataLen);//��һ��
	void   NormalizeSample (double *data, double& max, double& min, 
					int dataLen); //��һ���㷨
	void   NormalizeImage (CWi::Sample* s); //��һ��ͼ��
	void   FTSample (double* dataSource, double* dataDest);
	void   DiffSample (double* dataSource, double* dataDest, int dataLen);

	void   FilterNoise (CWi::Sample* s, int critical);//ȥ��
	void   ProjectionFeature(CWi::Sample* s, int num);
	void   ConstructImage (CPtrArray* sampleArrayRef);
	void   PreProcSample (CPtrArray* sampleArrayRef, int flag);
	void   SamplePress1(double *src,double *dst,int datalen,int inter);
	void   SamplePress2(double *src,double *dst,int datalen,int inter);
	void   Rotation(double *posX, double *posY,int dataLen,double rotAngle);//��תͼ��
	void   MedianFilter(double *data,int dataLen); //��ֵ�˲�
 	
    void   lowpassfilter(double *data,double threshold,unsigned long dataLen);//��ͨ�˲�
	void   fft(complex *td, complex *fd, int r);//fft�㷨
    void   ifft(complex *fd, complex *td, int r); //��fft�㷨

	double CalculateAverage(double *data,int dataLen);//����ƽ��ֵ
	void   AverageNormalize(double *data,int dataLen,double value);//��ֵ��һ��
	int    WaveCrest(double *src,double *dst,int *pos,int datalen,int threshold);
	//һЩ�����ĺ���
	double OriginalDistance(int sample1,int sample2);
	double WaveCrestPosDistance(int sample1,int sample2);
	double WaveCrestDistance(int sample1,int sample2);
	double XposDistance(int sample1,int sample2);
	double YposDistance(int sample1,int sample2);
	double XYposDistance(int sample1,int sample2);
	void   CalDirection(double *angle,double *xLoc,double *yLoc,int dataLen);
	void   Direction(int sample);
	//һЩ����ģ��ĺ���
	double GenTemplatePress();
	int    RecogTemplatePress(double *distance,int index);
	double GenTemplateXpos();
	int    RecogTemplateXpos(double *distance,int index);
	double GenTemplateYpos();
	int    RecogTemplateYpos(double *distance,int index);
	double GenTemplateXY();
	int    RecogTemplateXY(double *distance,int index);
	int    RecogMovement(double *distance,int index);
	int	   RegDih(double *distance,int index);
	void   GenVector(CPtrArray* sampleArrayRef);
	double GenTemplateVector();
	int    RecogTemplateVec(double *distance,int index);
	void   SpeedCurve(CWi::Sample* s);
	void   GenVQVector(CPtrArray* sampleArrayRef);
	void   VQCluster();
	void   GenVQTemplate();
	void   GenHMM();
	int    RecogHMM(double *distance, int index);
	void   GenVQVector();

	//һЩ���ຯ��
	void   VQClassify(CWi::Sample *s);
	int	   VQClassify(struct VQ_VECTOR *vq, struct VQ_CENTER *vc);
	void   OnDirection();
	void   OnMovement();
	
	//������ָ�ʽ��ģ��
	void   SaveTemplatePress(char * FileName);
	void   SaveTemplateXpos(char * FileName);
	void   SaveTemplateYpos(char * FileName);
	void   SaveTemplateXY(char * FileName);
	void   SaveMovement(char * FileName);
	void   SaveDih(char * FileName);
	void   SaveTemplateVec(char * FileName);
	void   SaveHMM(char * FileName);

	//װ�ظ��ָ�ʽ��ģ��
	int   LoadTemplatePress(char * FileName);
	int   LoadTemplateXpos(char * FileName);
	int   LoadTemplateYpos(char * FileName);
	int   LoadTemplateXY(char * FileName);
	int   LoadMovement(char * FileName);
	int   LoadDih(char * FileName);
	int   LoadTemplateVec(char * FileName);
	int   LoadHMM(char * FileName);
	double PoHMM(CWi::Sample *s);
};

#endif // !defined(AFX_WI_H__4C7EAE8A_D523_47A7_BDB0_1FD3D8756BCB__INCLUDED_)

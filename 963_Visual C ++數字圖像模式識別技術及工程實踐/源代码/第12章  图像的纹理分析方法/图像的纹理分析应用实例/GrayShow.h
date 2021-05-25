//////////////////////////////////////////////////////////////////////
// GrayShow.h: interface for the CGrayShow class.
// ����������Ҷȹ��־����㷨ʵ��
// 
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAYSHOW_H_INCLUDED_)
#define AFX_GRAYSHOW_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Dib.h"

class CGrayShow  
{
public:
	void ComputeMatrix(BYTE** LocalImage, int LocalImageWidth);
	void ComputeFeature(double& FeatureEnergy, double& FeatureEntropy, double& FeatureInertiaQuadrature, double& FeatureCorrelation, double& FeatureLocalCalm, int** pMatrix, int dim);
	//����
	double FeatureLocalCalmRD;	//�ֲ�ƽ���ԣ�45�ȷ���
	double FeatureLocalCalmLD;	//�ֲ�ƽ���ԣ�135�ȷ���
	double FeatureLocalCalmV;	//�ֲ�ƽ���ԣ�90�ȷ���ȷ���
	double FeatureLocalCalmH;	//�ֲ�ƽ���ԣ�0�ȷ���
	double FeatureCorrelationRD;	//����ԣ�45�ȷ���
	double FeatureCorrelationLD;	//����ԣ�135�ȷ���
	double FeatureCorrelationV;		//����ԣ�90�ȷ���
	double FeatureCorrelationH;		//����ԣ�0�ȷ���
	double FeatureInertiaQuadratureRD;	//���Ծأ�45�ȷ���
	double FeatureInertiaQuadratureLD;	//���Ծأ�135�ȷ���
	double FeatureInertiaQuadratureV;	//���Ծأ�90�ȷ���
	double FeatureInertiaQuadratureH;	//���Ծأ�0�ȷ���
	double FeatureEntropyRD;	//�أ�45�ȷ���
	double FeatureEntropyLD;	//�أ�135�ȷ���
	double FeatureEntropyV;		//�أ�90�ȷ���
	double FeatureEntropyH;		//�أ�0�ȷ���
	double FeatureEnergyRD;		//������45�ȷ���
	double FeatureEnergyLD;		//������135�ȷ���
	double FeatureEnergyV;		//������90�ȷ���
	double FeatureEnergyH;		//������0�ȷ���
	int FilterWindowWidth;	//���������Ĵ�С��ͨ����ͼ�񻮷ֳ����ɸ���������
	long ImageHeight;	//ԭͼ��ĸ߶�
	long ImageWidth;		//ԭͼ��Ŀ��
	int distance;	//���룬���ݲ�ͬ��Ӧ��ѡȡ	
	int GrayLayerNum;	//�Ҷȷּ�
	int** PMatrixRD;	//45�ȷ����ϵĻҶȹ��־���
	int** PMatrixLD;	//135�ȷ����ϵĻҶȹ��־���
	int** PMatrixV;		//90�ȷ����ϵĻҶȹ��־���
	int** PMatrixH;		//0�ȷ����ϵĻҶȹ��־���
	BYTE** ImageArray;	//ԭʼ��ͼ���������飭�Ҷ�

	RGBQUAD** m_tOriPixelArray;//ԭʼλͼ����
	RGBQUAD** m_tResPixelArray;//�ο�λͼ����

	CDib *m_dib;

	//����
	void LoadImage(CString &FilePathName);
	CGrayShow();
	virtual ~CGrayShow();

};

#endif // !defined(AFX_GRAYSHOW_H_INCLUDED_)

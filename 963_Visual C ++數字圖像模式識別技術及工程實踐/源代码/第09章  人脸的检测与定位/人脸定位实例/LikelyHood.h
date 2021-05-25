//////////////////////////////////////////////////////////////////////
// LikelyHood.h: ��CLikelyHood�Ľӿ�
//////////////////////////////////////////////////////////////////////

#ifndef __LIKELYHOOD_H
#define __LIKELYHOOD_H

#include <math.h>
#include "Dib.h"

#define 	B_Mean  117.4361;
#define 	R_Mean  156.5599;
#define 	Brcov00 160.1301;
#define 	Brcov01 12.1430 ;
#define 	Brcov10 12.1430 ;
#define 	Brcov11 299.4574;

typedef struct TCbCr
{
	double Cb;
	double Cr;
}CbCr;

class CLikelyHood : public CObject  
{
public:
	CLikelyHood();
	CLikelyHood(RGBQUAD **source,int width,int height);
	virtual ~CLikelyHood();
public:
	void CalLikeHood();
	bool CalBinary();
	void filter(double** source,int m_nWidth,int m_nHeight);
	int  CalParameter(CString DirectPath);
	TCbCr CalCbCr(int R,int G,int B);
public:
	double bmean;
	double rmean;
	double brcov[2][2];

	int	m_nWidth;	//ͼ����
	int m_nHeight;	//ͼ��߶�
	RGBQUAD **m_pSourceData;	//ԭʼ����
	double  **m_pLikeliHoodArray;	//���ƶ����飨��ά��
	BYTE    **m_pBinaryArray;	//��ֵ�����飨��ά��

	bool m_bBinaryReady;	//��־λ���ж��Ƿ���ɶ�ֵ��
private:
	bool m_bLikeliHoodReady;	//��־λ���ж��Ƿ��������ƶ�
};

#endif // #ifndef __LIKELYHOOD_H

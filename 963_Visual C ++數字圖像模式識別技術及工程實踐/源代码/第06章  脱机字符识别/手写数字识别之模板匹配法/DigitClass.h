// DigitClass.h: interface for the CDigitClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIGITCLASS_H__84110994_734D_4BC7_A51F_79A9EAA15792__INCLUDED_)
#define AFX_DIGITCLASS_H__84110994_734D_4BC7_A51F_79A9EAA15792__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Dib.h"

#define DigitMaxWidth 40
#define DigitMaxHeight 60
#define DigitSize 2400	//2400=40*60

struct sample
{
	double feature[13];//��������������
	int trueClass;//������������ʵ���0��9��
	int classfied;//ʶ��Ľ����0��9��
};

typedef struct sample Sample;

class CDigitClass  
{
public:
	//���캯������������
	CDigitClass();
	virtual ~CDigitClass();
	//����
	CDib digitdib;//��Ӧ�����ֵ�λͼ
	BYTE digitarray[DigitMaxHeight][DigitMaxWidth];
	BYTE digitarray1[DigitSize];
	int digitWidth; //����ͼ��Ŀ��
	int digitHeight; //����ͼ��ĸ߶�
	double feature[13];
	//����
	void CopyArToBitmap(void);
	void CopyBitmapToAr(void);
	void BinaryDigit(BYTE thre);
	//�����ֲ�ͬ�ķ���ϸ��
	void ThinDigit_1();
	void ThinDigit_2();
	void ThinDigit_3();
	void ThinDigit_4();
	void GetFeature();
	//��ȡ��������
};

#endif // !defined(AFX_DIGITCLASS_H__84110994_734D_4BC7_A51F_79A9EAA15792__INCLUDED_)

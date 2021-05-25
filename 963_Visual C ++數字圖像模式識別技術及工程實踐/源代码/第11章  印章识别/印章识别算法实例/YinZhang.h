// YinZhang.h
// ӡ��ͼ�����һЩ�ӿ�
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_YINZHANG_H_INCLUDED_)
#define AFX_YINZHANG_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CYinZhang  
{
public:
	void FeatureExtract();
	void EroseBackground(RGBQUAD& refer);
	BYTE** ImageArray;	//ͼ�����飨�ҶȻ�����ֵ����
	void LoadImage(CString &FilePathName);//װ��ͼ��
	RGBQUAD** m_tResPixelArray;	//�仯��ͼ�����ݣ�RGB��ʽ��
	RGBQUAD** m_tOriPixelArray;	//ԭʼͼ�����ݣ�RGB��ʽ��
	double GlobalMass;		//��������
	double GlobalCentroidX;	//��������
	double GlobalCentroidY;
	double PrintMass;		//ӡ������
	double PrintCentroidX;	//ӡ������
	double PrintCentroidY;
	double CentroidDistance;	//���ľ�
	long ImageWidth;	//ͼ����
	long ImageHeight;	//ͼ��߶�
	CYinZhang();
	virtual ~CYinZhang();

};

#endif // !defined(AFX_YINZHANG_H_INCLUDED_)

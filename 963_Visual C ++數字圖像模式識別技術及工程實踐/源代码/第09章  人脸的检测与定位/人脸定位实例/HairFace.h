//////////////////////////////////////////////////////////////////////
// HairFace.h: ��CHairFace�ӿ�
//////////////////////////////////////////////////////////////////////

#ifndef __HAIRFACE_H
#define __HAIRFACE_H

class CHairFace : public CObject  
{
public:
	RGBQUAD ** m_pSourceData;	//ԭʼͼ������
	int	  m_nWidth;	//���
	int   m_nHeight;	//�߶�
	BYTE  **m_pBinaryArray;	//��ֵ������
	bool  m_bBinaryOK;	//��־λ���Ƿ���ɶ�ֵ��
public:
	void MarkHairFace();
	CHairFace(RGBQUAD ** source,int width,int height);
	virtual ~CHairFace();

};

#endif // #ifndef __HAIRFACE_H

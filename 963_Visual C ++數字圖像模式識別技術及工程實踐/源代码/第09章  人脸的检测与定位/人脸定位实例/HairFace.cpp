//////////////////////////////////////////////////////////////////////
// HairFace.cpp: ��CHairFace�ӿ�
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FaceDetect.h"
#include "HairFace.h"

//////////////////////////////////////////////////////////////////////
// ���캯��/��������
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// ���캯��
// ������  source��ԭʼ����
//         width��ͼ����
//         height��ͼ��߶�
//////////////////////////////////////////////////////////////////////
CHairFace::CHairFace(RGBQUAD ** source,int width,int height)
{
	m_nWidth = width;
	m_nHeight= height;

	m_bBinaryOK = false;

	m_pSourceData = source;

	m_pBinaryArray = new  BYTE*[height];
	for(int i=0;i <height; i++)
		m_pBinaryArray[i] = new BYTE[width];
}

//////////////////////////////////////////////////////////////////////
// ��������
//////////////////////////////////////////////////////////////////////
CHairFace::~CHairFace()
{
	if(m_pBinaryArray!=NULL)
	{
		for(int i=0;i<m_nHeight;i++)
			if(m_pBinaryArray[i]!=NULL) delete m_pBinaryArray[i];
		delete m_pBinaryArray;
	}
}

//////////////////////////////////////////////////////////////////////
// �������ͷ����λ��
//////////////////////////////////////////////////////////////////////
void CHairFace::MarkHairFace()
{
	int i,j;
	for(i=0;i<m_nHeight;i++)
	for(j=0;j<m_nWidth ;j++)
	{
		double r,g,Y,temp;
		temp = m_pSourceData[i][j].rgbGreen
			+m_pSourceData[i][j].rgbRed
			+m_pSourceData[i][j].rgbBlue;
		r = (double)m_pSourceData[i][j].rgbRed/temp;
		g = (double)m_pSourceData[i][j].rgbGreen/temp;
		Y = 0.30*m_pSourceData[i][j].rgbRed+0.59*m_pSourceData[i][j].rgbGreen
			+0.11*m_pSourceData[i][j].rgbBlue;
		if(g<0.398 && g > 0.246 && r<0.664 && r>0.333 && r>g && g>=0.5*(1-r))
		{
			m_pBinaryArray[i][j] = 0;  //����λ��
		}
		else if(Y<40)
		{
			m_pBinaryArray[i][j] = 1;  //ͷ��λ��
		}
		else
		{
			m_pBinaryArray[i][j] = 2;  //ʲôҲ����
		}
	}
	m_bBinaryOK = true;
}

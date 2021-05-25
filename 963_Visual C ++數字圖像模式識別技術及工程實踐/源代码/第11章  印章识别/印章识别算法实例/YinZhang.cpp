// YinZhang.cpp
// ӡ��ͼ�����һЩ�ӿ�
//
//////////////////////////////////////////////////////////////////////

#include "YinZhang.h"
#include "math.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CYinZhang::CYinZhang()
{
	m_tOriPixelArray = NULL;//ԭʼλͼ����
	m_tResPixelArray = NULL;//�ο�λͼ����
}

CYinZhang::~CYinZhang()
{

}

////////////////////////////////////////////////////////////////////
//���ܣ�װ��ͼ��
//������FilePathName��ͼ���ļ�·����
void CYinZhang::LoadImage(CString &FilePathName)
{
	int i,j;
	//����Ƿ�Ϊ�գ���Ϊ����Ҫ�ͷ��ڴ�
	if(m_tOriPixelArray !=NULL)
	{
		for(i=0; i<ImageHeight; i++)
		{
			delete m_tOriPixelArray[i];
			delete m_tResPixelArray[i];
			delete ImageArray[i];
		}
	}

	m_dib->Open(FilePathName);
	ImageWidth = m_dib->GetWidth();
	ImageHeight = m_dib->GetHeight();

	BYTE	*colorTable;
	colorTable = (BYTE *)m_dib->m_pDibBits;
	int byteBitCount  = m_dib->GetBiBitCount()/8;

	m_tOriPixelArray  = new RGBQUAD*[ImageHeight];
	m_tResPixelArray  = new RGBQUAD*[ImageHeight];
	ImageArray = new BYTE*[ImageHeight];
	for(int l=0 ; l<ImageHeight; l++)
	{
		m_tOriPixelArray[l] = new RGBQUAD[ImageWidth];
		m_tResPixelArray[l] = new RGBQUAD[ImageWidth];
		ImageArray[l] = new BYTE[ImageWidth];
	}

	int count = 0;
	for(i=ImageHeight-1; i>=0; i--)
	{
		for(j=0; j<ImageWidth; j++)
		{
			m_tOriPixelArray[i][j].rgbBlue =colorTable[count++];
			m_tOriPixelArray[i][j].rgbGreen=colorTable[count++];
			m_tOriPixelArray[i][j].rgbRed  =colorTable[count++];
			m_tOriPixelArray[i][j].rgbReserved = 0;
			m_tResPixelArray[i][j]=m_tOriPixelArray[i][j];
			ImageArray[i][j] = (BYTE)(((unsigned int)m_tOriPixelArray[i][j].rgbBlue
								+(unsigned int)m_tOriPixelArray[i][j].rgbGreen
								+(unsigned int)m_tOriPixelArray[i][j].rgbRed)/3);
			count += byteBitCount-3;
		}
		count += (4-(ImageWidth*byteBitCount)%4)%4;
	}
}

/////////////////////////////////////////////////////////////////////////////
//  ȥ������
//  ����򵥵Ĳ����˴�ԭͼ������ȡ��ɫ���ֵķ���
//  ������refer��Ԥ���趨�ĺ�ɫͼ��ӡ�¾��������ֵ
void CYinZhang::EroseBackground(RGBQUAD &refer)
{
	//������ֵ�������ʵ��ı䶯
	unsigned char threR = 50;
	unsigned char threG = 50;
	unsigned char threB = 50;
	BOOL rIn, gIn, bIn;	//������־R,G,B�����Ƿ�����ֵ��Χ��
	unsigned char temp;

	int i,j;
	for(i=0; i<ImageHeight; i++)
	{
		for(j=0; j<ImageWidth; j++)
		{
			//���ж�R����
			if((m_tOriPixelArray[i][j].rgbRed > refer.rgbRed) 
				&& (m_tOriPixelArray[i][j].rgbRed-refer.rgbRed<threR))
				rIn = true;
			else if((refer.rgbRed > m_tOriPixelArray[i][j].rgbRed)
				&& (refer.rgbRed-m_tOriPixelArray[i][j].rgbRed<threR))
				rIn = true;
			else
				rIn = false;

			//�ж�G����
			if((m_tOriPixelArray[i][j].rgbGreen > refer.rgbGreen) 
				&& (m_tOriPixelArray[i][j].rgbGreen-refer.rgbGreen<threG))
				gIn = true;
			else if((refer.rgbGreen > m_tOriPixelArray[i][j].rgbGreen)
				&& (refer.rgbGreen-m_tOriPixelArray[i][j].rgbGreen<threG))
				gIn = true;
			else
				gIn = false;

			//�ж�B����
			if((m_tOriPixelArray[i][j].rgbBlue > refer.rgbBlue) 
				&& (m_tOriPixelArray[i][j].rgbBlue-refer.rgbBlue<threB))
				bIn = true;
			else if((refer.rgbBlue> m_tOriPixelArray[i][j].rgbBlue)
				&& (refer.rgbBlue-m_tOriPixelArray[i][j].rgbBlue<threB))
				bIn = true;
			else
				bIn = false;

			if(rIn && gIn && bIn)
				ImageArray[i][j] = (BYTE)1;
			else
				ImageArray[i][j] = (BYTE)0;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
//��ȡ����
void CYinZhang::FeatureExtract()
{
	GlobalCentroid = (double)ImageWidth*(double)ImageHeight;
	GlobalCentroidX = (double)ImageWidth/2.0;
	GlobalCentroidY = (double)ImageHeight/2.0;

	int i,j;
	PrintCentroidX = 0.0;
	PrintCentroidY = 0.0;
	PrintMass = 0.0;
	double tempX = 0.0;
	double tempY = 0.0;

	for(i=0; i<ImageHeight; i++)
	{
		for(j=0; j<ImageWidth; j++)
		{
			PrintMass += (double)ImageArray[i][j];
			tempX += (double)j*(double)ImageArray[i][j];
			tempY += (double)i*(double)ImageArray[i][j];
		}
	}

	PrintCentroidX = tempX/PrintMass;
	PrintCentroidY = tempY/PrintMass;

	CentroidDistance = sqrt((PrintCentroidX-GlobalCentroidX)*(PrintCentroidX-GlobalCentroidX)
		+(PrintCentroidY-GlobalCentroidY)*(PrintCentroidY-GlobalCentroidY));
}

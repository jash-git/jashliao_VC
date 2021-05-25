/* ========================================== *
 * Filename:	bpnet.h                       *
 * Description:								  *
 * һ��΢�������磬ʹ��BP������Ȩֵ         *
 * ========================================== */

#include <math.h>
#include <stdlib.h>
#include <time.h>

#define BP_LEARNING	(float)(0.5)	// ѧϰϵ��

class CBPNet 
{
	public:
		CBPNet();
		~CBPNet() {};

		float Train(float, float, float);
		float Run(float, float);

	private:
		float m_fWeights[3][3];		// 3����Ԫ

		float Sigmoid(float);		// S�κ���
};

CBPNet::CBPNet() 
{
	srand((unsigned)(time(NULL)));
	
	for (int i=0;i<3;i++) 
	{
		for (int j=0;j<3;j++) 
		{
			// ����һЩԭ��΢���ṩ��rand()�����������������
			// ������������Ҫ��֮���ʵ��ı任���䵽-1��1֮��
			m_fWeights[i][j] = (float)(rand())/(32767/2) - 1;
		}
	}
}

//ѵ������
float CBPNet::Train(float i1, float i2, float d) 
{
	// ����
	float net1, net2, i3, i4, out;
	
	// �������������Ԫֵ
	net1 = 1 * m_fWeights[0][0] + i1 * m_fWeights[1][0] +
		  i2 * m_fWeights[2][0];
	net2 = 1 * m_fWeights[0][1] + i1 * m_fWeights[1][1] +
		  i2 * m_fWeights[2][1];

	// ʹ��S����
	i3 = Sigmoid(net1);
	i4 = Sigmoid(net2);

	// ����������ֵ
	net1 = 1 * m_fWeights[0][2] + i3 * m_fWeights[1][2] +
	   	  i4 * m_fWeights[2][2];
	out = Sigmoid(net1);

	//���������򴫲�
	float deltas[3];
	
	deltas[2] = out*(1-out)*(d-out);
	deltas[1] = i4*(1-i4)*(m_fWeights[2][2])*(deltas[2]);
	deltas[0] = i3*(1-i3)*(m_fWeights[1][2])*(deltas[2]);

	// ����Ȩֵ
	float v1 = i1, v2 = i2;
	for(int i=0;i<3;i++) 
	{
		// ����б�Ҫ���ı�������ֵ
		if (i == 2) 
		{
			v1 = i3;
			v2 = i4;
		}
				
		m_fWeights[0][i] += BP_LEARNING*1*deltas[i];
		m_fWeights[1][i] += BP_LEARNING*v1*deltas[i];
		m_fWeights[2][i] += BP_LEARNING*v2*deltas[i];
	}

	return out;
}

//S����
float CBPNet::Sigmoid(float num) 
{
	return (float)(1/(1+exp(-num)));
}

//��������
float CBPNet::Run(float i1, float i2) 
{
	float net1, net2, i3, i4;
	
	net1 = 1 * m_fWeights[0][0] + i1 * m_fWeights[1][0] +
		  i2 * m_fWeights[2][0];
	net2 = 1 * m_fWeights[0][1] + i1 * m_fWeights[1][1] +
		  i2 * m_fWeights[2][1];

	i3 = Sigmoid(net1);
	i4 = Sigmoid(net2);

	net1 = 1 * m_fWeights[0][2] + i3 * m_fWeights[1][2] +
	   	  i4 * m_fWeights[2][2];
	return Sigmoid(net1);
}


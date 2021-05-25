//dih.h
#ifndef dih_h
#define dih_h

#include<math.h>
#define DUANBILENGTH 30.0

struct dihfrequency{
	double f0;
	double f1;
	double f2;
	double f3;
};

typedef struct dihfrequency DIHFQ;
typedef struct dihfrequency* PDIHFQ;

//////////////////////////////////////////////////////////////////////////////////
//���㷽��x[]��y[]��dire[]�ֱ���x,y���꣬�������飬length�����鳤��
void dih_compute_direction(double x[],double y[],int dire[],int length);

//////////////////////////////////////////////////////////////////////////////////
//����Ƶ��
//dire[]�Ƿ������飬temp������
void dih_compute_frequency(int dire[],int length,PDIHFQ temp);

////////////////////////////////////////////////////////////////////////////////////
//����Ƶ�ʣ����Ͼ�������
void dih_compute_frequency_dist(int dire[],double x[],double y[],int length,PDIHFQ temp);

/////////////////////////////////////////////////////////////////////////////////////////
//����Ƶ�ʣ�����ѹ������
void dih_compute_frequency_pressure(int dire[],double pressure[],int length,PDIHFQ temp);

/////////////////////////////////////////////////////////////////////////////////////////
//ͬʱ����ѹ����Ƶ������
void dih_compute_frequency_dp(int dire[],double pressure[],double x[],double y[],int length,PDIHFQ temp);

//////////////////////////////////////////////////////////////////////////////////////////
//�������
double dih_dist_compute(PDIHFQ fq1,PDIHFQ fq2);

#endif

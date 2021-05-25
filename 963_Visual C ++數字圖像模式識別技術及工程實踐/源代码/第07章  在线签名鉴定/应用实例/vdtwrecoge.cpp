/*vdtwrecoge.c****************************************************************/

#include "vdtwrecoge.h"
#include "math.h"
double vdistance[DTWMAXNUM][DTWMAXNUM]; /*�������*/
double vdtwpath[DTWMAXNUM][DTWMAXNUM]; /*����·��*/

/*****************************************************************************/
/* VectorAdd(mvector *A,mvector *B,mvector *C)
/* �����ӷ�����������C��
/*****************************************************************************/
void VectorAdd(mvector *A,mvector *B,mvector *C)
{
	if(A->num != B->num)
		return;
	int dim = A->num;
	for(int i = 0; i < dim; i++)
	{
		C->data[i] = A->data[i] + B->data[i];
	}
	C->num = dim;
}
/*****************************************************************************/
/*VectorInit(mvector *A,int dim) ������ʼ��
/* dim ά��
/******************************************************************************/

void VectorInit(mvector *A,int dim)
{
	if((dim > MAX_DIM)||(A == NULL))
		return ;
	for(int i = 0; i < dim; i++)
	{
		A->data[i] = 0.0;
	}
	A->num = dim;

}

/*****************************************************************************/
/*VectorMul(mvector *A,double mul) ��������
/* 
/*****************************************************************************/
void VectorMul(mvector *A,double mul)
{
	for(int i = 0; i<MAX_DIM; i++)
	{
		A->data[i] *= mul;

	}

}
#define SQUARE(x) x*x
/*****************************************************************************/
/* VectorDistance,��������������֮��ľ��룬ŷ�Ͼ���
/* A��B�Ǵ���������������
/*****************************************************************************/
double VectorDistance(mvector *A,mvector *B)
{
	double total = 0.0;
	double *vec1 = A->data;
	double *vec2 = B->data;
	double temp;
	int dim = A->num;
	if(A->num != B->num)
		return -1.0;
	for(int i = 0; i < dim; i++)
	{	
		temp = vec1[i] - vec2[i];
		total += SQUARE(temp);
	}
	total /= dim;
	total = sqrt(total);
	return total;
}
#undef SQUARE


/*****************************************************************************/
/* DTWDistance������������֮���ƥ�����
/* A,B�ֱ�Ϊ��һ�ڶ������飬I��JΪ�����鳤�ȣ�rΪƥ�䴰�ڵĴ�С
/* r�Ĵ�Сһ��ȡΪ���鳤�ȵ�1/10��1/30
/* ������������֮���ƥ�����,������أ�1.0���������鳤��̫����
/*****************************************************************************/
double VDTWDistanceFun(mvector *A,int I,mvector *B,int J,int r)
{
	int i,j;
	double dist;
	int istart,imax;
	double g1,g2,g3;
	int pathsig=1;/*·���ı�־*/
	int r2=r+ABS(I-J);/*ƥ�����*/
	int dim = A->num;    //������ά��
	if(A->num != B->num){
		return -1.0;
	}
	if((r2>I-1)||(r2>J-1)){
		return -1.0;
	}

	/*����������Ч��*/
	if(I>DTWMAXNUM||J>DTWMAXNUM){
		//printf("Too big number\n");
		return -1.0;
	}
	
	/*����һЩ��Ҫ�ĳ�ʼ��*/
	for(i=0;i<I;i++){
		for(j=0;j<J;j++){
			vdtwpath[i][j]=0;
			vdistance[i][j]=DTWVERYBIG;
		}
	}
	
	/*��̬�滮����С����*/
	/*�����Ҳ��õ�·���� -------
	                          . |
	                        .   |
	                      .     |
	                    .       |
	 �п����и��õ�ǰ��·������û��ϸ����֤�������㷨����������һ����
	 */
	vdistance[0][0]=(double)2*VectorDistance(&A[0],&B[0]);
	for(i=1;i<=r2;i++){
		vdistance[i][0]=vdistance[i-1][0]+VectorDistance(&A[i],&B[0]);
	}
	for(j=1;j<=r2;j++){
		vdistance[0][j]=vdistance[0][j-1]+VectorDistance(&A[0],&B[j]);
	}
	
	for(j=1;j<J;j++){
		istart=j-r2;
		if(j<=r2)
			istart=1;
		imax=j+r2;
		if(imax>=I)
			imax=I-1;

		
		for(i=istart;i<=imax;i++){
			g1=vdistance[i-1][j]+VectorDistance(&A[i],&B[j]);
			g2=vdistance[i-1][j-1]+2*VectorDistance(&A[i],&B[j]);
			g3=vdistance[i][j-1]+VectorDistance(&A[i],&B[j]);
			g2=MIN(g1,g2);
			g3=MIN(g2,g3);
			vdistance[i][j]=g3;
		}
	}
		
	dist=vdistance[I-1][J-1]/((double)(I+J));
	return dist;
}/*end DTWDistance*/

/*****************************************************************************/
/* DTWTemplate�����н���ģ��Ĺ���
/* ����AΪ�Ѿ������õ�ģ�壬�������Ժ����ѵ��������ʱ��
/* ���ѽ����õ�ģ����Ϊ��һ��������IΪģ��ĳ��ȣ������ģ���в��ٸı�
/* BΪ�¼����ѵ��������JΪB�ĳ��ȣ�turnΪѵ���Ĵ������ڵ�һ��
/* ���������齨��ģ��ʱ��rΪ1�����ǳ���Ȩֵ�Ŀ���
/* temp����ƥ������ѵ�����ģ�壬����temp[DTWMAXNUM]��������������ѵ����ģ��ĳ���
/* �����������-1������ѵ������֮����������Ҫ����ѡ��ѵ��������
/* ttΪ����֮��������ֵ�����ж���
/* rltdistance������룬��һ���������齨��ģ��ʱ�������⸳��һ��ֵ��
/* ������ǰһ�η��ص�ֵ����ò���
/*****************************************************************************/
int VDTWTemplate(mvector *A,int I,mvector *B,int J,mvector *temp,int turn,double tt,double *rltdistance)
{
	double dist;
	int i,j;
	int pathsig=1;
	int dim = A->num;
	dist=VDTWDistanceFun(A,I,B,J,(int)(I/30));
	if(dist>tt){
		printf("\nSample doesn't match!\n");
		return -1;
	}
		
	if(turn==1)
		*rltdistance=dist;
	else{
		*rltdistance=((*rltdistance)*(turn-1)+dist)/turn;
	}
	/*Ѱ��·��,�����Ҳ���������������*/
	i=I-1;
	j=J-1;
	while(j>=1||i>=1){
		double m;
		if(i>0&&j>0){
			m=MIN(MIN(vdistance[i-1][j],vdistance[i-1][j-1]),vdistance[i][j-1]);
			if(m==vdistance[i-1][j]){
				vdtwpath[i-1][j]=pathsig;
				i--;
			}
			else if(m==vdistance[i-1][j-1]){
				vdtwpath[i-1][j-1]=pathsig;
				i--;
				j--;
			}
			else{
				vdtwpath[i][j-1]=pathsig;
				j--;
			}
		}
		else if(i==0){
			vdtwpath[0][j-1]=pathsig;
			j--;
		}
		else{/*j==0*/
			vdtwpath[i-1][0]=pathsig;
			i--;
		}
	}
	vdtwpath[0][0]=pathsig;
	vdtwpath[I-1][J-1]=pathsig;
	
	/*����ģ��*/
	for(i=0;i<I;i++){
		mvector ftemp;
		VectorInit(&ftemp,dim);
		int ntemp=0;
		for(j=0;j<J;j++){
			if(vdtwpath[i][j]==pathsig){
				VectorAdd(&ftemp,&B[j],&ftemp);
				ntemp++;
			}
		}
		VectorMul(&ftemp,1.0/(double)ntemp);
		//temp[i]=(A[i]*turn+ftemp)/((double)(turn+1));/*ע�������Ȩֵ*/
		VectorMul(&A[i],turn);
		VectorAdd(&ftemp,&A[i],&temp[i]);
		VectorMul(&temp[i],1.0/(double)(turn+1));
	}
	
	
	return I;/*����ģ��ĳ���*/
}//end DTWTemplate
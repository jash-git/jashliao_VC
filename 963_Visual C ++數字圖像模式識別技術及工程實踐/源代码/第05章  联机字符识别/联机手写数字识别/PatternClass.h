//ģʽʶ���࣬ʵ��������Ĵ洢��ʶ���
//�廪��ѧ�Զ���ϵ98��  �̺���
#include<stdio.h>

class PatternClass{
private:
	//˽�б���
	int xMax,yMax;//�����ʵ��ά��
	int realValue;//�������ʾ��ʵ��ֵ
	int M[32][32];//�洢����

private:
	//˽�к���
	int Linknize(void);
	int Recognize(void);

public:
	PatternClass();
	void SetXY(int x,int y){xMax=x;yMax=y;}
	void SetValue(int value){realValue=value;}
	void GetValue(int &value){value=realValue;}
	void GetXY(int &x,int &y){x=xMax;y=yMax;}
	void SetM(int data[32][32]);
};



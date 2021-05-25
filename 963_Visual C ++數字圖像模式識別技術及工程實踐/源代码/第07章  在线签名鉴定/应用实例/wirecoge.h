<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title></title>
</head>
<body>
<pre>/*******************************************************************/
/*	wirecoge.h&nbsp;�ʼ�����ͷ�ļ�
/*	�ʼ��������
/*	����:��������д�ض��ֵ�ѹ�����ߺ�λ������ʶ��д����
/*	����:�̺���	�����
/*	��λ:�廪��ѧ�Զ���ϵ��81��
/*	ʱ��:2001��8��29��
/*******************************************************************/

#define&nbsp;WIMAXTIME	2000	/*���������ĸ���,����ʵ��Ӳ���Ĳ�ͬ*/
							/*���Լ����޸�*/

#define&nbsp;MAXPRESSURE	100.00	/*����ѹ�������ֵ,Ϊ��ģʽƥ��ʱ��*/
#define&nbsp;XLENGTH		300		/*�����ֵ�λ��X����ĳ���*/
#define&nbsp;YLENGTH		150		/*�����ֵ�λ��Y����ĳ���*/
#define&nbsp;DTWRESULTNUM	300	/*���嶯̬ʱ�������������ĳ���*/

typedef&nbsp;struct&nbsp;point{
	int&nbsp;x;
	int&nbsp;y;
}POINT;

class&nbsp;wirecoge{
private:	/*����˽�б���*/
public:
	unsigned&nbsp;char&nbsp;DTWPath[DTWRESULTNUM][DTWRESULTNUM];	/*���涯̬ʱ������·�����*/
	float&nbsp;DTWDistance[DTWRESULTNUM][DTWRESULTNUM];	/*���㶯̬ʱ�����۾���*/
	float&nbsp;pressure[WIMAXTIME];	/*ѹ����С����*/
	float&nbsp;pressure1[WIMAXTIME];	/*��1��ѹ������*/
	float&nbsp;pressure2[WIMAXTIME];	/*��2��ѹ������*/
	float&nbsp;pressure3[WIMAXTIME];	/*��3��ѹ������*/
	POINT&nbsp;position[WIMAXTIME];	/*λ������*/
	POINT&nbsp;dtwresult[DTWRESULTNUM];	/*�洢��̬ʱ������ƥ����*/
public:		
	//wirecoge();/*�д����¶���*/
	//~wirecoge();
	float&nbsp;DTWCompute(float&nbsp;A[],int&nbsp;I,float&nbsp;B[],int&nbsp;J);	/*��̬ʱ�����ۣ����������DT
WPath��*/
	float&nbsp;MinFloat(float&nbsp;a,float&nbsp;b);
	float&nbsp;AbsFloat(float&nbsp;a);
	int&nbsp;AbsInt(int&nbsp;a);
};

</pre>
</body>
</html>
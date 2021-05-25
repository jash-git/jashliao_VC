// JiuG.h: interface for the CJiuG class.

#if !defined(AFX_JIUG_H__A836D34F_3D4D_450C_BB2A_1412429F6451__INCLUDED_)
#define AFX_JIUG_H__A836D34F_3D4D_450C_BB2A_1412429F6451__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxcoll.h>//������CPtrList

typedef struct JiuGongState{
	int curdistance;//��ǰ�ľ��룬�ӳ�ʼ�ڵ㿪ʼ
	int state[3][3];
	struct JiuGongState *prestate;//��һ���ڵ��ָ��
	struct JiuGongState *nextstate;//��һ���ڵ��ָ��
}JGState;//����Ź��ṹ

class CJiuG  
{
public:
	JGState StateInit;//��ʼ״̬
	JGState StateObj;//Ŀ��״̬
	JGState StateCur;//��ǰ״̬

	CPtrList OpenList;//Open��
	CPtrList CloseList;//Close��
	CPtrList ResultList;//������
	JGState *curstep;

public:
	int m_ndepth;//�������
	int ComputeJO(JGState *jo);//����״̬����ż��
	CJiuG();
	virtual ~CJiuG();
	bool MoveLeft(JGState *src,JGState *result);//����
	bool MoveRight(JGState *src,JGState *result);//����
	bool MoveUp(JGState *src,JGState *result);//����
	bool MoveDown(JGState *src,JGState *result);//����
	bool Compare(JGState *src1,JGState *src2);//�Ƚ�����״̬�Ƿ����
	int ComputeFn(JGState *cur,JGState *dest);//���ۺ����ļ��㣬���ǲ�����Pn
	bool Search();//��A*�㷨�������Ž�
	void FreeList(CPtrList *list);//�ͷ��ڴ�
	void CopyJG(JGState *src,JGState *dest);//���ƾŹ�
};

#endif // !defined(AFX_JIUG_H__A836D34F_3D4D_450C_BB2A_1412429F6451__INCLUDED_)

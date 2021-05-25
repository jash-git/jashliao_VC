// Bwfind.h: interface for the CBwfind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BWFIND_H__A50177D8_86F9_40EA_9FDC_B3DF64DD82CF__INCLUDED_)
#define AFX_BWFIND_H__A50177D8_86F9_40EA_9FDC_B3DF64DD82CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define BLACK 1;
#define WHITE -1;
#define EMPTY 0;
class CBwfind  :CObject
{
public:
	//�������
	void SaveBoard(int tb[][8]);
	int outcome;
	int bak;
	//��¼64������֣��Ա㷴��
	int save[64][8][8];
	BOOL preview;
	int stepx,stepy;
	//����
	BOOL search(int tb[][8],int);
	int depth;
	int searchend;
	//����
	int CountNum();
	int CountWhite();
	int CountBlack();
	void select(int);
	void newboard(int tb[][8],int,int,int);
	BOOL decide(int,int,int);
	CBwfind();
	int board[8][8];
	virtual ~CBwfind();
	int ComChoice,ManChoice;
    
protected:
	
private:
	//���ۺ���
	void Corner(int tb[][8],int i,int j,int &value);
	void LineSense(int tb[][8],int chessx,int chessy,int &value);
	int Mobility(int tb[][8],int flag);
	void CornerSense(int tb[][8],int &);
	int valuefirst(int tb[][8]);
	int findfirst(int tb[][8],int &,int &, int);
	//����
	int white(int tb[][8]);
	int black(int tb[][8]);
	int Total(int tb[][8]);
	BOOL judge(int tb[][8],int chessx,int chessy,int flag);
	int findlast(int tb[][8], int &,int &,int);
};

#endif // !defined(AFX_BWFIND_H__A50177D8_86F9_40EA_9FDC_B3DF64DD82CF__INCLUDED_)

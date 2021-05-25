//////////////////////////////////////////////////////////////////
// CPathFinder class 
//
// A* �㷨�ӿڣ�����Թ��������

#ifndef _PATHFINDER_H_
#define _PATHFINDER_H_

#include <memory.h>

//�ڵ���
class _asNode {
	public:
		_asNode(int a = -1,int b = -1) : x(a), y(b), number(0), numchildren(0) 
		{
			parent = next = NULL;
			memset(children, 0, sizeof(children));
		}

		int			f,g,h;			// A*�㷨�Ĺ��ۺ���ֵ��
		int			x,y;			// ����
		int			numchildren;
		int			number;			// x*30+y
		_asNode		*parent;		// ���ڵ�
		_asNode		*next;
		_asNode		*children[8];	// 8����
};

// ��ջ
struct _asStack {
	_asNode	 *data;
	_asStack *next;
};

typedef int(*_asFunc)(int, int, void *);

//�Թ���
class CPathFinder {
	public:
		CPathFinder();
		~CPathFinder();

		bool	GeneratePath(int, int, int, int);
		void	SetValid(_asFunc sv) { udValid = sv;   }
		void	SetCost(_asFunc sc)  { udCost = sc;    }
		void	SetData(void *sd)	 { m_pCBData = sd; }
		void	SetRows(int r)		 { m_iRows = r;    }

		_asNode	*GetBestNode() { return m_pBest; }

	protected:
		int		m_iRows;			// ��������ڵ�ĸ���
		int		m_iSX, m_iSY, m_iDX, m_iDY, m_iDNum;
		void	*m_pCBData;			// �Ѿ������Ľڵ�

		_asNode	*m_pOpen;			// OPEN��
		_asNode	*m_pClosed;			// CLOSE��
		_asNode *m_pBest;			// ��õĽڵ�
		_asStack*m_pStack;			// ��ջ

		_asFunc	udCost;				// �û�����ķ���
		_asFunc udValid;			// �û��������Ч����

		// һЩ�ṹ��������
		void	AddToOpen(_asNode *);
		void	ClearNodes();
		void	CreateChildren(_asNode *);
		void	LinkChild(_asNode *, int, int);
		void	UpdateParents(_asNode *);

		// ��ջ��������
		void	Push(_asNode *);
		_asNode *Pop();
		
		_asNode *CheckList(_asNode *, int);
		_asNode	*GetBest();
		
		// ��������
		inline int Coord2Num(int x, int y) { return x * m_iRows + y; }
};

#endif

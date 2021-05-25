//PathFinder.cpp
#include "stdafx.h"
#include "PathFinder.h"

//���캯��
CPathFinder::CPathFinder() 
{
	m_pOpen = m_pClosed = NULL;
	m_pStack = NULL;
}

//��������
CPathFinder::~CPathFinder() 
{
	ClearNodes();
}

////////////////////////////////////////////////////////////////////////////
//����ڵ�
void CPathFinder::ClearNodes() 
{
	_asNode *temp = NULL, *temp2 = NULL;

	if (m_pOpen) 
	{
		while (m_pOpen) 
		{
			temp = m_pOpen->next;

			delete m_pOpen;

			m_pOpen = temp;
		}
	}

	if (m_pClosed) {
		while (m_pClosed) {
			temp = m_pClosed->next;

			delete m_pClosed;

			m_pClosed = temp;
		}
	}
}

////////////////////////////////////////////////////////////////////
// ���ܣ���Ѱ����·��
// ������sx������x����
//       sy������y����
//       dx���յ��x����
//       dy���յ��y����
bool CPathFinder::GeneratePath(int sx, int sy, int dx, int dy) 
{
	ClearNodes();
	
	m_iSX = sx; m_iSY = sy; m_iDX = dx; m_iDY = dy;
	m_iDNum = Coord2Num(dx,dy);

	_asNode *temp = new _asNode(sx, sy);
	_asNode *best;

	temp->g = 0;
	temp->h = (dx-sx)*(dx-sx) + (dy-sy)*(dy-sy);
	temp->f = temp->g + temp->h;
	temp->number = Coord2Num(sx, sy);

	m_pOpen = temp;
	while (true) 
	{
		if (!(best = GetBest())) return false;

		if (best->number == m_iDNum) break;

		CreateChildren(best);
	};
	
	m_pBest = best;

	return true;
}

////////////////////////////////////////////////////////////////////////////
// Ѱ����õĽڵ�
_asNode *CPathFinder::GetBest() 
{
	if (!m_pOpen) return NULL;

	_asNode *temp = m_pOpen, *temp2 = m_pClosed;
	m_pOpen = temp->next;

	if (temp2) 
	{
		m_pClosed = temp;
		m_pClosed->next = temp2;
	} 
	else 
	{
		m_pClosed = temp;
		m_pClosed->next = NULL;
	}

	return temp;
}

////////////////////////////////////////////////////////////////////////////
// ���ɺ�ѡ�ڵ�
void CPathFinder::CreateChildren(_asNode *node) 
{
	int x = node->x, y = node->y;

	for (int i=-1;i<2;i++) 
	{
		for (int j=-1;j<2;j++) 
		{
			if (i == 0 && j == 0 || !udValid(x+i, y+j, m_pCBData)) 
				continue;

			LinkChild(node, x+i, y+j);
		}
	}
}

///////////////////////////////////////////////////////////////////
// �����ӽڵ�
// ������node��Ҫ����Ľڵ�
//       x��x����
//       y��y����
void CPathFinder::LinkChild(_asNode *node, int x, int y) 
{
	int g = node->g + udCost(x,y,m_pCBData);
	int num = Coord2Num(x,y);

	_asNode *check = NULL;

	if (check = CheckList(m_pOpen, num)) 
	{
		node->children[node->numchildren++] = check;
		
		// ���ָ��õ�·��������
		if (g < check->g) 
		{
			check->parent = node;
			check->g = g;
			check->f = g + check->h;
		}
	} 
	else if (check = CheckList(m_pClosed, num)) 
	{
		node->children[node->numchildren++] = check;

		if (g < check->g) 
		{
			check->parent = node;
			check->g = g;
			check->f = g + check->h;

			UpdateParents(check);
		}
	} 
	else 
	{
		_asNode *newnode = new _asNode(x,y);
		newnode->parent = node;
		newnode->g = g;
		newnode->h = (x-m_iDX)*(x-m_iDX) + (y-m_iDY)*(y-m_iDY);
		newnode->f = newnode->g + newnode->h;
		newnode->number = Coord2Num(x,y);

		AddToOpen(newnode);

		node->children[node->numchildren++] = newnode;
	}
}

/////////////////////////////////////////////////////////////////////////////
// ������������
// ������node������ͷ�ڵ�
//       num��Ҫ��������
_asNode *CPathFinder::CheckList(_asNode *node, int num) 
{
	while (node) 
	{
		if (node->number == num) 
			return node;

		node = node->next;
	}

	return NULL;
}

//////////////////////////////////////////////////////////////////
// ��OPEN�������ӽڵ㣬������fֵ��������
// ������addnode�������ӵĽڵ�
void CPathFinder::AddToOpen(_asNode *addnode) 
{
	_asNode *node = m_pOpen;
	_asNode *prev = NULL;

	if (!m_pOpen) 
	{
		m_pOpen = addnode;
		return;
	}

	while(node) 
	{
		if (addnode->f > node->f) 
		{
			prev = node;
			node = node->next;
		} 
		else 
		{
			if (prev) 
			{
				prev->next = addnode;
				addnode->next = node;
			} 
			else 
			{
				_asNode *temp = m_pOpen;

				m_pOpen = addnode;
				m_pOpen->next = temp;
			}

			return;
		}
	}

	prev->next = addnode;
}

//////////////////////////////////////////////////////////////////
// ����˫�׽ڵ�
// ������node�������µĽڵ�
void CPathFinder::UpdateParents(_asNode *node) 
{
	int g = node->g, c = node->numchildren;

	_asNode *kid = NULL;
	for (int i=0;i<c;i++) 
	{
		kid = node->children[i];
		if (g+1 < kid->g) 
		{
			kid->g = g+1;
			kid->f = kid->g + kid->h;
			kid->parent = node;
			
			Push(kid);
		}
	}

	_asNode *parent;
	while (m_pStack) 
	{
		parent = Pop();
		c = parent->numchildren;
		for (int i=0;i<c;i++) 
		{
			kid = parent->children[i];
			
			if (parent->g+1 < kid->g) 
			{
				kid->g = parent->g + udCost(kid->x, kid->y,m_pCBData);
				kid->f = kid->g + kid->h;
				kid->parent = parent;

				Push(kid);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////
// ��ջ
void CPathFinder::Push(_asNode *node) 
{
	if (!m_pStack) 
	{
		m_pStack = new _asStack;
		m_pStack->data = node;
		m_pStack->next = NULL;
	} 
	else 
	{
		_asStack *temp = new _asStack;

		temp->data = node;
		temp->next = m_pStack;
		m_pStack = temp;
	}
}

///////////////////////////////////////////////////////////////////////////
// ��ջ
_asNode *CPathFinder::Pop() 
{
	_asNode *data = m_pStack->data;
	_asStack *temp = m_pStack;

	m_pStack = temp->next;
	
	delete temp;

	return data;
}

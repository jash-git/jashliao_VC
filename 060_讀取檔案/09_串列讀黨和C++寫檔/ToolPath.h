// ToolPath.h: interface for the CToolPath class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLPATH_H__503A9748_6C1E_4999_9048_B7703691979E__INCLUDED_)
#define AFX_TOOLPATH_H__503A9748_6C1E_4999_9048_B7703691979E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CToolPath : public CObject //2-step 
{
public:
	CToolPath();
	CPoint m_CPStart,m_CPEnd;
	void SetState(int state);
	int GetState();
	virtual ~CToolPath();
	virtual void Serialize(CArchive& ar);
private:
	int m_State;
DECLARE_SERIAL(CToolPath)
};

#endif // !defined(AFX_TOOLPATH_H__503A9748_6C1E_4999_9048_B7703691979E__INCLUDED_)

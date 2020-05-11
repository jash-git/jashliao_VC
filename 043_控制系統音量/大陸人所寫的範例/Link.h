/************************************************************************ 
* 文件名：    Link.h 
* 文件描述：  超级链接
* 创建人：    三峡大学 程红秀, 2004年12月26日 
* 版本号：    1.0 
************************************************************************/ 
#if !defined _HYPERLINK_H
#define _HYPERLINK_H

#if _MSC_VER >= 1000
#pragma once
#endif 

class CLink : public CStatic
{
public:
    CLink();
    virtual ~CLink();

public:

    void SetToolTipText(CString str);
    void SetLinkCursor(HCURSOR hCursor);
    void SetDefaultCursor();

    //{{AFX_VIRTUAL(CLink)
	public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL DestroyWindow();
	protected:
    virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

protected:
    BOOL     m_bOver;   
    HCURSOR  m_hLinkCursor; 
    CToolTipCtrl m_ToolTip;   

   
protected:
    //{{AFX_MSG(CLink)
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}
#endif 
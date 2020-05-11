#ifndef __TRANSPARENTIMAGE_H
#define __TRANSPARENTIMAGE_H

#if _MSC_VER >= 1000
#pragma once
#endif

class CTransparentImage	: public CStatic
{
public:
	CTransparentImage() ;
	virtual ~CTransparentImage() ;
protected:
	//{{AFX_MSG( CTransparentImage )
	afx_msg void OnPaint() ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
} ;

//{{AFX_INSERT_LOCATION}}
#endif

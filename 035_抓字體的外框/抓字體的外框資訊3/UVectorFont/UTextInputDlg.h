#if !defined(AFX_UTEXTINPUTDLG_H__6B315A4C_1F7B_4D7E_B581_08A120785E16__INCLUDED_)
#define AFX_UTEXTINPUTDLG_H__6B315A4C_1F7B_4D7E_B581_08A120785E16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UTextInputDlg.h : header file
//

int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf,LPNEWTEXTMETRIC lpntm,DWORD nFontType,long lparam);

/////////////////////////////////////////////////////////////////////////////
// CUTextInputDlg dialog

class CUTextInputDlg : public CDialog
{
// Construction
public:
	CUTextInputDlg(CWnd* pParent = NULL);   // standard constructor
    CString getsTextEdit() { return m_sTextEdit; }
    int getiFontHeight() { return m_iFontHeight; }
    int getiFontSpace() { return m_iFontSpace; }
    CString getsFontFaceName() { return m_sFontFaceName; }
// Dialog Data
	//{{AFX_DATA(CUTextInputDlg)
	enum { IDD = IDD_TEXT_INPUT };
	CComboBox	m_cFontFaceName;
	CString	m_sTextEdit;
	int		m_iFontHeight;
	int		m_iFontSpace;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUTextInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUTextInputDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeFontFaceName();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
    CString m_sFontFaceName;
protected:
    void save();
    void load();
    void fillFontFaceName();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UTEXTINPUTDLG_H__6B315A4C_1F7B_4D7E_B581_08A120785E16__INCLUDED_)

// SampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CInfoZipSample.h"
#include "SampleDlg.h"
#include "InfoZip\InfoZip.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSampleDlg dialog


CSampleDlg::CSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSampleDlg)
	m_sArchive = _T("");
	//}}AFX_DATA_INIT
}


void CSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSampleDlg)
	DDX_Control(pDX, IDC_FILES, m_lstFiles);
	DDX_Text(pDX, IDC_ARCHIVE, m_sArchive);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CSampleDlg)
	ON_BN_CLICKED(IDC_ADD_FILES, OnAddFiles)
	ON_BN_CLICKED(IDC_DEL_FILES, OnDeleteFiles)
	ON_BN_CLICKED(IDC_SELECT_ARCHIVE, OnSelectArchive)
	ON_BN_CLICKED(IDC_COMPRESS, OnCompress)
	ON_BN_CLICKED(IDC_EXTRACT, OnExtract)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSampleDlg message handlers

void CSampleDlg::OnAddFiles() 
{
	CFileDialog dlg (TRUE, NULL, NULL, OFN_ALLOWMULTISELECT,
		"All files (*.*)|*.*||", this);

	if (dlg.DoModal() == IDOK)
	{
		POSITION pos = dlg.GetStartPosition();
		while (pos)
		{
			CString sFile = dlg.GetNextPathName(pos);
			m_lstFiles.AddString(sFile);
		}
	}
}

void CSampleDlg::OnDeleteFiles() 
{
	int iSelCount = m_lstFiles.GetSelCount();
	int *piSelFiles = new int[iSelCount];
	m_lstFiles.GetSelItems(iSelCount, piSelFiles);

	for (int i=iSelCount-1; i>=0; i--)
	{
		int iSelectedFile = piSelFiles[i];
		m_lstFiles.DeleteString(iSelectedFile);
	}

	delete[] piSelFiles;
}

void CSampleDlg::OnSelectArchive() 
{
	CFileDialog dlg (TRUE, NULL, NULL, 0,
		"All files (*.*)|*.*||", this);

	if (dlg.DoModal() == IDOK)
	{
		CString sFile = dlg.GetPathName();
		GetDlgItem(IDC_ARCHIVE)->SetWindowText(sFile);
	}
}

void CSampleDlg::OnCompress() 
{
	BeginWaitCursor();
	char pszArchive[MAX_PATH+1];
	GetDlgItem(IDC_ARCHIVE)->GetWindowText(pszArchive, MAX_PATH+1);

	int iFileCount = m_lstFiles.GetCount();
		
	char **pFiles = (char **) new  int [iFileCount];
	for (int i=0; i<iFileCount; i++)
	{
		pFiles[i] = new char[MAX_PATH+1];
		m_lstFiles.GetText(i, pFiles[i]);
	}

	CInfoZip InfoZip;
	if (!InfoZip.InitializeZip())
	{
		EndWaitCursor();
		AfxMessageBox("Must be initialized", MB_OK);
		return;
	}

	if (!InfoZip.AddFiles(pszArchive, pFiles, iFileCount))
	{
		EndWaitCursor();
		AfxMessageBox("Files not added", MB_OK);
		return;
	}

	if (!InfoZip.Finalize())
	{
		EndWaitCursor();
		AfxMessageBox("Cannot finalize", MB_OK);
		return;
	}
	EndWaitCursor();
}

void CSampleDlg::OnExtract() 
{
	BeginWaitCursor();
	char pszArchive[MAX_PATH+1];
	ZeroMemory(pszArchive, MAX_PATH+1);
	GetDlgItem(IDC_ARCHIVE)->GetWindowText(pszArchive, MAX_PATH+1);

	char pszTarget[MAX_PATH+1];
	ZeroMemory(pszTarget, MAX_PATH+1);
	GetDlgItem(IDC_TARGET)->GetWindowText(pszTarget, MAX_PATH+1);

	CInfoZip InfoZip;
	if (!InfoZip.InitializeUnzip())
	{
		EndWaitCursor();
		AfxMessageBox("Must be initialized", MB_OK);
		return;
	}

	if (!InfoZip.ExtractFiles(pszArchive, pszTarget))
	{
		EndWaitCursor();
		AfxMessageBox("Files not added", MB_OK);
		return;
	}

	if (!InfoZip.FinalizeUnzip())
	{
		EndWaitCursor();
		AfxMessageBox("Cannot finalize", MB_OK);
		return;
	}
	EndWaitCursor();
}

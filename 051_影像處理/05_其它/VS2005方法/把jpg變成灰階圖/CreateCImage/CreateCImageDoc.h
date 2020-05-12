// CreateCImageDoc.h : interface of the CCreateCImageDoc class
//


#pragma once


class CCreateCImageDoc : public CDocument
{
protected: // create from serialization only
	CCreateCImageDoc();
	DECLARE_DYNCREATE(CCreateCImageDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CCreateCImageDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};



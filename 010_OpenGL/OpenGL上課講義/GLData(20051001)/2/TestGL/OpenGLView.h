#if !defined(AFX_OPENGLVIEW_H__76EE4DDA_A779_4EDD_B836_EA4121DD2DD9__INCLUDED_)
#define AFX_OPENGLVIEW_H__76EE4DDA_A779_4EDD_B836_EA4121DD2DD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpenGLView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// OpenGLView view

class OpenGLView : public CView
{
protected:
	OpenGLView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(OpenGLView)

// Attributes
public:

// Operations
public:
	void SetModelViewMatrix(double xth, double yth, double zth);
	void AutoScaleCal(double X, double Y, double Z, GLdouble *a, double &minx, double &maxx, double &miny, double &maxy, double &minz, double &maxz);
	void AutoScale(double xmax, double xmin, double ymax, double ymin, double zmax, double zmin, double &maxx, double &minx, double &maxy, double &miny);
	void SetObjXYZRange(double xmax, double xmin, double ymax, double ymin, double zmax, double zmin, bool depthflag=true);
	void ViewAll();
	virtual void GLRender();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(OpenGLView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~OpenGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(OpenGLView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void UpdateDrawView();
	double ObjTransX,ObjTransY,ObjTransZ;
	double ObjXMax,ObjXMin,ObjYMax,ObjYMin,ObjZMax,ObjZMin;
	void CreateProjMatrix(double xmax, double xmin, double ymax, double ymin);
	double EyeXMax,EyeXMin,EyeYMax,EyeYMin,EyeZMax,EyeZMin;
	int ScrHeight,ScrWidth;
	void GLResize(int Width, int Height);
	int MyChosePixelFormat(bool accel);
	BOOL GLHardAccel;
	BOOL SetupPixelFormat();
	CDC* m_pDC;
	HGLRC m_hRC;
	HDC m_hDC;
	BOOL InitializeOpenGL();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLVIEW_H__76EE4DDA_A779_4EDD_B836_EA4121DD2DD9__INCLUDED_)

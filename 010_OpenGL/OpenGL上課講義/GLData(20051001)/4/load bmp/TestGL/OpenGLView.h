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
	virtual void TestFunc();
	void CallPreView();
	int GetViewState();
	void SwitchViewState(int state);
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
	float PointSize;
	float ImageViewScaleX,ImageViewScaleY;
	double ImagePixelScaleX,ImagePixelScaleY;
	double ImageXMax,ImageYMax;
	GLsizei ImageWidth,ImageHeight;
	CDC* m_pDC;
	HGLRC m_hRC;
	HDC m_hDC;
	int ScrHeight,ScrWidth;
	void ModelToScreen(double x, double y, double z, int &cx, int &cy);
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ResetRView();
	int CurrentViewID;
	bool RecordViewF[5];
	double RecordViewXYZ[5][20];
	double LastPosition[3];
	void PointToVector(int x, int y, int width, int height, double v[]);
	void DrawRect(int id, CPoint p1, CPoint p2);
	void MoveView(CPoint pt);
	void ScaleView(CPoint pt);
	void RotateView(CPoint pt);
	void RecordView();
	void ZoomWindow();
	CPoint MouseDownPoint,MouseCurPoint;
	BOOL ZoomWinFlag;
	int	CurrentViewState;
	int Show3DAxisType,Show3DAxisSize;
	void Draw3DAxis();
	void Show3DAxis(int cx, int cy);
	void CreateFont();
	void SetupList();
	void GLPrintText(double x, double y, double z, const char *const string);
	GLuint AxisList,FontList;
	GLubyte AxisXColor[3],AxisYColor[3],AxisZColor[3];
	void Create3DAxis();
	void UpdateDrawView();
	double ObjXMax,ObjXMin,ObjYMax,ObjYMin,ObjZMax,ObjZMin;
	void CreateProjMatrix(double xmax, double xmin, double ymax, double ymin);
	double EyeXMax,EyeXMin,EyeYMax,EyeYMin,EyeZMax,EyeZMin;
	void GLResize(int Width, int Height);
	int MyChosePixelFormat(bool accel);
	BOOL GLHardAccel;
	BOOL SetupPixelFormat();
	BOOL InitializeOpenGL();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLVIEW_H__76EE4DDA_A779_4EDD_B836_EA4121DD2DD9__INCLUDED_)

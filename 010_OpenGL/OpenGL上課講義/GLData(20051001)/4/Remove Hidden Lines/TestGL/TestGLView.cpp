// TestGLView.cpp : implementation of the CTestGLView class
//

#include "stdafx.h"
#include "TestGL.h"

#include "TestGLDoc.h"
#include "TestGLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestGLView

IMPLEMENT_DYNCREATE(CTestGLView, OpenGLView)

BEGIN_MESSAGE_MAP(CTestGLView, OpenGLView)
	//{{AFX_MSG_MAP(CTestGLView)
	ON_COMMAND(ID_VIEW_ALL, OnViewAll)
	ON_COMMAND(ID_VIEW_ISO, OnViewIso)
	ON_COMMAND(ID_VIEW_LEFT, OnViewLeft)
	ON_COMMAND(ID_VIEW_MOVE, OnViewMove)
	ON_COMMAND(ID_VIEW_BACK, OnViewBack)
	ON_COMMAND(ID_VIEW_BOTTOM, OnViewBottom)
	ON_COMMAND(ID_VIEW_FRONT, OnViewFront)
	ON_COMMAND(ID_VIEW_PREV, OnViewPrev)
	ON_COMMAND(ID_VIEW_RIGHT, OnViewRight)
	ON_COMMAND(ID_VIEW_ROTATE, OnViewRotate)
	ON_COMMAND(ID_VIEW_SCALE, OnViewScale)
	ON_COMMAND(ID_VIEW_TOP, OnViewTop)
	ON_COMMAND(ID_VIEW_WINDOW, OnViewWindow)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ROTATE, OnUpdateViewRotate)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SCALE, OnUpdateViewScale)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WINDOW, OnUpdateViewWindow)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MOVE, OnUpdateViewMove)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, OpenGLView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, OpenGLView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OpenGLView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestGLView construction/destruction

CTestGLView::CTestGLView()
{
	// TODO: add construction code here

}

CTestGLView::~CTestGLView()
{
}

BOOL CTestGLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return OpenGLView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestGLView drawing

void CTestGLView::OnDraw(CDC* pDC)
{
	CTestGLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	OpenGLView::OnDraw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CTestGLView printing

BOOL CTestGLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation

	return DoPreparePrinting(pInfo);
}

void CTestGLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestGLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestGLView diagnostics

#ifdef _DEBUG
void CTestGLView::AssertValid() const
{
	OpenGLView::AssertValid();
}

void CTestGLView::Dump(CDumpContext& dc) const
{
	OpenGLView::Dump(dc);
}

CTestGLDoc* CTestGLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestGLDoc)));
	return (CTestGLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestGLView message handlers

void CTestGLView::GLRender()
{
	glColor3f(1.,0.5,0.); 

	glNormal3f(0.,0.,1.);
    glBegin(GL_QUADS);
      glVertex3f(100.,100.,100.);
      glVertex3f(-100.,100.,100.);
	  glVertex3f(-100.,-100.,100.);
	  glVertex3f(100.,-100.,100.);
	glEnd();

	glNormal3f(0.,0.,-1.);
	glBegin(GL_QUADS);
      glVertex3f(-100.,100.,-100.);
      glVertex3f(100.,100.,-100.);
	  glVertex3f(100.,-100.,-100.);
	  glVertex3f(-100.,-100.,-100.);
	glEnd();

	glNormal3f(1.,0.,0.);
	glBegin(GL_QUADS);
      glVertex3f(100.,100.,-100.);
      glVertex3f(100.,100.,100.);
      glVertex3f(100.,-100.,100.);
      glVertex3f(100.,-100.,-100.);
	glEnd();

	glNormal3f(-1.,0.,0.);
	glBegin(GL_QUADS);
      glVertex3f(-100.,100.,100.);
      glVertex3f(-100.,100.,-100.);
      glVertex3f(-100.,-100.,-100.);
      glVertex3f(-100.,-100.,100.);
	glEnd();

	glNormal3f(0.,1.,0.);
    glBegin(GL_QUADS);
      glVertex3f(100.,100.,-100.);
      glVertex3f(-100.,100.,-100.);
      glVertex3f(-100.,100.,100.);
      glVertex3f(100.,100.,100.);
	glEnd();

	glNormal3f(0.,-1.,0.);
	glBegin(GL_QUADS);
      glVertex3f(-100.,-100.,-100.);
      glVertex3f(100.,-100.,-100.);
      glVertex3f(100.,-100.,100.);
      glVertex3f(-100.,-100.,100.);
	glEnd();
}

void CTestGLView::OnViewAll() 
{
	// TODO: Add your command handler code here
	ViewAll();
}

void CTestGLView::OnViewIso() 
{
	// TODO: Add your command handler code here
	SetModelViewMatrix(-60.,0.,45.);
}

void CTestGLView::OnViewLeft() 
{
	// TODO: Add your command handler code here
	SetModelViewMatrix(-90.,0.,90.);
}

void CTestGLView::OnViewBack() 
{
	// TODO: Add your command handler code here
	SetModelViewMatrix(-90.,0.,180.);
}

void CTestGLView::OnViewBottom() 
{
	// TODO: Add your command handler code here
	SetModelViewMatrix(0.,180.,0.);
}

void CTestGLView::OnViewFront() 
{
	// TODO: Add your command handler code here
	SetModelViewMatrix(-90.,0.,0.);
}

void CTestGLView::OnViewRight() 
{
	// TODO: Add your command handler code here
	SetModelViewMatrix(-90.,0.,-90.);
}

void CTestGLView::OnViewTop() 
{
	// TODO: Add your command handler code here
	SetModelViewMatrix(0.,0.,0.);
}

void CTestGLView::OnViewRotate() 
{
	// TODO: Add your command handler code here
	SwitchViewState(1);
}

void CTestGLView::OnViewMove() 
{
	// TODO: Add your command handler code here
	SwitchViewState(2);
}

void CTestGLView::OnViewScale() 
{
	// TODO: Add your command handler code here
	SwitchViewState(3);
}

void CTestGLView::OnViewWindow() 
{
	// TODO: Add your command handler code here
	SwitchViewState(4);
}

void CTestGLView::OnUpdateViewRotate(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetViewState()==1);
}

void CTestGLView::OnUpdateViewMove(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetViewState()==2);
}

void CTestGLView::OnUpdateViewScale(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetViewState()==3);
}

void CTestGLView::OnUpdateViewWindow(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetViewState()==4);
}

void CTestGLView::OnViewPrev() 
{
	// TODO: Add your command handler code here
	CallPreView();
}

//處理物體遠近不同所產生的遮蔽效果
void CTestGLView::TestFunc()
{
     wglMakeCurrent(m_hDC, m_hRC);
     GLfloat LightAmbient[4]={.2f,.3f,.4f,1.0f};
	 GLfloat LightDiffuse[4]={.4f,.5f,.5f,1.0f};
	 GLfloat LightSpecular[]={1.f,1.f,1.f,1.0f};
	 GLfloat LightPos[]={1.,1.,1.,0.};
  	 GLfloat MaterialSpecular[]={.4f,.4f,.4f,1.0f};
	 GLint MaterialShininess=50;

	 glFrontFace(GL_CCW);//逆時針方向所組成的面為正面
	 glLightfv(GL_LIGHT0, GL_AMBIENT,LightAmbient);
     glLightfv(GL_LIGHT0, GL_DIFFUSE,LightDiffuse);
     glLightfv(GL_LIGHT0, GL_SPECULAR,LightSpecular);
     glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
	 glEnable(GL_COLOR_MATERIAL);
   	 glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
	 glMaterialfv(GL_FRONT,GL_SPECULAR,MaterialSpecular);
	 glMateriali(GL_FRONT,GL_SHININESS,MaterialShininess);
     
	 glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);//使第0盞燈光生效
	 //glEnable(GL_NORMALIZE); //automatic normalization of normals
     glEnable(GL_CULL_FACE);//不計算物體背面的情形
	 glCullFace(GL_BACK);
     //glShadeModel(GL_FLAT);
	 glShadeModel(GL_SMOOTH); //使物體本身的顏色能與燈光效果配合展現出來
	 //glPolygonMode(GL_FRONT,GL_FILL);
	 glPolygonMode(GL_FRONT,GL_LINE);
	 wglMakeCurrent(NULL,NULL);
}

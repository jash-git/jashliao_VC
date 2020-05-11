// TestGLView.cpp : implementation of the CTestGLView class
//

#include "stdafx.h"
#include "TestGL.h"

#include "TestGLDoc.h"
#include "TestGLView.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

GLfloat points[3][3] = {{ -400.0f, 400.0f, -100.0f },
	                    { -400.0f, -400.0f, -100.0f},
	                    { 400.0f, -400.0f, -100.0f }};
GLfloat LightPos[]={1.,1.,1.,0.};
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
	//glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
	//glEnable(GL_LIGHTING);
	glPushMatrix();
	DrawBox();	
	glDisable(GL_CULL_FACE);
	glNormal3f(0.,0.,1.);
    glBegin(GL_QUADS);
	  glVertex3f(-400.,400.,-100.);
	  glVertex3f(400.,400.,-100.);
	  glVertex3f(400.,-400.,-100.);
     glVertex3f(-400.,-400.,-100.);
  	glEnd();
	float a[16];
	glGetFloatv(GL_MODELVIEW_MATRIX,a);
    glLoadIdentity();
    glColor3f(0.,0.,0.);
    glMultMatrixf((GLfloat *)shadowMat);
	glMultMatrixf(a);
    DrawBox();
	glPopMatrix();
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
     
	 //glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);//使第0盞燈光生效
	 //glEnable(GL_NORMALIZE); //automatic normalization of normals
     //glEnable(GL_CULL_FACE);//不計算物體背面的情形
	 glCullFace(GL_BACK);
     //glShadeModel(GL_FLAT);
	 glShadeModel(GL_SMOOTH); //使物體本身的顏色能與燈光效果配合展現出來
	 glPolygonMode(GL_FRONT,GL_FILL);
	 //glPolygonMode(GL_FRONT,GL_LINE);
	 
   
	 //glGetFloatv(GL_MODELVIEW_MATRIX,(GLfloat*)shadowMat);
	 MakeShadowMatrix(points,LightPos,shadowMat);
	 wglMakeCurrent(NULL,NULL);
}

void CTestGLView::DrawBox()
{
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

// Creates a shadow projection matrix out of the plane equation
// coefficients and the position of the light. The return value is stored
// in destMat[][]
void CTestGLView::MakeShadowMatrix(GLfloat points[][3], GLfloat lightPos[], GLfloat destMat[][4])
{
 	GLfloat planeCoeff[4];
	GLfloat dot;

	// Find the plane equation coefficients
	// Find the first three coefficients the same way we
	// find a normal.
	calcNormal(points,planeCoeff);

	// Find the last coefficient by back substitutions
	planeCoeff[3] = - (
		(planeCoeff[0]*points[2][0]) + (planeCoeff[1]*points[2][1]) +
		(planeCoeff[2]*points[2][2]));


	// Dot product of plane and light position
	dot = planeCoeff[0] * lightPos[0] +
			planeCoeff[1] * lightPos[1] +
			planeCoeff[2] * lightPos[2] +
			planeCoeff[3] * lightPos[3];

	// Now do the projection
	// First column
    destMat[0][0] = dot - lightPos[0] * planeCoeff[0];
    destMat[1][0] = 0.0f - lightPos[0] * planeCoeff[1];
    destMat[2][0] = 0.0f - lightPos[0] * planeCoeff[2];
    destMat[3][0] = 0.0f - lightPos[0] * planeCoeff[3];

	// Second column
	destMat[0][1] = 0.0f - lightPos[1] * planeCoeff[0];
	destMat[1][1] = dot - lightPos[1] * planeCoeff[1];
	destMat[2][1] = 0.0f - lightPos[1] * planeCoeff[2];
	destMat[3][1] = 0.0f - lightPos[1] * planeCoeff[3];

	// Third Column
	destMat[0][2] = 0.0f - lightPos[2] * planeCoeff[0];
	destMat[1][2] = 0.0f - lightPos[2] * planeCoeff[1];
	destMat[2][2] = dot - lightPos[2] * planeCoeff[2];
	destMat[3][2] = 0.0f - lightPos[2] * planeCoeff[3];

	// Fourth Column
	destMat[0][3] = 0.0f - lightPos[3] * planeCoeff[0];
	destMat[1][3] = 0.0f - lightPos[3] * planeCoeff[1];
	destMat[2][3] = 0.0f - lightPos[3] * planeCoeff[2];
	destMat[3][3] = dot - lightPos[3] * planeCoeff[3];
}

// Points p1, p2, & p3 specified in counter clock-wise order
void CTestGLView::calcNormal(float v[][3], float out[])
{
	float v1[3],v2[3];
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;

	// Calculate two vectors from the three points
	v1[x] = v[0][x] - v[1][x];
	v1[y] = v[0][y] - v[1][y];
	v1[z] = v[0][z] - v[1][z];

	v2[x] = v[1][x] - v[2][x];
	v2[y] = v[1][y] - v[2][y];
	v2[z] = v[1][z] - v[2][z];

	// Take the cross product of the two vectors to get
	// the normal vector which will be stored in out
	out[x] = v1[y]*v2[z] - v1[z]*v2[y];
	out[y] = v1[z]*v2[x] - v1[x]*v2[z];
	out[z] = v1[x]*v2[y] - v1[y]*v2[x];

	// Normalize the vector (shorten length to one)
	ReduceToUnit(out);
}

// Reduces a normal vector specified as a set of three coordinates,
// to a unit normal vector of length one.
void CTestGLView::ReduceToUnit(float vector[])
{
	float length;
	
	// Calculate the length of the vector		
	length = (float)sqrt((vector[0]*vector[0]) + 
						(vector[1]*vector[1]) +
						(vector[2]*vector[2]));

	// Keep the program from blowing up by providing an exceptable
	// value for vectors that may calculated too close to zero.
	if (length == 0.0f)
	   length = 1.0f;

	// Dividing each element by the length will result in a
	// unit normal vector.
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}

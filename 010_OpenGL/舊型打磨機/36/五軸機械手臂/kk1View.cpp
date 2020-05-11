// kk1View.cpp : implementation of the CKk1View class
//

#include "stdafx.h"
#include "kk1.h"
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include <gl/glut.h>
#include "kk1Doc.h"
#include "kk1View.h"
////////////////////////////
#include "OpenGLFun.h"
#include "OpenGLPara.h"
#include "glmfc.h"
/////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
FILE *k;
FILE *k1;
FILE *l;
int Cx,Cy;
int jx=0,jy=0,jz=0,jt=0;
int y_base=0;
int x_main_hand=0;
int senser_Rotate=0;
/////////////////////////////////////////////////////////////////////////////
float Theta=0,PDX=0,PDY=0,PAX=0,PAY=0,DeltaT=0;
///////////////////////////////////////////
//接收
#define	MAP_NAME0	"spacesoft corp0."
#define	MAP_NAME1	"spacesoft corp1."
#define	MAP_NAME2	"spacesoft corp2."
#define	MAP_NAME3	"spacesoft corp3."
#define	MAP_NAME4	"spacesoft corp4."
#define	MAP_NAME5	"spacesoft corp5."
#define	MAP_LENGTH	16
HANDLE hFileMap0 = NULL ;
HANDLE hFileMap1 = NULL ;
HANDLE hFileMap2 = NULL ;
HANDLE hFileMap3 = NULL ;
HANDLE hFileMap4 = NULL ;
HANDLE hFileMap5 = NULL ;
static char szOldData[MAP_LENGTH] = "" ;
/////////////////////////////////////////////////////////////////////////////
//傳送
#define	MAP_NAME6	"spacesoft corp6."
#define	MAP_NAME7	"spacesoft corp7."
#define	MAP_NAME8	"spacesoft corp8."
#define	MAP_NAME9	"spacesoft corp9."
HANDLE hFileMap6 = NULL ;
HANDLE hFileMap7 = NULL ;
HANDLE hFileMap8 = NULL ;
HANDLE hFileMap9 = NULL ;
/////////////////////////////////////////////////////////////////////////////
//賦予平台生命變數
float X_offset=48;
float Y_offset=100;
float Z_offset=554;
float X_toffset=145;
float Y_toffset=575;
float Z_toffset=318;
float a1=205;
float d4=150;
float Theta_w0=0;
float Theta_w9=0;
/////////////////////////////////////////////////////////////////////////////
bool ontimer=false;//計數器旗標
bool map=false;//記憶體映射旗標
int next_number=0;
int next_break1=0;
/////////////////////////////////////////////////////////////////////////////
GLfloat life_x=0;//賦予平台生命變數
GLfloat life_y=0;
GLfloat life_z=0;
GLfloat life_r=0;


/////////////////////////////////////////////////////////////////////////////
int work_number=0;
/////////////////////////////////////////////////////////////////////////////
// CKk1View

IMPLEMENT_DYNCREATE(CKk1View, CScrollView)

BEGIN_MESSAGE_MAP(CKk1View, CScrollView)
	//{{AFX_MSG_MAP(CKk1View)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_COMMAND(ID_settimer, Onsettimer)
	ON_COMMAND(ID_Directly, OnDirectly)
	ON_COMMAND(ID_Flank, OnFlank)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKk1View construction/destruction

CKk1View::CKk1View()
{
	// TODO: add construction code here
	xRot=0;
	yRot=0;
	zRot=0;
}

CKk1View::~CKk1View()
{
}

BOOL CKk1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CKk1View drawing

void CKk1View::OnDraw(CDC* pDC)
{
	//MessageBox("OnDraw");
	m_pPal = NULL;
	CKk1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// select the palette
	//
	CPalette *	ppalOld	= NULL;
	if (m_pPal) {
		ppalOld	= pDC->SelectPalette(m_pPal, 0);
		pDC->RealizePalette();
	}
	BOOL	bResult	= wglMakeCurrent(pDC->m_hDC, m_hrc);
	if (FALSE == bResult)
		TRACE(_T("wglMakeCurrent() failed %x.\r\n"), ::GetLastError());
	
//	Rend();//原本打磨機程式

	opengl_Initial();	
//	opengl_disc();//圓盤底座
opengl_final();
//opengl_ServoMotor();
//	draw_child(dialog_set);
	glFlush();
	SwapBuffers(dc->m_hDC);
	if (ppalOld)
	pDC->SelectPalette(ppalOld, 0);
	wglMakeCurrent(NULL, NULL);
	// TODO: add draw code for native data here
}

void CKk1View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CKk1View printing

BOOL CKk1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKk1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKk1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CKk1View diagnostics

#ifdef _DEBUG
void CKk1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CKk1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CKk1Doc* CKk1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKk1Doc)));
	return (CKk1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKk1View message handlers

void CKk1View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CScrollView::OnMouseMove(nFlags, point);
}

void CKk1View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPen pen(PS_SOLID,3,RGB(255,255,0));
	cb=point;
	aDC->SelectObject(&pen);
	aDC->MoveTo(ca);
	aDC->LineTo(cb);
	ReleaseCapture();
	CScrollView::OnLButtonUp(nFlags, point);
}

void CKk1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	SetCapture();
	aDC=new CClientDC(this);
	ca=point;
	/*
	CString a,b;
	char k1[10];
	b="x=";
	_itoa(point.x ,k1,10);
	a=k1;
	b=b+a;
	_itoa(point.y,k1,10);
	a=k1;
	b=b+"y=";
	b=b+a;
	MessageBox(b);
	*/
	CScrollView::OnLButtonDown(nFlags, point);
}
void CKk1View::Rend()
{
	//CGrinderOpenGLDoc * pDoc = GetDocument();
	CKk1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////	
	//
	// enable depth calculations
	//
	glEnable(GL_DEPTH_TEST);		// Hidden surface removal
	glFrontFace(GL_CCW);			// Counter clock-wise polygons face out
	glDisable(GL_CULL_FACE);		// Do not calculate inside of jet
	glShadeModel(GL_SMOOTH);

	//
	// enable lighting calculations
	//	
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glEnable(GL_LIGHT0);
	
	//
	// set the material color to follow the current color
	//
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	// All materials hereafter have full specular reflectivity
	// with a high shine
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);	
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	//
	// clear the color and depth buffers
	//
	glClearColor(1.0f, 0.8f, 0.5f, 1.0f );	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

//////Draw Program Start/////////////////////////////////////////////////// 

	glLineWidth(1.5f);	// 線條大小

	if(Line_flag)
	//if(TRUE)
	{
		glPolygonMode(GL_FRONT_AND_BACK ,GL_LINE);
		glLineWidth(0.1f);	// 線條大小
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK ,GL_FILL);
		glLineWidth(0.1f);	// 線條大小
	}

	
	if(View_lock == FALSE)			// 判斷視角是否鎖定
	{
		if(View_flag == Up_View)			// 上視圖
		{
			xRot = yRot = zRot = 0.0f;
//			xView = yView  = 0.0f;
		}
		else if(View_flag == Front_View)	// 前視圖
		{
			xRot = -90.0f;
			yRot =	0.0f;
			zRot =	90.0f;
//			xView = yView =  0.0f;
		}
		else if(View_flag == Back_View)		// 後視圖
		{
			xRot = -90.0f;
			yRot =	0.0f;
			zRot = -90.0f;
//			xView = yView =  0.0f;
		}
		else if(View_flag == Right_View)	// 右視圖
		{
			xRot = -90.0f;
			zRot = 0.0f;
			yRot = 0.0f;
//			xView = yView =  0.0f;
		}
		else if(View_flag == Left_View)		// 左視圖
		{
			xRot = -90.0f;
			zRot = 180.0f;
			yRot = 0.0f;
//			xView = yView =  0.0f;
		}
		else if(View_flag == Orign_View)	// 立體圖
		{
			xRot = 285.0f;
			yRot = 0.0f;
			zRot = 50.0f;
//			xView = yView =  0.0f;
		}
	}
	glPushMatrix();
	{
		glTranslatef(xView, yView, zView);
		glRotatef(xRot, 1.0f, 0.0f, 0.0f);
		glRotatef(yRot, 0.0f, 1.0f, 0.0f);
		glRotatef(zRot, 0.0f, 0.0f, 1.0f);
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	{
		// 底座
		glTranslatef(Base_W/2, Base_L/2, Base_H/2);
		glColor3ub(96, 96, 96);
		drawRetc(Base_W, Base_L, Base_H);
		// 底座(完)
		glPushMatrix();
		{
			// X軸
			// 左
			glTranslatef(-Base_W/2+X_axis_W/2, -Base_L/2+X_axis_L/2, Base_H/2+X_axis_H/2);
			glColor3ub(128, 128, 200);
			drawRetc(X_axis_W, X_axis_L, X_axis_H);
			// 右
			glTranslatef(0.0f, -X_axis_L/2+2*Base_L/2-X_axis_L/2, 0.0f);
			glColor3ub(128, 128, 200);
			drawRetc(X_axis_W, X_axis_L, X_axis_H);
			// X軸(完)

			// Y軸
			glTranslatef(-X_axis_W/2+Y_axis_W/2+X_shift, X_axis_L/2-Y_axis_L/2, X_axis_H/2+Y_axis_H/2);
			glTranslatef(X_shift, 0.0f, 0.0f);			// X_shift Parameter
			glColor3ub(128, 128, 200);
			drawRetc(Y_axis_W, Y_axis_L, Y_axis_H);
			// Y軸(完)

			// Link1-1
			glTranslatef(0.0f, -Y_axis_L/2+Link11_L/2+Y_shift, Y_axis_H/2+Link11_H/2);
			glTranslatef(0.0f, Y_shift, 0.0f);			// Y_shift Parameter
			glColor3ub(128, 128, 200);
			drawRetc(Link11_W, Link11_L, Link11_H);
			// Link1-1(End)

			// Servo Motor 1
			glPushMatrix();
			{
				glTranslatef(-Y_axis_W/2-SM1_Bottom_W/2, 0.0f, -Link11_H/2+SM1_Bottom_H/2);
				glColor3ub(200, 128, 128);
				drawRetc(SM1_Bottom_W, SM1_Bottom_L, SM1_Bottom_H);

				glTranslatef(0.0f, 0.0f, SM1_Bottom_H/2+SM1_Middle_L/2);
				glColor3ub(96, 128, 96);
				drawCir(SM1_Middle_R, SM1_Middle_L, 16);

				glTranslatef(0.0f, 0.0f, SM1_Middle_L/2+SM1_Top_L/2);
				glColor3ub(96, 128, 200);
				drawCir(SM1_Top_R, SM1_Top_L, 16);

			}
			glPopMatrix();
			// Servo Motor 1(End)
			
			// Bar1-1
			glTranslatef(0.0f, 0.0f, Link11_H/2+Bar11_L/2);
			glRotatef(Rotate1, 0.0f, 0.0f, 1.0f);		// Rotate1 Parameter
			glColor3ub(128, 30, 56);
			drawCir(Bar11_R, Bar11_L, 16);
			// Bar1-1(End)

			// Link1-2
			glTranslatef(0.0f, 0.0f, Bar11_L/2+Link12_H/2);
			glColor3ub(200, 100, 200);
			drawRetc(Link12_W, Link12_L, Link12_H);
			// Link1-2(End)
			
			// Bar1-2
			glTranslatef(0.0f, -Link12_L/2-Bar12_L/2, 0.0f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glRotatef(Rotate2, 0.0, 0.0f, 1.0f);		// Rotate2 Parameter
			glColor3ub(98, 16, 200);
			drawCir(Bar12_R, Bar12_L, 16);
			glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
			// Bar1-2(End)

			// Link2
			glTranslatef(Link2_W/2, -Bar12_L/2+Link2_L/2-0.1f, 0.0f);
			glColor3ub(128, 128, 200);
			drawRetc(Link2_W, Link2_L, Link2_H);
			// Link2(完)

			// Loadcell
			glTranslatef(Link2_W/2+Loadcell1_L/2, 0.0f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glRotatef(Rotate3, 0.0f, 0.0f, 1.0f);		// Rotate3 Parameter
			glColor3ub(128, 64, 64);
			drawCir(Loadcell1_R, Loadcell1_L, 16);
			glTranslatef(0.0f, 0.0f, Loadcell1_L/2+Loadcell2_L/2);
			glColor3ub(156, 64, 64);
			drawCir(Loadcell2_R, Loadcell2_L, 16);
			// Loadcell(完)
			
			// Fixture
			glTranslatef(0.0f, 0.0f, Loadcell2_L/2+Fixture1_L/2);
			glColor3ub(128, 128, 128);
			drawCir(Fixture1_R, Fixture1_L, 16);
			glTranslatef(0.0f, 0.0f, Fixture1_L/2+Fixture2_L/2);
			glColor3ub(128, 128, 128);
			drawCir(Fixture2_R, Fixture2_L, 16);
			// Fixture(完)

			glTranslatef(0.0f, 0.0f, Fixture2_L/2+Watch1_1_H/2);
			glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
///*刪除表框起始位置
			// Watch Model
			// Watch1_1 左
			glPushMatrix();
			{
				glTranslatef(Watch1_2_W/2+Watch1_1_W/2,0.0f,  0.0f);
				glColor3ub(96, 96, 96);
				drawRetc(Watch1_1_W, Watch1_1_L, Watch1_1_H);
			}	
			glPopMatrix();
			// Watch1_1 左(End)
			// Watch1_1 右
			glPushMatrix();
			{
				glTranslatef(-(Watch1_2_W/2+Watch1_1_W/2), 0.0f, 0.0f);
				glColor3ub(96, 96, 96);
				drawRetc(Watch1_1_W, Watch1_1_L, Watch1_1_H);
			}	
			glPopMatrix();
			// Watch1_1 右(End)
			// Watch1_2 上
			glPushMatrix();
			{
				glTranslatef(0.0f, Watch1_1_L/2-Watch1_2_L/2, 0.0f);
				glColor3ub(96, 96, 96);
				drawRetc(Watch1_2_W, Watch1_2_L, Watch1_2_H);
			}
			glPopMatrix();
			// Watch1_2 上(End)
			// Watch1_2 下
			glPushMatrix();
			{
				glTranslatef( 0.0f, -(Watch1_1_L/2-Watch1_2_L/2),0.0f);
				glColor3ub(96, 96, 96);
				drawRetc(Watch1_2_W, Watch1_2_L, Watch1_2_H);
			}
			glPopMatrix();
			// Watch1_2 下(End)
			// Watch Model(End)
//*/刪除表框結束位置	
		}
		glPopMatrix();

		// 砂輪機底座
		// 底座Base
		glTranslatef(Base_W/2+GrinderHold_Base_W/2, 0.0f, -Base_H/2+GrinderHold_Base_H/2);
		glColor3ub(68, 68, 68);
		drawRetc(GrinderHold_Base_W, GrinderHold_Base_L, GrinderHold_Base_H);
		// 底座Base(完)
		// Base1 左
		glPushMatrix();
		{
			glTranslatef(0.0f, GrinderHold_Base_L/2-GrinderHold1_R, GrinderHold_Base_H/2);
			glRotatef(-90, 0.0f, 1.0f, 0.0f);
			glColor3ub(68, 68, 68);
			drawCir(GrinderHold1_R, GrinderHold1_L, 16);
		}
		glPopMatrix();
		// Base1 左(完)
		// Base1 右
		glPushMatrix();
		{
			glTranslatef(0.0f, -GrinderHold_Base_L/2+ GrinderHold1_R, GrinderHold_Base_H/2);
			glRotatef(-90, 0.0f, 1.0f, 0.0f);
			glColor3ub(68, 68, 68);
			drawCir(GrinderHold1_R, GrinderHold1_L, 16);
		}
		glPopMatrix();
		// Base1 右(完)
		// Base 上
		glPushMatrix();
		{
			glTranslatef(0.0f, 0.0f, GrinderHold_Base_H/2+GrinderHold2_H/2);
			glColor3ub(68, 68, 68);
			drawRetc(GrinderHold2_W, GrinderHold2_L, GrinderHold2_H);
		}
		glPopMatrix();
		// Base 上(完)
		// 砂輪機底座(完)
		
		// 砂輪
		glTranslatef(GrinderHold_Base_W/2, -GrinderHold_Base_L/2+GrinderHold1_R+Grinder_init_shift, GrinderHold_Base_H/2);
		glPushMatrix();
		{
			// 砂輪1
			glPushMatrix();
			{
				glTranslatef(-Grinder_Bar_L/2, 0.0f, 0.0f);
				glRotatef(-90, 0.0f, 1.0f, 0.0f);
				glRotatef(Grinder_Rotate, 0.0f, 0.0f, 1.0f);
				glColor3ub(28, 28, 28);
				drawCir(Grinder_Bar_R, Grinder_Bar_L, 16);
				
				glTranslatef(0.0f, 0.0f, Grinder_Bar_L/2-Grinder_L/2);
				glColor3ub(128, 64, 64);
				drawCir(Grinder_R, Grinder_L, 32);
				glRotatef(90, 0.0f, 1.0f, 0.0f);
			}
			glPopMatrix();
			// 砂輪1(End)
			// 砂輪2
			glPushMatrix();
			{
				glTranslatef(-(Grinder_Bar_L+Grinder_Distance)/2, Grinder_Bar_Distance, 0.0f);
				glRotatef(-90, 0.0f, 1.0f, 0.0f);
				glRotatef(Grinder_Rotate, 0.0f, 0.0f, 1.0f);
				glColor3ub(28, 28, 28);
				drawCir(Grinder_Bar_R, Grinder_Bar_L+Grinder_Distance, 16);
				
				glTranslatef(0.0f, 0.0f, (Grinder_Bar_L+Grinder_Distance)/2-Grinder_L/2);
				glColor3ub(200, 200, 200);
				drawCir(Grinder_R, Grinder_L, 32);
				glRotatef(90, 0.0f, 1.0f, 0.0f);
			}
			glPopMatrix();
			// 砂輪2(End)
			// 砂輪3
			glPushMatrix();
			{
				glTranslatef(-(Grinder_Bar_L+2*Grinder_Distance)/2, 2*Grinder_Bar_Distance, 0.0f);
				glRotatef(-90, 0.0f, 1.0f, 0.0f);
				glRotatef(Grinder_Rotate, 0.0f, 0.0f, 1.0f);
				glColor3ub(28, 28, 28);
				drawCir(Grinder_Bar_R, Grinder_Bar_L+2*Grinder_Distance, 16);
				
				glTranslatef(0.0f, 0.0f, (Grinder_Bar_L+2*Grinder_Distance)/2-Grinder_L/2);
				glColor3ub(128, 200, 64);
				drawCir(Grinder_R, Grinder_L, 32);
				glRotatef(90, 0.0f, 1.0f, 0.0f);
			}
			glPopMatrix();
			// 砂輪3(End)
		}
		glPopMatrix();
	}
	glPopMatrix();
	}
	glPopMatrix();
//////Draw Program End/////////////////////////////////////////////////////
	//
	// flush the drawing pipeline
	//
	//glFlush();
	//SwapBuffers(dc->m_hDC);

}

int CKk1View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
//	CClientDC		dc(this);
	dc = new CClientDC (this);
	PIXELFORMATDESCRIPTOR	pfd;

	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.cColorBits	= 24;
	pfd.cDepthBits	= 32;
	pfd.dwFlags	= PFD_DOUBLEBUFFER | PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	pfd.iLayerType	= PFD_MAIN_PLANE;
	pfd.iPixelType	= PFD_TYPE_RGBA;
	pfd.nSize	= sizeof(PIXELFORMATDESCRIPTOR); 
	pfd.nVersion	= 1;

	int	nPixelFormat	= ChoosePixelFormat(dc->m_hDC, &pfd);
	if (0 == nPixelFormat) {
		TRACE(_T("ChoosePixelFormat() failed %d.\r\n"), GetLastError());
		return -1;
	}
	TRACE(_T("pixel format %d.\r\n"), nPixelFormat);
	
	BOOL	bResult	= SetPixelFormat(dc->m_hDC, nPixelFormat, &pfd);
	if (FALSE == bResult) {
		TRACE(_T("SetPixelFormat() failed %d.\r\n"),GetLastError());
		return -1;
	}

	//
	// create a rendering context
	//
	m_hrc	= wglCreateContext(dc->m_hDC);
	if (NULL == m_hrc) {
		TRACE(_T("wglCreateContext() failed %x.\r\n"), GetLastError());
		return -1;
	}
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	//
	// create the palette
	//
	CreateRGBPalette(dc->m_hDC, m_pPal);
	k=fopen("k.txt","w");
	// TODO: Add your specialized creation code here
	hFileMap6 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME6 ) ;
	hFileMap7 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME7 ) ;
	hFileMap8 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME8 ) ;
	hFileMap9 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME9 ) ;
	return 0;
}

void CKk1View::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);	
	if ((cx <= 0) || (cy <= 0))
		return;
//設定Open_Gl畫布	
//	CClientDC	dc(this);

	//
	// make the rendering context m_hrc current
	//
	Cx=cx;
	Cy=cy;
	BOOL	bResult = wglMakeCurrent(dc->m_hDC, m_hrc);
	if (FALSE == bResult) {
		TRACE(_T("wglMakeCurrent() failed %x.\r\n"), GetLastError());
		return;
	}
	
	int w = cx;
	int h = cy;
	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	// Set Viewport to window dimensions
    glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
    if (w <= h) 
		glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2, nRange*2);
    else 
		glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2, nRange*2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	wglMakeCurrent(NULL, NULL);
	// TODO: Add your message handler code here
	
}
void CKk1View::Update(int x,int y,int pitch,int yaw,int row,int sw)
{
	if(y_base<189)
	{
		y_base+=x;
	}
	else
	{
		senser_Rotate+=10;
		y_base=189;	
	}
/*
	switch(sw)
	{
	case 1:
		if(X_shift<100)
		{
			X_shift+= x;
		}
		else
		{
			X_shift=100;
		}
		if(Y_shift<110)
		{
			Y_shift+=y;
		}
		else
		{
			Y_shift=110;
		}
		Rotate1=0;
		Rotate2=0;
		Rotate3+=row;

		break;
	case 2:
		X_shift=x;
		Y_shift=y;
		Rotate1=pitch;
		Rotate2=yaw;
		Rotate3=row;
		break;
	}
//	Rotate1+=yaw;
//	Rotate2+=pitch;
//	Rotate3+=row;
*/

	Invalidate(true);
}
void CKk1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case VK_NUMPAD5:
		Line_Side=!Line_Side;
		break;
	case VK_NUMPAD2:
		//MessageBox("2");
		View_lock = TRUE;
		xRot += 5.0f;
		break;
	case VK_NUMPAD4:

		View_lock = TRUE;		
		yRot -= 5.0f;
		break;
	case VK_NUMPAD6:

		View_lock = TRUE;
		yRot += 5.0f;
		break;
	case VK_NUMPAD7:

		View_lock = TRUE;
		zRot -= 5.0f;
		break;
	case VK_NUMPAD8:

		View_lock = TRUE;
		xRot-= 5.0f;
		break;
	case VK_NUMPAD9:

		View_lock = TRUE;
		zRot += 5.0f;
		break;
	case VK_F1:
		//View_lock = FALSE;
		xRot=0;
		yRot=0;
		zRot=0;
		jx=0;
		jy=0;
		jz=0;
		break;
	case VK_F2:
		//View_lock = FALSE;
		//jx=30;
		//jy=100;
		xRot=-90;
		yRot=0;
		zRot=0;
		jx=0;
		jy=0;
		jz=0;
		break;
	case VK_F3:
		//View_lock = FALSE;
		//jx=30;
		//jy=170;
		xRot=-90;
		yRot=0;
		zRot=90;
		jx=0;
		jy=0;
		jz=0;
		break;
	case VK_F4:
		//View_lock = FALSE;
		//jx=30;
		//jy=270;
		xRot=-90;
		yRot=0;
		zRot=-90;
		jx=0;
		jy=0;
		jz=0;
		break;
	case VK_F5:

		break;
	case VK_F6:
		View_lock = FALSE;

		break;
	/////////////////////////
	case VK_F7://x
		View_lock = TRUE;
		senser_Rotate+=10;
		break;
	case VK_F8://y
		View_lock = TRUE;

		x_main_hand+=10;
		break;
	case VK_F9://yaw
		View_lock = TRUE;

		jz++;
		break;
	case VK_F12://pitch
		View_lock = TRUE;
		jy+=1;

		break;
	case VK_F11://row
		View_lock = TRUE;

		jx+=1;
		break;
	}
	Invalidate(true);
	
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}
BOOL CKk1View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
		return TRUE;
}
void CKk1View::draw_child(int IntSwitch)
{
	//逆時鍾矩形
	////////////////////////////////
	glPushMatrix();
	{
	glColor3f(10.0f,0.0f,0.0f);
	glLineWidth(1.0);

	glBegin(GL_LINES);
	glVertex3f(600,0,0);//左下
	glVertex3f(600,300,0);//左上
	glEnd();
		
	glBegin(GL_LINES);
	glVertex3f(600,0,0);//左下
	glVertex3f(1000,0,0);//右下
	glEnd();
	
	glBegin(GL_LINES);
	glVertex3f(1000,0,0);//右下
	glVertex3f(1000,300,0);//右上
	glEnd();
	
	glBegin(GL_LINES);
	glVertex3f(1000,300,0);//右下
	glVertex3f(600,300,0);//右上
	glEnd();
	}
	glPopMatrix();
	switch(IntSwitch)
	{
	case 1:
	glColor3f(32.0f,253.0f,253.0f);
	draw_child1();
	glColor3f(0.0f,0.0f,0.0f);
	draw_child2();
	draw_child3();
	draw_child4();
	break;
	case 2:
	glColor3f(32.0f,253.0f,253.0f);
	draw_child2();
	glColor3f(0.0f,0.0f,0.0f);
	draw_child1();
	draw_child3();
	draw_child4();
	break;
	case 3:
	glColor3f(32.0f,253.0f,253.0f);
	draw_child3();
	glColor3f(0.0f,0.0f,0.0f);
	draw_child1();
	draw_child2();
	draw_child4();
	break;
	case 4:
	glColor3f(32.0f,253.0f,253.0f);
	draw_child4();
	glColor3f(0.0f,0.0f,0.0f);
	draw_child1();
	draw_child2();
	draw_child3();
	break;
	default:
	glColor3f(0.0f,0.0f,0.0f);
	draw_child4();
	draw_child1();
	draw_child2();
	draw_child3();
	}

}
void CKk1View::draw_child1(void)//左
{
	glPushMatrix();
	{
	//glColor3f(188.0f,0.0f,200.0f);
	glBegin(GL_QUADS);
	glVertex3f(700,30,0);//左下
	glVertex3f(700,270,0);//左上
	glVertex3f(740,270,0);//右上
	glVertex3f(740,30,0);//右下
	glEnd();
	}
	glPopMatrix();
}
void CKk1View::draw_child2(void)//上
{
	glPushMatrix();
	{
	//glColor3f(0.0f,0.0f,10.0f);
	glBegin(GL_QUADS);
	glVertex3f(740,210,0);//左下
	glVertex3f(740,250,0);//左上
	glVertex3f(890,250,0);//右上
	glVertex3f(890,210,0);//右下
	glEnd();
	}
	glPopMatrix();

}
void CKk1View::draw_child3(void)//右
{
	glPushMatrix();
	{
	//glColor3f(10.0f,0.0f,10.0f);
	glBegin(GL_QUADS);
	glVertex3f(890,30,0);//左下
	glVertex3f(890,270,0);//左上
	glVertex3f(930,270,0);//右上
	glVertex3f(930,30,0);//右下
	glEnd();
	}
	glPopMatrix();
}
void CKk1View::draw_child4(void)//下
{
	glPushMatrix();
	{
	//glColor3f(10.0f,10.0f,0.0f);
	glBegin(GL_QUADS);
	glVertex3f(740,50,0);//左下
	glVertex3f(740,90,0);//左上
	glVertex3f(890,90,0);//右上
	glVertex3f(890,50,0);//右下
	glEnd();
	}
	glPopMatrix();
}
void CKk1View::opengl_Initial(void)
{

	glEnable(GL_DEPTH_TEST);		// Hidden surface removal
	glFrontFace(GL_CCW);			// Counter clock-wise polygons face out
	glDisable(GL_CULL_FACE);		// Do not calculate inside of jet
	glShadeModel(GL_SMOOTH);


	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glEnable(GL_LIGHT0);
	
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);	
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	glClearColor(1.0f, 0.8f, 0.5f, 1.0f );	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
void CKk1View::opengl_disc(void)//jash_liao writes main programe of open gl
{
	int Cir_R,Cir_L,x_w,x_l,x_h,y_w,y_l,y_h;
			//打模機start
			glPushMatrix();
			{

				
				glRotatef(-45-jx, 1.0f, 0.0f, 0.0f);
				glRotatef(0-jy, 0.0f, 0.0f, 1.0f);

				//砂輪start
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glColor3ub(128, 0, 0);
				glTranslatef(250,250,-500);//左 上 前
				drawCir(100, 20, 1000);
				glTranslatef(0,0,-9);
				glColor3ub(128, 0, 120);
				drawCir(15, 40, 1000);
				glTranslatef(-250,-250,500);
				glRotatef(-90, 1.0f, 0.0f, 0.0f);
				//砂輪end
				
				//圓盤底座start
				glColor3ub(128, 64, 64);
					//drawCir(Grinder_R+300, Grinder_L+50, 1000);
				drawCir(500, Grinder_L+50, 1000);
				//圓盤底座end
				//機器手臂start
				glPushMatrix();
				{
					
					//儲存圓盤底座的半徑與厚度,/2的原因是因要使每個元件貼合之技巧
						//Cir_R=(Grinder_R+300)/2;
					Cir_R=500/2;
					Cir_L=(Grinder_L+50)/2;
					
					///////////////////////////////////////////////////////
					
					//X軸start
					//設定X軸的長度,寬度,高度
					x_w=140;//y
					x_l=400;//x
					x_h=40;//z
					//設定X軸安裝位置x=0,y=250,z=圓盤厚度的一半加上X軸厚度的一半
					glTranslatef(0.0f, 250.0f,+Cir_L+x_h/2);
					//設定X軸顏色
					glColor3ub(200, 128, 128);
					//畫出X軸
					drawRetc(x_w, x_l, x_h);
					//X軸end

					//////////////////////////////////////////////////////////
					
					//y軸start	
					//已知y軸的h=62,w=96,l=201
					//設定y軸安裝位置x=X軸的中心點,y=(-X軸的y軸一半)(ps因為要移到原點,所以取負號)加上(y軸的y軸一半),z=(y軸厚度的一半)加上(X軸厚度的一半)
					//在這裡只要把y軸加上一個正數就可以達到其移動之效果
					y_h=62;//z
					y_w=201;//x
					y_l=96;//y
					glTranslatef(0, x_l/-2+y_l/2 ,(x_h/2+y_h/2));
					glTranslatef(0,y_base,0);
					//設定y軸顏色
					glColor3ub(0, 128, 128);
					//畫出Y軸
					drawRetc(y_w, y_l, y_h);
					//y軸end

					//////////////////////////////////////////////////////////
					//z軸start
					glTranslatef(-y_l/2, 0 ,y_h/2+96/8);
					/////////////////////////////////////////////////////////
					//servomoter start
					//base start
					glColor3ub(200, 128, 128);
					drawRetc(96, 96, 24);
					//base end
					//body start
					glTranslatef(0.0f, 0.0f, SM1_Bottom_H/2+SM1_Middle_L/2);
					glColor3ub(96, 128, 96);
					drawCir(43, 96, 16);
					//body end
					//head1 start
					glTranslatef(0.0f, 0.0f, 96/2+SM1_Top_L/2);
					glColor3ub(96, 128, 200);
					drawCir(30,20,16);
					//head1 end
					//head2 start
					glTranslatef(0.0f, 0.0f, 20/2+10/2);
					glColor3ub(96, 128, 0);
					drawCir(50,10,16);
					//head2 end
					//servomoter end
					////////////////////////////////////////////////////////
					//減速機 start
					glTranslatef(y_l/2, 0 ,(y_h/2+96/8)*-1);//移回y軸中心
					glTranslatef(y_l/2, 0 ,(y_h/2+20/2)*-2);//移到y軸右邊
					glRotatef(90, 0.0f, 1.0f, 0.0f);
					glColor3ub(200, 0, 128);
					drawRetc(30, 76, 76);

					glTranslatef((30/2+50/2)*-1, 0 ,0);//移到y軸右邊
					glColor3ub(5, 5, 128);
					drawRetc(50, 60, 60);

					glTranslatef((50/2+50/2)*-1, 0 ,0);//移到y軸右邊
					glColor3ub(200, 128,0 );
					drawRetc(50, 76, 76);
					//減速機 end
					//////////////////////////////////////////////////////
					//主手臂y軸
					glRotatef(-90, 0.0f, 1.0f, 0.0f);
					glTranslatef(-40, 0 ,(50/2+90/2));//移到y軸右邊
					glColor3ub(200, 0,0 );
					drawRetc(210, 90, 54);
					//////////////////////////////////////////////////////
					//連接主手臂連桿1(小圓柱)
					glTranslatef((210/2+30/2), 0 ,0);//移到y軸右邊
					glRotatef(-90, 0.0f, 1.0f, 0.0f);
					glColor3ub(200,50,150 );
					drawCir(25,30,16);
					//////////////////////////////////////////////////////
					//連接主手臂連桿2(大圓盤)
					glTranslatef(0, 0 ,(30/2+20/2)*-1);//移到y軸右邊
					glColor3ub(200,150,50 );
					drawCir(30,20,16);
					/////////////////////////////////////////////////////
					//主手臂X軸
					glRotatef(-90+x_main_hand, 0.0f, 0.0f, 1.0f);//修改z軸角度就可以旋轉
					glTranslatef(0, 0 ,(60/2+20/2)*-1);//移到y軸右邊
					glColor3ub(100,150,50 );
					drawRetc(124, 60, 60);
					////////////////////////////////////////////////////
					//感測器 start
					glTranslatef((124/2+14.75/2)*-1, 0 ,0);
					glRotatef(-90, 0.0f, 1.0f, 0.0f);
					glRotatef(senser_Rotate, 0.0f, 0.0f, 1.0f);
					
					glColor3ub(200,50,150 );
					drawCir(10,14.75,16);
					
					glTranslatef(0, 0 ,(5/2+14.75/2));
					glColor3ub(50,0,255 );
					drawCir(32,5,16);
					
					glRotatef(90, 0.0f, 1.0f, 0.0f);
					glTranslatef((30/2+14.8/2)*-1, 0 ,0);
					
					glColor3ub(128,25,25 );
					drawRetc(30, 26, 20);

					////////////////////////////////////////////////
					//load ceal start
						glTranslatef(15, 0 ,0);//移到y軸右邊
						glColor3ub(128,250,25 );
						drawRetc(15, 60, 10);//寬,長,厚度//20

						glTranslatef((5/2+15/2)*-1, (30-20/2) ,0);
						drawRetc(5, 20, 10);//寬,長,厚度

						glTranslatef((24.5/2+5/2)*-1, (60/2-20/2)*-1 ,0);
						drawRetc(24.5, 60, 10);//寬,長,厚度

						glTranslatef((5/2+24.5/2)*-1, (60/2-20/2)*-1,0);
						drawRetc(5, 20, 10);//寬,長,厚度
						glTranslatef((15/2)*-1, (60/2-20/2),0);
						glColor3ub(128,250,25 );
						drawRetc(15, 60, 10);//寬,長,厚度
					//load ceal end
					////////////////////////////////////////////////
						
						glTranslatef(0, 0,0);
						glColor3ub(128,25,25 );
						drawRetc(21, 40, 20);
						
						glTranslatef((5/2+21/2)*-1, 0,0);
						glRotatef(-90, 0.0f, 1.0f, 0.0f);
						glColor3ub(50,0,255 );
						drawCir(32,5,16);
					////////////////////////////////////////////
						//夾具start
						glTranslatef(0,0,(5/2+6/2)*1);
						//glRotatef(-90, 0.0f, 1.0f, 0.0f);
						glColor3ub(50,0,25 );
						drawCir(25,6,16);
						glTranslatef(0,0,(5/2+31.1/2)*1);
						//glRotatef(-90, 0.0f, 1.0f, 0.0f);
						glColor3ub(50,255,25 );
						drawCir(21,31.1,16);
						//夾具end
					///////////////////////////////////////////
						//表框start
						glTranslatef(15,0,(8/2+31.5/2));//左邊
						glColor3ub(255,255,255 );
						drawRetc(10, 50, 8);
						glTranslatef(-15*2,0,0);//右邊
						drawRetc(10, 50, 8);
						glTranslatef(15,15,0);//上面
						glRotatef(-90, 0.0f, 0.0f, 1.0f);
						drawRetc(10, 40, 8);
						glTranslatef(15*2,0,0);//下面
						drawRetc(10, 40, 8);
						//表框end
					////////////////////////////////////////

						
				}
				glPopMatrix();

				//機器手臂end
				//glRotatef(90, 0.0f, 1.0f, 0.0f);
			}
			glPopMatrix();
			//打模機end
}
void CKk1View::opengl_ServoMotor(void)
{
		glPushMatrix();
		{
		glTranslatef(0, 1400, 0);
		yRot=-90;//因為主畫面有旋轉一個角度,所以要補償
		glRotatef(yRot, 0.0f, 1.0f, 0.0f);
				// opengl_ServoMotor 1
			glPushMatrix();
			{
				
				glTranslatef(-Y_axis_W/2-SM1_Bottom_W/2, 0.0f, -Link11_H/2+SM1_Bottom_H/2);
				glColor3ub(200, 128, 128);
				drawRetc(SM1_Bottom_W, SM1_Bottom_L, SM1_Bottom_H);

				glTranslatef(0.0f, 0.0f, SM1_Bottom_H/2+SM1_Middle_L/2);
				glColor3ub(96, 128, 96);
				drawCir(SM1_Middle_R, SM1_Middle_L, 16);

				glTranslatef(0.0f, 0.0f, SM1_Middle_L/2+SM1_Top_L/2);
				glColor3ub(96, 128, 200);
				drawCir(SM1_Top_R, SM1_Top_L, 16);

				

			}
			glPopMatrix();
		}
		glPopMatrix();
			// Servo Motor 1(End)

}
void CKk1View::robot(void)
{
		glPushMatrix();
		{	
			// X軸
			// 左
			glTranslatef(-Base_W/2+X_axis_W/2, -Base_L/2+X_axis_L/2, Base_H/2+X_axis_H/2);
			glColor3ub(128, 128, 200);
			drawRetc(X_axis_W, X_axis_L, X_axis_H);
			// 右
			glTranslatef(0.0f, -X_axis_L/2+2*Base_L/2-X_axis_L/2, 0.0f);
			glColor3ub(128, 128, 200);
			drawRetc(X_axis_W, X_axis_L, X_axis_H);
			// X軸(完)
			
			// Y軸
			glTranslatef(-X_axis_W/2+Y_axis_W/2+X_shift, X_axis_L/2-Y_axis_L/2, X_axis_H/2+Y_axis_H/2);
			glTranslatef(X_shift, 0.0f, 0.0f);			// X_shift Parameter
			glColor3ub(128, 128, 200);
			drawRetc(Y_axis_W, Y_axis_L, Y_axis_H);
			// Y軸(完)
			
			// Link1-1
			glTranslatef(0.0f, -Y_axis_L/2+Link11_L/2+Y_shift, Y_axis_H/2+Link11_H/2);
			glTranslatef(0.0f, Y_shift, 0.0f);			// Y_shift Parameter
			glColor3ub(128, 128, 200);
			drawRetc(Link11_W, Link11_L, Link11_H);
			// Link1-1(End)

			// Servo Motor 1
			glPushMatrix();
			{
				glTranslatef(-Y_axis_W/2-SM1_Bottom_W/2, 0.0f, -Link11_H/2+SM1_Bottom_H/2);
				glColor3ub(200, 128, 128);
				drawRetc(SM1_Bottom_W, SM1_Bottom_L, SM1_Bottom_H);

				glTranslatef(0.0f, 0.0f, SM1_Bottom_H/2+SM1_Middle_L/2);
				glColor3ub(96, 128, 96);
				drawCir(SM1_Middle_R, SM1_Middle_L, 16);

				glTranslatef(0.0f, 0.0f, SM1_Middle_L/2+SM1_Top_L/2);
				glColor3ub(96, 128, 200);
				drawCir(SM1_Top_R, SM1_Top_L, 16);

			}
			glPopMatrix();
			// Servo Motor 1(End)
			
			// Bar1-1
			glTranslatef(0.0f, 0.0f, Link11_H/2+Bar11_L/2);
			glRotatef(Rotate1, 0.0f, 0.0f, 1.0f);		// Rotate1 Parameter
			glColor3ub(128, 30, 56);
			drawCir(Bar11_R, Bar11_L, 16);
			// Bar1-1(End)
			
			// Link1-2
			glTranslatef(0.0f, 0.0f, Bar11_L/2+Link12_H/2);
			glColor3ub(200, 100, 200);
			drawRetc(Link12_W, Link12_L, Link12_H);
			// Link1-2(End)
			
			// Bar1-2
			glTranslatef(0.0f, -Link12_L/2-Bar12_L/2, 0.0f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glRotatef(Rotate2, 0.0, 0.0f, 1.0f);		// Rotate2 Parameter
			glColor3ub(98, 16, 200);
			drawCir(Bar12_R, Bar12_L, 16);
			glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
			// Bar1-2(End)

			// Link2
			glTranslatef(Link2_W/2, -Bar12_L/2+Link2_L/2-0.1f, 0.0f);
			glColor3ub(128, 128, 200);
			drawRetc(Link2_W, Link2_L, Link2_H);
			// Link2(完)

			// Loadcell
			glTranslatef(Link2_W/2+Loadcell1_L/2, 0.0f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glRotatef(Rotate3, 0.0f, 0.0f, 1.0f);		// Rotate3 Parameter
			glColor3ub(128, 64, 64);
			drawCir(Loadcell1_R, Loadcell1_L, 16);
			glTranslatef(0.0f, 0.0f, Loadcell1_L/2+Loadcell2_L/2);
			glColor3ub(156, 64, 64);
			drawCir(Loadcell2_R, Loadcell2_L, 16);
			// Loadcell(完)
			
			// Fixture
			glTranslatef(0.0f, 0.0f, Loadcell2_L/2+Fixture1_L/2);
			glColor3ub(128, 128, 128);
			drawCir(Fixture1_R, Fixture1_L, 16);
			glTranslatef(0.0f, 0.0f, Fixture1_L/2+Fixture2_L/2);
			glColor3ub(128, 128, 128);
			drawCir(Fixture2_R, Fixture2_L, 16);
			// Fixture(完)

			glTranslatef(0.0f, 0.0f, Fixture2_L/2+Watch1_1_H/2);
			glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
///*刪除表框起始位置
			// Watch Model
			// Watch1_1 左
			glPushMatrix();
			{
				glTranslatef(Watch1_2_W/2+Watch1_1_W/2,0.0f,  0.0f);
				glColor3ub(96, 96, 96);
				drawRetc(Watch1_1_W, Watch1_1_L, Watch1_1_H);
			}	
			glPopMatrix();
			// Watch1_1 左(End)
			// Watch1_1 右
			glPushMatrix();
			{
				glTranslatef(-(Watch1_2_W/2+Watch1_1_W/2), 0.0f, 0.0f);
				glColor3ub(96, 96, 96);
				drawRetc(Watch1_1_W, Watch1_1_L, Watch1_1_H);
			}	
			glPopMatrix();
			// Watch1_1 右(End)
			// Watch1_2 上
			glPushMatrix();
			{
				glTranslatef(0.0f, Watch1_1_L/2-Watch1_2_L/2, 0.0f);
				glColor3ub(96, 96, 96);
				drawRetc(Watch1_2_W, Watch1_2_L, Watch1_2_H);
			}
			glPopMatrix();
			// Watch1_2 上(End)
			// Watch1_2 下
			glPushMatrix();
			{
				glTranslatef( 0.0f, -(Watch1_1_L/2-Watch1_2_L/2),0.0f);
				glColor3ub(96, 96, 96);
				drawRetc(Watch1_2_W, Watch1_2_L, Watch1_2_H);
			}
			glPopMatrix();
			// Watch1_2 下(End)
			// Watch Model(End)
//*/刪除表框結束位置	
		}
		glPopMatrix();
}
void CKk1View::opengl_final(void)
{
	int base_h=50,base_l1=400,base_w1=500/*400*/,base_l2=200,base_w2=300;
	int base_triangle=100;
	int base_watch_h1=200,base_watch_w1=200,base_watch_l1=250;
	int x,y,iPivot;
	int track_h=20,track_w=20,track_l=400;//基座的軌道
	int track_h1=10,track_w1=20,track_l1=200;///滑軌
	int platform_w1=500,platform_l1=200,platform_h1=32;///平台1
	int track_h2=10,track_w2=20,track_l2=500;//滑軌2
	int platform_w2=200,platform_l2=200,platform_h2=32;////平台2
	int base_vertical_h2=50,base_vertical_w2=500,base_vertical_l2=200;//垂直底座
	int track_vertical_h=10,track_vertical_w=500,track_vertical_l=20;//垂直底座滑軌
	int track_vertical_h1=32,track_vertical_w1=200,track_vertical_l1=200;//垂直滑軌上的移動平台
	int base_emery_w1=100,base_emery_l1=150,base_emery_h1=20,base_emery_w2=150,base_emery_l2=60,base_emery_h2=20;//沙輪機底板
	//////////////////////////////////////////////////////////////////伺服馬達
	int ServoMotor_Cir1=43,ServoMotor_Cir2=20,ServoMotor_Cir3=16;
	int ServoMotor_Retc11=66,ServoMotor_Retc12=66,ServoMotor_Retc13=50;
	int ServoMotor_Retc21=68,ServoMotor_Retc22=68,ServoMotor_Retc23=40;
	//////////////////////////////////////////////////////////////////
	int emery_triangle1=154,emery_triangle2=41,emery_triangle3=20;
	float angle;
	glPushMatrix();//1-1
	{
		glTranslatef(0,-200,0);//使整個機構向下移動,以便觀看
		glRotatef(xRot, 1.0f, 0.0f, 0.0f);//正面
		glRotatef(yRot, 0.0f, 1.0f, 0.0f);//正面
		glRotatef(zRot, 0.0f, 0.0f, 1.0f);//正面
		/////////////////////////////////////////////////////////////////////////
		glRotatef(jx, 1.0f, 0.0f, 0.0f);
		glRotatef(jy, 0.0f, 1.0f, 0.0f);
		glRotatef(jz, 0.0f, 0.0f, 1.0f);
		//////////////////////////////////////////////////////////////////////////
		glPushMatrix();//3-1
		{
			glColor3ub(96, 96, 96);
			///////////////////////////////////////////////
			drawRetc(base_w1, base_l1, base_h);//底座1
			///////////////////////////////////////////////
			glPushMatrix();//7-1//基座的軌道//track_h=20,track_w=20,track_l=400;
			{
				/////////////此區塊內的數字,全部是自由心正定出來的
				glTranslatef((base_w1-300),0,base_h/2+track_h/2);
				glColor3ub(0, 96, 0);
				drawRetc(track_w,track_l,track_h);//1
				glTranslatef(-150,0,0);
				drawRetc(track_w,track_l,track_h);//3
				glTranslatef(50,0,0);
				drawRetc(track_w,track_l,track_h);//2
				glTranslatef(-150,0,0);
				drawRetc(track_w,track_l,track_h);//4
			}
			glPopMatrix();//7-2
			glPushMatrix();//8-1主體
			{
				//滑軌+平台1+馬達
				glTranslatef((base_w1-280),0,base_h/2+20+10/2);
				glColor3ub(8, 96, 80);
				////////////////////////////////////////////////////////////////////////
				///////////////////////////////////////馬達
				//////////int ServoMotor_Cir1=43,ServoMotor_Cir2=20,ServoMotor_Cir3=16;
				//////////int ServoMotor_Retc11=66,ServoMotor_Retc12=66,ServoMotor_Retc13=50;
				//////////int ServoMotor_Retc21=68,ServoMotor_Retc22=68,ServoMotor_Retc23=40;
				glRotatef(90,1.0f,0.0f,0.0f);
				glTranslatef(-140,-32,base_l1/2+ServoMotor_Cir2/2);
				drawCir(ServoMotor_Cir1, ServoMotor_Cir2, ServoMotor_Cir3);
				glTranslatef(0,0,ServoMotor_Cir2/2+ServoMotor_Retc13/2);
				drawRetc(ServoMotor_Retc11,ServoMotor_Retc12,ServoMotor_Retc13);
				glTranslatef(0,0,ServoMotor_Retc13/2+ServoMotor_Retc23/2);
				drawRetc(ServoMotor_Retc21,ServoMotor_Retc22,ServoMotor_Retc23);
				/////////////////////////////////////////////////////////////////////////
				////////////////滑軌//track_h1=10,track_w1=20,track_l1=200;
				glTranslatef(0,0,210);////最初定位
				glTranslatef(0,0,-life_x);//賦予生命---------------1
				glTranslatef(165,0,0);
				glRotatef(-90,1.0f,0.0f,0.0f);
				glTranslatef(-26,400,20+10);
				drawRetc(track_w1,track_l1,track_h1);//1
				glTranslatef(-290,0,0);
				drawRetc(track_w1,track_l1,track_h1);//2
				////////////////////////////////////platform_w1=500,platform_l1=200,platform_h1=32///平台1
				glTranslatef(120,0,track_h1/2+platform_h1/2);
				drawRetc(platform_w1,platform_l1,platform_h1);
				//////////////////////////////////////
				glPushMatrix();//9-1因為當時先畫滑軌2及平台2所以要加堆疊
				{
					/////////////////馬達
					//////////int ServoMotor_Cir1=43,ServoMotor_Cir2=20,ServoMotor_Cir3=16;
					//////////int ServoMotor_Retc11=66,ServoMotor_Retc12=66,ServoMotor_Retc13=50;
					//////////int ServoMotor_Retc21=68,ServoMotor_Retc22=68,ServoMotor_Retc23=40;
					glTranslatef(0,140,43);//由美觀決定
					glRotatef(90,1.0f,0.0f,0.0f);
					glRotatef(90,0.0f,1.0f,0.0f);
					glTranslatef(-140,-32,platform_w1/2+ServoMotor_Cir2/2);
					drawCir(ServoMotor_Cir1, ServoMotor_Cir2, ServoMotor_Cir3);
					glTranslatef(0,0,ServoMotor_Cir2/2+ServoMotor_Retc13/2);
					drawRetc(ServoMotor_Retc11,ServoMotor_Retc12,ServoMotor_Retc13);
					glTranslatef(0,0,ServoMotor_Retc13/2+ServoMotor_Retc23/2);
					drawRetc(ServoMotor_Retc21,ServoMotor_Retc22,ServoMotor_Retc23);
				}
				glPopMatrix();//9-2
				////////////////////////////////////track_h2=10,track_w2=20,track_l2=500;//滑軌2
				glRotatef(90,0.0f,0.0f,1.0f);
				glTranslatef(60,0,platform_h1/2+track_h2/2);
				glColor3ub(0, 96, 0);
				drawRetc(track_w2,track_l2,track_h2);//1
				glTranslatef(-40,0,0);
				drawRetc(track_w2,track_l2,track_h2);//2
				glTranslatef(-40,0,0);
				drawRetc(track_w2,track_l2,track_h2);//3
				glTranslatef(-40,0,0);
				drawRetc(track_w2,track_l2,track_h2);//4
				////////////////////////////////////////////////platform_w2=200,platform_l2=200,platform_h2=32;////平台2
				glTranslatef(0,-150,0);//最初定位
				glTranslatef(0,life_y,0);//賦予生命---------------2
				glTranslatef(60,0,track_h2/2+platform_h2/2);
				glColor3ub(0, 0, 90);
				drawRetc(platform_w2,platform_l2,platform_h2);//1
				//////////////////////////////////////////////////////base_vertical_h2=50,base_vertical_w2=500,base_vertical_l2=200//垂直底座
				glRotatef(90,0.0f,1.0f,0.0f);
				glTranslatef(base_vertical_w2/-2+platform_h2/-2,0,platform_w2/2-base_vertical_h2/2);
				glColor3ub(0, 50, 100);
				drawRetc(base_vertical_w2,base_vertical_l2,base_vertical_h2);//1
				//////////////////////////////////////////////垂直底座馬達
				glPushMatrix();//10-1
				{
					//////////int ServoMotor_Cir1=43,ServoMotor_Cir2=20,ServoMotor_Cir3=16;
					//////////int ServoMotor_Retc11=66,ServoMotor_Retc12=66,ServoMotor_Retc13=50;
					//////////int ServoMotor_Retc21=68,ServoMotor_Retc22=68,ServoMotor_Retc23=40;
					glTranslatef(base_vertical_w2/-2+ServoMotor_Cir2/-2,0,0);
					glRotatef(-90,0.0f,1.0f,.0f);
					drawCir(ServoMotor_Cir1, ServoMotor_Cir2, ServoMotor_Cir3);
					glTranslatef(0,0,ServoMotor_Cir2/2+ServoMotor_Retc13/2);
					drawRetc(ServoMotor_Retc11,ServoMotor_Retc12,ServoMotor_Retc13);
					glTranslatef(0,0,ServoMotor_Retc13/2+ServoMotor_Retc23/2);
					drawRetc(ServoMotor_Retc21,ServoMotor_Retc22,ServoMotor_Retc23);
				}
				glPopMatrix();//10-2
				//////////////////track_vertical_h=10,track_vertical_w=500,track_vertical_l=20;//垂直底座滑軌
				glTranslatef(0,0,(base_vertical_h2/2+track_vertical_h/2)*-1);
				glColor3ub(0, 96, 0);
				glTranslatef(0,20,0);
				drawRetc(track_vertical_w,track_vertical_l,track_vertical_h);//1
				glTranslatef(0,-40,0);
				drawRetc(track_vertical_w,track_vertical_l,track_vertical_h);//1
				glTranslatef(0,-70,0);
				drawRetc(track_vertical_w,track_vertical_l,track_vertical_h);//2
				glTranslatef(0,180,0);
				drawRetc(track_vertical_w,track_vertical_l,track_vertical_h);//2
				/////////////////////////////////track_vertical_h1=32,track_vertical_w1=200,track_vertical_l1=200//垂直滑軌上的移動平台
				glTranslatef(-150,0,0);//最初定位
				glTranslatef(life_z,0,0);//賦予生命---------------3
				glTranslatef(0,-90,0);
				glTranslatef(0,0,(track_vertical_h/2+32/2)*-1);
				glColor3ub(0, 50, 80);
				drawRetc(track_vertical_w1,track_vertical_l1,track_vertical_h1);
				/////////////////////////////////base_emery_w1=100,base_emery_l1=150,base_emery_h1=20,base_emery_w2=150,base_emery_l2=60,base_emery_h2=20//沙輪機底板
				glTranslatef(0,(track_vertical_l1-base_emery_l1)/2,(track_vertical_h1/2+base_emery_h1/2)*-1);
				glColor3ub(50, 30, 40);
				drawRetc(base_emery_w1,base_emery_l1,base_emery_h1);
				glRotatef(90,0.0f,0.0f,1.0f);
				glTranslatef(base_emery_l1/2+base_emery_w2/2,0,0);
				drawRetc(base_emery_w2,base_emery_l2,base_emery_h2);
				///////////////////////////////////////////////////
				//int emery_triangle1=154,emery_triangle2=41,emery_triangle3=20;
				glPushMatrix();//11-1//沙輪機底板三角形
				{
				glTranslatef(-2,20,0);
				glRotatef(-8,0.0f,0.0f,1.0f);
				drawRetc(emery_triangle1,emery_triangle2,emery_triangle3);
				}
				glPopMatrix();//11-2
				//////////////////////////////////////////////////
				glPushMatrix();//12-1//沙輪機底板三角形
				{
				glTranslatef(-2,-20,0);
				glRotatef(8,0.0f,0.0f,1.0f);
				drawRetc(emery_triangle1,emery_triangle2,emery_triangle3);
				}
				glPopMatrix();//12-2
				
				//////////////////////////////////////////////沙輪棒馬達
				glPushMatrix();//13-1
				{
					//////////int ServoMotor_Cir1=43,ServoMotor_Cir2=20,ServoMotor_Cir3=16;
					//////////int ServoMotor_Retc11=66,ServoMotor_Retc12=66,ServoMotor_Retc13=50;
					//////////int ServoMotor_Retc21=68,ServoMotor_Retc22=68,ServoMotor_Retc23=40;
					glTranslatef(25,0,emery_triangle3/2+ServoMotor_Cir2/2);
					glColor3ub(0, 50, 100);
					drawCir(ServoMotor_Cir1, ServoMotor_Cir2, ServoMotor_Cir3);
					glTranslatef(0,0,ServoMotor_Cir2/2+ServoMotor_Retc13/2);
					drawRetc(ServoMotor_Retc11,ServoMotor_Retc12,ServoMotor_Retc13);
					glTranslatef(0,0,ServoMotor_Retc13/2+ServoMotor_Retc23/2);
					drawRetc(ServoMotor_Retc21,ServoMotor_Retc22,ServoMotor_Retc23);
				}
				glPopMatrix();//13-2

				/////////////////////////////////////////////////////沙磨機start
				
				glPushMatrix();//14-1
				{
					
					glTranslatef(150/2-45,0,(emery_triangle3/2+10/2)*-1);
					drawCir(15, 10, 16);//連桿
					//glRotatef(-90,0.0f,0.0f,1.0f);
					glRotatef(-life_r,0.0f,0.0f,1.0f);//賦予生命---------------4
					////////////////////////////////////////沙磨機主體start
					glTranslatef(0,0,(10/2+60/2)*-1);
					drawRetc(60,60,60);
					glRotatef(90,0.0f,1.0f,0.0f);
					glTranslatef(0,0,60/2+55.36/2);
					drawCir(25, 55.36, 16);
					///////////////////////////////////////////////////
					glTranslatef(0,0,55.36/2);
					if(Line_Side!=false)
					{
						glBegin(GL_LINES);
						{
							for(angle = 0.0f; angle < (2.0f*GL_PI); angle+=((2.0f*GL_PI)/16))
							{						
								glVertex3f(0.0f, 0.0f, 34.64f);
								x = 25.0f*sin(angle);
								y = 25.0f*cos(angle);
								glVertex2f(x, y);
							}
						}
						glEnd();
					}
					else
					{
					glBegin(GL_TRIANGLE_FAN);//三角錐的主體
					{
						glVertex3f(0.0f, 0.0f, 34.64f);
						for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f))
						{
							x = 25.0f*sin(angle);
							y = 25.0f*cos(angle);
							glVertex2f(x, y);
						}
					}
					glEnd();
					}
					////////////////////////////////////////沙磨機主體end
					////////////////////////////////////////////////////////打磨棒1
					glTranslatef(0,0,34.64f);
					drawCir(2.5, 20, 16);
					//////////////////////////////////////////////////////打磨棒2
					glTranslatef(0,0,20/2+20/2);
					drawCir(5, 20, 16);

				}
				glPopMatrix();//14-2
				
			/////////////////////////////////////////////////////////////////沙磨機end
			}
			glPopMatrix();//8-2
			glTranslatef( -base_w1/2-base_l2/2,base_l1/-2+base_w2/2 ,0.0f);
			glColor3ub(96, 96, 96);
			/////小塊底座//base_l2=200,base_w2=300;,base_h=50
			drawRetc(base_l2,base_w2 , base_h);
			glTranslatef(0,20,0);///由於規定夾具底座必須距離30mm,所以50-30=20,其中50為擺放在正中間時的距離兩邊的距離
			glPushMatrix();//4-1夾具底座
			{
				////////////int base_watch_h1=200,base_watch_w1=200,base_watch_l1=250;
				glTranslatef(((base_l2/-2)+(base_watch_l1/2)),0,(base_h/2+base_watch_h1/2));
				glColor3ub(96, 96, 80);
				drawRetc(base_watch_l1, base_watch_w1, base_watch_h1);
				glPushMatrix();//5-1//表框夾具
				{
				////////////int base_watch_h1=200,base_watch_w1=200,base_watch_l1=250;
				glTranslatef((base_watch_l1/2-74),(base_watch_w1/2-74)*-1,(base_watch_h1/2+10/2));
				glColor3ub(96, 96, 30);
				drawCir(50, 10, 16);
				////////////////////////////////////////
				glTranslatef(0,0,(10+20)/2);
				glColor3ub(50, 96, 30);
				drawCir(43, 20, 16);
				////////////////////////////////////////
				glTranslatef(0,0,(20+5)/2);
				glColor3ub(50, 40, 30);
				drawCir(40, 5, 16);
				////////////////////////////////////////
				glTranslatef(0,0,(5+15)/2);
				glColor3ub(50, 96, 30);
				drawCir(43, 15, 16);
				////////////////////////////////////////
				glTranslatef(0,0,(15+6)/2);
				glColor3ub(60, 96, 70);
				drawCir(30, 6, 16);
				/////////////////////////////////////////
				glTranslatef(0,0,(6+30)/2);
				glColor3ub(60, 20, 70);
				drawCir(25, 30, 16);
				}
				glPopMatrix();//5-2
			}
			glPopMatrix();//4-2
			glPushMatrix();//6-1//表框夾具馬達
			{
			
				//////////int ServoMotor_Cir1=43,ServoMotor_Cir2=20,ServoMotor_Cir3=16;
				//////////int ServoMotor_Retc11=66,ServoMotor_Retc12=66,ServoMotor_Retc13=50;
				//////////int ServoMotor_Retc21=68,ServoMotor_Retc22=68,ServoMotor_Retc23=40;
				glTranslatef((base_watch_l1/-2+50*3),(base_watch_w1/2+15/2),base_watch_h1-50/2);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glColor3ub(96, 58, 80);
				drawCir(ServoMotor_Cir1, ServoMotor_Cir2, ServoMotor_Cir3);
				glTranslatef(0,0,(ServoMotor_Cir2/2+ServoMotor_Retc13/2)*-1);
				drawRetc(ServoMotor_Retc11,ServoMotor_Retc12,ServoMotor_Retc13);
				glTranslatef(0,0,(ServoMotor_Retc13/2+ServoMotor_Retc23/2)*-1);
				drawRetc(ServoMotor_Retc21,ServoMotor_Retc22,ServoMotor_Retc23);

			}
			glPopMatrix();//6-2
		}
		glPopMatrix();//3-2
	}
	glPopMatrix();//1-2
}

BOOL CKk1View::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class


	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CKk1View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	char ch0[100],ch1[100],ch2[100],ch3[100],ch4[100],ch5[100];
	//int d1,s;
	double a,b,c,d,e,f;
	/////////////////////////////////////////////////////////////
	char *ch6,*ch7,*ch8,*ch9;
	int d1,s;
	LPVOID mapView6,mapView7,mapView8,mapView9;
	mapView6 = MapViewOfFile( hFileMap6,FILE_MAP_WRITE, 0, 0, 0 );
	mapView7 = MapViewOfFile( hFileMap7,FILE_MAP_WRITE, 0, 0, 0 );
	mapView8 = MapViewOfFile( hFileMap8,FILE_MAP_WRITE, 0, 0, 0 );
	mapView9 = MapViewOfFile( hFileMap9,FILE_MAP_WRITE, 0, 0, 0 );
	switch(work_number)
	{
	case 1:
		LPVOID mapView0,mapView1,mapView2,mapView3,mapView4,mapView5;
		mapView0 = MapViewOfFile( hFileMap0,FILE_MAP_WRITE, 0, 0, 0 );
		mapView1 = MapViewOfFile( hFileMap1,FILE_MAP_WRITE, 0, 0, 0 );
		mapView2 = MapViewOfFile( hFileMap2,FILE_MAP_WRITE, 0, 0, 0 );
		mapView3 = MapViewOfFile( hFileMap3,FILE_MAP_WRITE, 0, 0, 0 );
		mapView4 = MapViewOfFile( hFileMap4,FILE_MAP_WRITE, 0, 0, 0 );
		mapView5 = MapViewOfFile( hFileMap5,FILE_MAP_WRITE, 0, 0, 0 );	
		if(mapView0 !=NULL)
		{
			strcpy(ch0,(LPTSTR)mapView0);
			strcpy(ch1,(LPTSTR)mapView1);
			strcpy(ch2,(LPTSTR)mapView2);
			strcpy(ch3,(LPTSTR)mapView3);
			strcpy(ch4,(LPTSTR)mapView4);
			strcpy(ch5,(LPTSTR)mapView5);
			a=(atof(ch0)/10000);
			b=(atof(ch1)/10000);
			c=(atof(ch2)/10000);
			d=(atof(ch3)/10000);
			e=(atof(ch4)/10000);
			f=(atof(ch5)/10000);
			Theta=a;
			PDX=b;
			PDY=c;
			PAX=d;
			PAY=e;
			DeltaT=f;
			fprintf(k1,"%f\t%f\t%f\t%f\t%f\t%f\n",a,b,c,d,e,f);
		}
		break;
	case 2:
		switch(next_number)
		{
			case 0:
				if(life_x<=71.9994 && life_y<=105.75 &&life_z<=191.542)
				{
					life_x+=71.9994/300;
					life_y+=105.75/300;
					life_z+=191.542/300;
				}
				else
				{
					next_number++;
				}
				break;
			case 1:
				if(Theta_w0<=16.128)
				{
					Theta_w0+=(16.128-(-16.128))/500;
					life_x=(90*sin(Theta_w0*3.14/180)+X_toffset-X_offset);
					life_y=-14.25-a1-d4+Y_toffset-Y_offset;
					life_z=42-90*cos(Theta_w0*3.14/180)-Z_toffset+Z_offset;
				}
				else
				{
					next_number++;
				}
				break;
			case 2:
				if(Theta_w0>=-16.128)
				{
					Theta_w0-=(16.128-(-16.128))/500;
					life_x=(90*sin(Theta_w0*3.14/180)+X_toffset-X_offset);
					life_y=-14.25-a1-d4+Y_toffset-Y_offset;
					life_z=42-90*cos(Theta_w0*3.14/180)-Z_toffset+Z_offset;
				}
				else
				{
					next_number++;
				}
				break;
			case 3:
				if(life_x>0)
				{
					life_x-=71.9994/300;
				}
				if(life_y>0)
				{
					life_y-=105.75/300;
					life_z-=191.542/300;
				}
				if(life_x<=0.0f && life_y<=0.0f && life_z <=0.0f && life_r <=0.0f)
					next_number=0;
				break;
		}
		ch6=fcvt(life_x,4,&d1,&s);
		strcpy((LPTSTR)mapView6,ch6);
		ch7=fcvt(life_y,4,&d1,&s);
		strcpy((LPTSTR)mapView7,ch7);
		ch8=fcvt(life_z,4,&d1,&s);
		strcpy((LPTSTR)mapView8,ch8);
		ch9=fcvt((work_number-1),4,&d1,&s);
		strcpy((LPTSTR)mapView9,ch9);
		fprintf(l,"%c\t%c\t%c\t%c\n",ch6,ch7,ch8,ch9);
		UnmapViewOfFile( (LPVOID)mapView6);
		UnmapViewOfFile( (LPVOID)mapView7);
		UnmapViewOfFile( (LPVOID)mapView8);
		UnmapViewOfFile( (LPVOID)mapView9);
		Invalidate(true);
		break;

	case 3:
		switch(next_number)
		{
			case 0:
				if(life_x<=71.9999f)
					life_x+=71.9999f/300.0f;			
				if(life_y <= 249.0066f)
					life_y+=249.0066f/300.0f;
				if(life_z <= 48.0f)
					life_z+=48.0f/300.0f;
				if(life_r <= 90.0f)
					life_r+=90.0f/300.0f;
				if(life_x>=71.9999f && life_y>=249.0066f && life_z>=48.0f && life_r>= 90.0f)
				{
					next_number++;
				}
				break;
			case 1:
				if(Theta_w9<=18.21)
				{
					Theta_w9+=(18.21-(-18.21))/500;
					life_x=(80*sin(Theta_w9*3.14/180)+X_toffset-X_offset);
					life_y=55-a1-80*cos(Theta_w9*3.14/180)+Y_toffset-Y_offset;
					life_z=-38-d4-Z_toffset+Z_offset;
				}
				else
				{
					next_number++;
				}
				break;
			case 2:
				if(Theta_w9>=-18.21)
				{
					Theta_w9-=(18.21-(-18.21))/500;
					life_x=(80*sin(Theta_w9*3.14/180)+X_toffset-X_offset);
					life_y=55-a1-80*cos(Theta_w9*3.14/180)+Y_toffset-Y_offset;
					life_z=-38-d4-Z_toffset+Z_offset;
				}
				else
				{
					next_number++;
				}
				break;
			case 3:
				if(life_x>0.0f)
				{
					life_x-=71.9999f/300.0f;
				}
				if(life_y>0.0f)
				{
					life_y-=249.0066f/300.0f;
				}
				if(life_z>0.0f)
				{
					life_z-=48.0f/300.0f;
				}
				if(life_r>=0.0f)
				{
					life_r-=90.0f/300.0f;
				}
				if(life_x<=0.0f && life_y<=0.0f && life_z <=0.0f && life_r <=0.0f)
					next_number=0;
				break;
		}
		ch6=fcvt(life_x,4,&d1,&s);
		strcpy((LPTSTR)mapView6,ch6);
		ch7=fcvt(life_y,4,&d1,&s);
		strcpy((LPTSTR)mapView7,ch7);
		ch8=fcvt(life_z,4,&d1,&s);
		strcpy((LPTSTR)mapView8,ch8);
		ch9=fcvt((work_number-1),4,&d1,&s);
		strcpy((LPTSTR)mapView9,ch9);
		
		UnmapViewOfFile( (LPVOID)mapView6);
		UnmapViewOfFile( (LPVOID)mapView7);
		UnmapViewOfFile( (LPVOID)mapView8);
		UnmapViewOfFile( (LPVOID)mapView9);
		Invalidate(true);
		break;
	}
	CScrollView::OnTimer(nIDEvent);
}

void CKk1View::Onsettimer() 
{
	// TODO: Add your command handler code here
	///////////////////////////////////////////

	///////////////////////////////////////////
	k1=fopen("mapdata.txt","w");
	hFileMap0 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME0 ) ;
	hFileMap1 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME1 ) ;
	hFileMap2 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME2 ) ;
	hFileMap3 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME3 ) ;
	hFileMap4 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME4 ) ;
	hFileMap5 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME5 ) ;
	
	if(ontimer==false)
	{
		SetTimer(1,10,NULL);
		ontimer=true;
		work_number=1;
	}
	else
	{
		work_number=1;
	}
	
}

void CKk1View::OnDirectly()//正面 
{
	// TODO: Add your command handler code here
	///////////////////////////////////////////
	life_x=0;//賦予平台生命變數
	life_y=0;
	life_z=0;
	life_r=0;
	///////////////////////////////////////
	X_offset=48;
	Y_offset=100;
	Z_offset=554;
	X_toffset=145;
	Y_toffset=575;
	Z_toffset=318;
	a1=205;
	d4=150;
	Theta_w0=-16.128;
	Theta_w9=0;
	///////////////////////////////////////////

	if(ontimer==false)
	{
		SetTimer(1,10,NULL);
		ontimer=true;
		work_number=2;
		next_number=0;
	}
	else
	{
		work_number=2;
		next_number=0;
	}
	l=fopen("mapdata.txt","w");

}

void CKk1View::OnFlank()//側面 
{
	// TODO: Add your command handler code here
	///////////////////////////////////////////
	life_x=0;//賦予平台生命變數
	life_y=0;
	life_z=0;
	life_r=0;
	X_offset=48;
	Y_offset=100;
	Z_offset=554;
	X_toffset=145;
	Y_toffset=575;
	Z_toffset=318;
	a1=205;
	d4=150;
	Theta_w0=0;
	Theta_w9=-18.21;
	///////////////////////////////////////////
	if(ontimer==false)
	{
		SetTimer(1,10,NULL);
		ontimer=true;
		work_number=3;
		next_number=0;

	}
	else
	{
		work_number=3;
		next_number=0;

	}

}

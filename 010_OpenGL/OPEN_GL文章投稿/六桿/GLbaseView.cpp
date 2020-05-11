// GLbaseView.cpp : implementation of the CGLbaseView class
//

#include "stdafx.h"
#include "GLbase.h"
#include <gl/glut.h>//第三步
#include "glmfc.h"//第三步
#include "GLbaseDoc.h"
#include "GLbaseView.h"
#include "OpenGLFun.h"//第六步
#include "OpenGLPara.h"
#include "Dlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
float view_x,view_y,view_z;
float trans_x,trans_y;
float Rotat1,Rotat2,Rotat3,Rotat4,Rotat5;
float Trans1;
/////////////////////////////////////////////////////////////////////////////
// CGLbaseView

IMPLEMENT_DYNCREATE(CGLbaseView, CView)

BEGIN_MESSAGE_MAP(CGLbaseView, CView)
	//{{AFX_MSG_MAP(CGLbaseView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_set, Onset)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_A, OnA)
	ON_BN_CLICKED(IDC_C, OnC)
	ON_BN_CLICKED(IDC_D, OnD)
	ON_BN_CLICKED(IDC_E, OnE)
	ON_BN_CLICKED(IDC_Q, OnQ)
	ON_BN_CLICKED(IDC_S, OnS)
	ON_BN_CLICKED(IDC_W, OnW)
	ON_BN_CLICKED(IDC_X, OnX)
	ON_BN_CLICKED(IDC_Z, OnZ)
	ON_BN_CLICKED(IDC_UP1, OnUp1)
	ON_BN_CLICKED(IDC_UP2, OnUp2)
	ON_BN_CLICKED(IDC_UP3, OnUp3)
	ON_BN_CLICKED(IDC_UP4, OnUp4)
	ON_BN_CLICKED(IDC_UP5, OnUp5)
	ON_BN_CLICKED(IDC_UP6, OnUp6)
	ON_BN_CLICKED(IDC_Down1, OnDown1)
	ON_BN_CLICKED(IDC_Down2, OnDown2)
	ON_BN_CLICKED(IDC_Down3, OnDown3)
	ON_BN_CLICKED(IDC_Down4, OnDown4)
	ON_BN_CLICKED(IDC_Down5, OnDown5)
	ON_BN_CLICKED(IDC_Down6, OnDown6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGLbaseView construction/destruction

CGLbaseView::CGLbaseView()
{
	// TODO: add construction code here

}

CGLbaseView::~CGLbaseView()
{
}

BOOL CGLbaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGLbaseView drawing

void CGLbaseView::OnDraw(CDC* pDC)
{
	m_pPal = NULL;//第十步
	CGLbaseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	////////////////////////////////////////第七步
	CPalette *	ppalOld	= NULL;
	if (m_pPal) {
		ppalOld	= pDC->SelectPalette(m_pPal, 0);
		pDC->RealizePalette();
	}
	BOOL	bResult	= wglMakeCurrent(pDC->m_hDC, m_hrc);
	if (FALSE == bResult)
		TRACE(_T("wglMakeCurrent() failed %x.\r\n"), ::GetLastError());

	opengl_Initial();

	static GLfloat  ambientLight[]	= { 1.0f, 1.0f, 1.0f, 1.0f };	
	static GLfloat  diffuseLight[]	= { 0.7f, 0.7f, 0.7f, 1.0f };
	static GLfloat  specular[]		= { 0.7f, 0.7f, 0.7f, 1.0f };	//燈光性質
	static GLfloat  specref []		= { 0.5f, 0.5f, 0.2f, 1.0f };	//反射性質
	static float normal[3];//設定法向量

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除畫面的動作
	if(Line_Flag)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//會產生多邊形的外圍輪廓
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//會產生填滿的多邊形
///////////////////////////////////////////
//第十三步開始
	glPushMatrix();///區塊start
	{
		glTranslatef(0.0f,0.0f,0.0f);
		glRotatef(view_x, 1.0f, 0.0f, 0.0f);//視角旋轉角度
		glRotatef(view_y, 0.0f, 1.0f, 0.0f);//視角旋轉角度
		glRotatef(view_z, 0.0f, 0.0f, 1.0f);//視角旋轉角度
		glColor3ub(0.0f,0.0f,130.0f);//設顏色
		drawRetc(1024.0f,768.0f,10.0f);//底板
		glPushMatrix();///區塊start
		{
			glColor3ub(0.0f,130.0f,130.0f);
			glTranslatef((1024.0f/2.0f-100.0f/2.0f),(768.0f/2.0f-100.0/2.0f),(10.0f/2.0f+200.0f/2.0f));
			glTranslatef(trans_x,0.0,0.0);
			glTranslatef(0.0,trans_y,0.0);
			drawRetc(100.0f,100.0f,200.0f);//主幹1
			glRotatef(Rotat1,0.0f,0.0f,1.0f);
			glPushMatrix();///區塊start
			{
				glColor3ub(0.0f,130.0f,30.0f);
				glTranslatef(0.0f,0.0f,(200.0f/2.0f)+(200.0f/2.0f));
				drawRetc(100.0f,100.0f,200.0f);//主幹2
				glPushMatrix();///區塊start
				{
					glColor3ub(130.0f,30.0f,130.0f);
					glTranslatef(100.0f/2.0f-300.0f/2.0f,(100.0f/2.0f+100.0f/2.0f),(200.0f/2.0f)-(100.0f/2.0f));
					glTranslatef(300.0f/2.0f-100.0f/2.0f,0.0f,0.0f);
					glRotatef(Rotat2,0.0f,1.0f,0.0f);
					glTranslatef(-300.0f/2+100.0f/2.0f,0.0f,0.0f);
					drawRetc(300.0f,100.0f,100.0f);//手臂1
					glPushMatrix();///區塊start
					{
						glColor3ub(130.0f,30.0f,30.0f);
						glTranslatef(-100.0f,0.0f,0.0f);
						glRotatef(Rotat3,0.0f,1.0f,0.0f);
						glTranslatef(100.0f,0.0f,0.0f);
						glTranslatef(-300.0f/2-250.0f/2.0f+100.0f,-100.0f/2.0f-100.0f/2.0f,0.0f);
						drawRetc(250.0f,100.0f,100.0f);//手臂2
						glPushMatrix();///區塊start
						{
							glColor3ub(30.0f,130.0f,130.0f);
							glTranslatef(-300.0f/2.0f+50.0f/2.0,0.0f,0.0f);
							drawCir(50.0f,100.0f,16);//手臂2的半圓
							glRotatef(Rotat4,1.0f,0.0f,0.0f);
							glPushMatrix();///區塊start
							{
								glColor3ub(130.0f,130.0f,130.0f);
								glRotatef(90.0f,1.0f,0.0f,0.0f);
								glTranslatef(-50.0f,0.0f,(150.0f+Trans1)/2.0f);
								drawCir(10.0f,150.0f+Trans1,16);//手臂3
								glPushMatrix();///區塊start
								{
									glTranslatef(0.0f,0.0f,(150.0f+Trans1)/2.0f);
									glRotatef(Rotat5,0.0f,0.0f,1.0f);
									drawRetc(40.0f,30.0f,3.0f);//手掌
								}
								glPopMatrix();///區塊end
							}
							glPopMatrix();///區塊end
						}
						glPopMatrix();///區塊end
					}
					glPopMatrix();///區塊end
				}
				glPopMatrix();///區塊end
			}
			glPopMatrix();///區塊end
		}
		glPopMatrix();///區塊end
	}
	glPopMatrix();///區塊end
//////////////////////////////////////////
//第十三步結束
////////////////////////第十一步
	glFlush();
	SwapBuffers(pDC->m_hDC);

	if (ppalOld)
		pDC->SelectPalette(ppalOld, 0);

	wglMakeCurrent(NULL, NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CGLbaseView diagnostics

#ifdef _DEBUG
void CGLbaseView::AssertValid() const
{
	CView::AssertValid();
}

void CGLbaseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGLbaseDoc* CGLbaseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGLbaseDoc)));
	return (CGLbaseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGLbaseView message handlers

int CGLbaseView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	///////////////////////////////////////////第四步
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

	//
	// create the palette
	//
	CreateRGBPalette(dc->m_hDC, m_pPal);		
	return 0;
}

void CGLbaseView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
///////////////////////////////////////////第五步
	if ((cx <= 0) || (cy <= 0))
		return;

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
    glViewport(0, 0, w, h);//設定視窗中可以讓Open GL繪圖的部分

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
	
}
void CGLbaseView::opengl_Initial()//第九步
{
	//open gl初始值設定	
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

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);//將多邊形設為具有反射性質	
	glMateriali(GL_FRONT, GL_SHININESS, 128);//設定反射性質的亮度
	glClearColor(0.0f, 100.0f, 150.0f, 1.0f );//設定桌布顏色	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除螢幕動作

}

BOOL CGLbaseView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;//第十二步
}

void CGLbaseView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case 65://A,4
		view_y+=5.0f;
		//MessageBox("A");
		break;
	case 67://C,3
		break;	
	case 68://D,6
		view_y-=5.0f;
		//MessageBox("D");
		break;
	case 69://E,9
		view_z+=5.0f;
		//MessageBox("E");
		break;
	case 81://Q,7
		view_z-=5.0f;
		//MessageBox("Q");
		break;
	case 83://S,5
		view_x=0.0f;
		view_y=0.0f;
		view_z=0.0f;
		break;
	case 87://W,8
		view_x-=5.0f;
		//MessageBox("W");
		break;
	case 88://X,2
		view_x+=5.0f;
		//MessageBox("X");
		break;
	case 90://Z,1
		view_z=0.0f;
		view_x=-90.0f;
		view_y=0.0f;
		//MessageBox("Z");
		break;
	case VK_F5:
		Line_Flag = !Line_Flag;
		break;
	case VK_UP:
		trans_x+= 5.0f;
		break;
	case VK_DOWN:
		trans_x -= 5.0f;
		break;
	case VK_RIGHT:
		trans_y += 5.0f;
		break;
	case VK_LEFT:
		trans_y -= 5.0f;
		break;
	}
	Invalidate(true);	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CGLbaseView::Onset() 
{
	// TODO: Add your command handler code here
	///*
	CDlg1 dlg1(this);//建立對話盒實體
	if(dlg1.DoModal()==IDOK)
	{
		Rotat1=dlg1.m_v1; 
		Rotat2=dlg1.m_v2;
		Rotat3=dlg1.m_v3;
		Rotat4=dlg1.m_v4;
		Rotat5=dlg1.m_v5;
		Trans1=dlg1.m_v6;
		
	}
	Invalidate(true);
	//*/
	//bar1.show();
}

void CGLbaseView::OnButton1() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnQ() 
{
	// TODO: Add your control notification handler code here
	view_z-=5.0f;
	this->SetFocus(); 
	Invalidate(true);
}

void CGLbaseView::OnS() 
{
	// TODO: Add your control notification handler code here
	view_x=0.0f;
	view_y=0.0f;
	view_z=0.0f;
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnW() 
{
	// TODO: Add your control notification handler code here
	view_x-=5.0f;
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnX() 
{
	// TODO: Add your control notification handler code here
	view_x+=5.0f;
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnZ() 
{
	// TODO: Add your control notification handler code here
	view_z=0.0f;
	view_x=-90.0f;
	view_y=0.0f;
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnE() 
{
	// TODO: Add your control notification handler code here
	view_z+=5.0f;
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnD() 
{
	// TODO: Add your control notification handler code here
	view_y-=5.0f;
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnC() 
{
	// TODO: Add your control notification handler code here
	Line_Flag = !Line_Flag;
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnA() 
{
	// TODO: Add your control notification handler code here
	view_y+=5.0f;
	this->SetFocus(); 
	Invalidate(true);
}

void CGLbaseView::OnUp1() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(0,1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);		
}

void CGLbaseView::OnUp2() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(1,1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnUp3() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(2,1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnUp4() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(3,1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnUp5() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(4,1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnUp6() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(5,1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnDown1() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(0,-1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnDown2() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(1,-1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnDown3() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(2,-1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnDown4() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(3,-1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnDown5() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(4,-1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

void CGLbaseView::OnDown6() 
{
	// TODO: Add your control notification handler code here
	float data[6]={0};
	bar1.SentData(5,-1.0f);
	bar1.GetData(data);
	Rotat1=data[0]; 
	Rotat2=data[1];
	Rotat3=data[2];
	Rotat4=data[3];
	Rotat5=data[4];
	Trans1=data[5];
	this->SetFocus(); 
	Invalidate(true);	
}

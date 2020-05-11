// OpenGLView.cpp : implementation file
//

#include "stdafx.h"
#include "TestGL.h"
#include "OpenGLView.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// OpenGLView

IMPLEMENT_DYNCREATE(OpenGLView, CView)

OpenGLView::OpenGLView()
{
	GLHardAccel=FALSE;
	m_pDC=NULL;
	m_hRC=NULL;
}

OpenGLView::~OpenGLView()
{
}


BEGIN_MESSAGE_MAP(OpenGLView, CView)
	//{{AFX_MSG_MAP(OpenGLView)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// OpenGLView drawing

void OpenGLView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	wglMakeCurrent(m_hDC, m_hRC);
	glFlush();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// clear background
	GLRender();
	SwapBuffers(m_hDC);  // if double buffering is used it's time to swap the buffers
    wglMakeCurrent(NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// OpenGLView diagnostics

#ifdef _DEBUG
void OpenGLView::AssertValid() const
{
	CView::AssertValid();
}

void OpenGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// OpenGLView message handlers

int OpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	if (InitializeOpenGL()==FALSE)
	   return -1;
	return 0;
}

BOOL OpenGLView::InitializeOpenGL()
{
    m_pDC=new CClientDC(this);
    if (m_pDC==NULL)
	   return FALSE;//繪圖DC建立失敗!!繪圖視窗無法建立.
	m_hDC=m_pDC->GetSafeHdc();
	if (!SetupPixelFormat())
       return FALSE;
    m_hRC=wglCreateContext(m_hDC); 
    if (m_hRC==NULL)
	   return FALSE;//繪圖Context建立失敗!!繪圖視窗無法建立.
	if (wglMakeCurrent(m_hDC,m_hRC)==NULL)
       return FALSE;//OpenGL作動失敗!!繪圖視窗無法建立.
    glClearColor(0.,0.,0.,0.);// specify black as clear color
    glClearDepth(1.0f);               // specify the back of the buffer as clear depth
    glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    wglMakeCurrent(NULL,NULL);        // enable depth testing
    return TRUE;
}

BOOL OpenGLView::SetupPixelFormat()
{
     PIXELFORMATDESCRIPTOR pfd = 
     { sizeof(PIXELFORMATDESCRIPTOR),// size of this pfd
       1,                      // version number
       PFD_DRAW_TO_WINDOW |    // support window
       PFD_SUPPORT_OPENGL |    // support OpenGL
	   PFD_DOUBLEBUFFER,       // double buffered
       PFD_TYPE_RGBA,          // RGBA type
       24,                     // 24-bit color depth
       0, 0, 0, 0, 0, 0,       // color bits ignored
       0,                      // no alpha buffer
       0,                      // shift bit ignored
       0,                      // no accumulation buffer
       0, 0, 0, 0,             // accum bits ignored
       16,                     // 16-bit z-buffer
       0,                      // no stencil buffer
       0,                      // no auxiliary buffer
       PFD_MAIN_PLANE,         // main layer
       0,                      // reserved
       0, 0, 0                 // layer masks ignored
     };
	int iPixelFormat;
    if (GLHardAccel==FALSE)//軟體
	 { iPixelFormat=MyChosePixelFormat(false);
	   if (iPixelFormat==0)
	    { pfd.dwFlags=PFD_GENERIC_FORMAT|PFD_DRAW_TO_WINDOW|PFD_DOUBLEBUFFER|PFD_SUPPORT_OPENGL;
	      iPixelFormat=ChoosePixelFormat(m_hDC,&pfd); 
		}
	 }
	else//硬體加速
	 { iPixelFormat=MyChosePixelFormat(true);
	   if (iPixelFormat==0)
	    { iPixelFormat=MyChosePixelFormat(false);
	      if (iPixelFormat==0)
	       { pfd.dwFlags=PFD_DRAW_TO_WINDOW|PFD_DOUBLEBUFFER|PFD_SUPPORT_OPENGL;
	         iPixelFormat=ChoosePixelFormat(m_hDC,&pfd); 
		   }
	    }
	 } 
    if (iPixelFormat==0)
	   return FALSE;//選擇Pixelformat失敗!!繪圖視窗無法建立.
	if (SetPixelFormat(m_hDC,iPixelFormat,&pfd)==FALSE)//設定 Pixel format 給 device context
	   return FALSE;	//設定Pixelformat失敗!!繪圖視窗無法建立.
    return TRUE;
}

int OpenGLView::MyChosePixelFormat(bool accel)
{
    int nFormatCount=DescribePixelFormat(m_hDC,1,0,NULL);
	PIXELFORMATDESCRIPTOR pfd;
  	for (int i=1; i<=nFormatCount;i++)
      {	if (DescribePixelFormat(m_hDC,i,sizeof(PIXELFORMATDESCRIPTOR),&pfd)==nFormatCount)
		 { if (accel==false)
		    { if ((pfd.dwFlags & PFD_GENERIC_FORMAT)
			     &&(pfd.dwFlags & PFD_DRAW_TO_WINDOW)
				 &&(pfd.dwFlags & PFD_SUPPORT_OPENGL)
	             &&(pfd.dwFlags & PFD_DOUBLEBUFFER)
		         &&(pfd.iPixelType==PFD_TYPE_RGBA)
		         &&(pfd.cColorBits>=16)
		         &&(pfd.cDepthBits>=16))
	          return i;	
		    }
		   else
		    { if (!(pfd.dwFlags & PFD_GENERIC_FORMAT)
                 &&(pfd.dwFlags & PFD_DRAW_TO_WINDOW) 
			     &&(pfd.dwFlags & PFD_SUPPORT_OPENGL)
	             &&(pfd.dwFlags & PFD_DOUBLEBUFFER)
		         &&(pfd.iPixelType==PFD_TYPE_RGBA)
		         &&(pfd.cColorBits>=16)
		         &&(pfd.cDepthBits>=16))
	          return i;	
		    }
		 }
	  }
	return 0;
}

BOOL OpenGLView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}


void OpenGLView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	GLResize(cx,cy);
}

void OpenGLView::GLResize(int Width, int Height)
{
    if (0>=Width||0>=Height) 
	   return;
	ScrWidth=Width;ScrHeight=Height;
   	// TODO: Add your message handler code here
	CreateProjMatrix(EyeXMax,EyeXMin,EyeYMax,EyeYMin);
}

void OpenGLView::CreateProjMatrix(double xmax, double xmin, double ymax, double ymin)
{
	double dx,dy;

	if (xmax<xmin)
	   return;
    if (ymax<ymin)
	   return;
	dx=xmax-xmin;
    dy=ymax-ymin;
	if (dx<=dy)
	 { ymax=ymin+dx; 
	   dy=dx;
	 }  
	else
	 { xmax=xmin+dy;  
	   dx=dy;
	 }
	if (ScrWidth<=ScrHeight)
       ymax=ymin+dx*ScrHeight/ScrWidth;
	else
       xmax=xmin+dy*ScrWidth/ScrHeight;
    EyeXMax=xmax;EyeXMin=xmin;
    EyeYMax=ymax;EyeYMin=ymin;
    wglMakeCurrent(m_hDC,m_hRC);
    glViewport(0,0,ScrWidth,ScrHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(EyeXMin,EyeXMax,EyeYMin,EyeYMax,EyeZMin,EyeZMax); 
    wglMakeCurrent(NULL,NULL);
}

void OpenGLView::GLRender()
{

}

void OpenGLView::ViewAll()
{
    double xmax,xmin,ymax,ymin;

	AutoScale(ObjXMax,ObjXMin,ObjYMax,ObjYMin,ObjZMax,ObjZMin,xmax,xmin,ymax,ymin);
    CreateProjMatrix(xmax,xmin,ymax,ymin);
    UpdateDrawView();
}

void OpenGLView::SetObjXYZRange(double xmax, double xmin, double ymax, double ymin, double zmax, double zmin, bool depthflag)
{
    ObjTransX=-0.5*(xmax+xmin);
	ObjTransY=-0.5*(ymax+ymin);
	ObjTransZ=-0.5*(zmax+zmin);;
	
	ObjXMax=xmax+ObjTransX;ObjXMin=xmin+ObjTransX;
	ObjYMax=ymax+ObjTransY;ObjYMin=ymin+ObjTransY;
	ObjZMax=zmax+ObjTransZ;ObjZMin=zmin+ObjTransZ;
	if (depthflag==true)
	 { double d;
	   d=0.6*sqrt((ObjXMax-ObjXMin)*(ObjXMax-ObjXMin)+(ObjYMax-ObjYMin)*(ObjYMax-ObjYMin)+(ObjZMax-ObjZMin)*(ObjZMax-ObjZMin));
	   EyeZMax=d;
       EyeZMin=-d;
	 }
}

void OpenGLView::AutoScale(double xmax, double xmin, double ymax, double ymin, double zmax, double zmin, double &maxx, double &minx, double &maxy, double &miny)
{
	GLdouble a[16];
    double maxz,minz,X,Y,Z,d1,d2;

	wglMakeCurrent(m_hDC,m_hRC);
    glMatrixMode(GL_MODELVIEW);
    glGetDoublev(GL_MODELVIEW_MATRIX,a); 
	wglMakeCurrent(NULL,NULL);
    X=xmax;Y=ymax;Z=zmax;//給予初始值 
	maxx=a[0]*X+a[4]*Y+a[8]*Z+a[12];
    minx=maxx;
    maxy=a[1]*X+a[5]*Y+a[9]*Z+a[13];
    miny=maxy;
    maxz=a[2]*X+a[6]*Y+a[10]*Z+a[14];
    minz=maxz;
    AutoScaleCal(X,Y,Z,a,minx,maxx,miny,maxy,minz,maxz);
    X=xmax;Y=ymax;Z=zmin;
    AutoScaleCal(X,Y,Z,a,minx,maxx,miny,maxy,minz,maxz);
    X=xmax;Y=ymin;Z=zmax;
    AutoScaleCal(X,Y,Z,a,minx,maxx,miny,maxy,minz,maxz);
    X=xmin;Y=ymax;Z=zmax;
    AutoScaleCal(X,Y,Z,a,minx,maxx,miny,maxy,minz,maxz);
    X=xmin;Y=ymin;Z=zmin;
    AutoScaleCal(X,Y,Z,a,minx,maxx,miny,maxy,minz,maxz);
    X=xmin;Y=ymin;Z=zmax;
    AutoScaleCal(X,Y,Z,a,minx,maxx,miny,maxy,minz,maxz);
    X=xmin;Y=ymax;Z=zmin;
    AutoScaleCal(X,Y,Z,a,minx,maxx,miny,maxy,minz,maxz);
    X=xmax;Y=ymin;Z=zmin;
    AutoScaleCal(X,Y,Z,a,minx,maxx,miny,maxy,minz,maxz);
  
    d1=maxx-minx;
    d2=maxy-miny;
    if (d1>d2)
     { maxy=maxy+(d1-d2)/2.;
       miny=miny-(d1-d2)/2.;
       d2=d1;
     } 
    if (d1<d2)
     { maxx=maxx+(d2-d1)/2.;
       minx=minx-(d2-d1)/2.;
       d1=d2;
     } 
}

void OpenGLView::AutoScaleCal(double X, double Y, double Z, GLdouble *a, double &minx, double &maxx, double &miny, double &maxy, double &minz, double &maxz)
{
    double x1,y1,z1;

    x1=a[0]*X+a[4]*Y+a[8]*Z+a[12];
    y1=a[1]*X+a[5]*Y+a[9]*Z+a[13];
    z1=a[2]*X+a[6]*Y+a[10]*Z+a[14];
    if (x1<minx) minx=x1;
    if (x1>maxx) maxx=x1;
    if (y1<miny) miny=y1;
    if (y1>maxy) maxy=y1;
    if (z1<minz) minz=z1;
    if (z1>maxz) maxz=z1;
}

void OpenGLView::UpdateDrawView()
{
    Invalidate();
}

void OpenGLView::SetModelViewMatrix(double xth, double yth, double zth)
{
    wglMakeCurrent(m_hDC,m_hRC);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotated(xth,1.,0.,0.);
    glRotated(yth,0.,1.,0.);
	glRotated(zth,0.,0.,1.);
	wglMakeCurrent(NULL,NULL);
    UpdateDrawView();
}

BOOL OpenGLView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
    cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC, 
    LoadCursor(NULL,IDC_ARROW),NULL,NULL); 
    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN; 
    return CView::PreCreateWindow(cs); 
}

void OpenGLView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	wglMakeCurrent(m_hDC,m_hRC);
    if (m_hRC!=NULL)
	   wglDeleteContext(m_hRC);
    if (m_pDC)
       delete m_pDC;// delete the DC
	wglMakeCurrent(NULL,NULL);
}

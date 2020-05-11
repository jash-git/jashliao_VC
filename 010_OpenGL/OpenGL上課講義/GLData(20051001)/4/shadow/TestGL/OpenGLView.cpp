// OpenGLView.cpp : implementation file
//

#include "stdafx.h"
#include "TestGL.h"
#include "OpenGLView.h"
#include <math.h>

#define MaxViewID 5  //最大view記錄數目

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
	AxisXColor[0]=255;AxisXColor[1]=128;AxisXColor[2]=128;//座標X軸:淡紅
	AxisYColor[0]=128;AxisYColor[1]=255;AxisYColor[2]=128;//座標Y軸:淡青
	AxisZColor[0]=128;AxisZColor[1]=128;AxisZColor[2]=255;//座標Z軸:淡紫
	AxisList=0;
	FontList=0;
	EyeXMax=10.;EyeXMin=-10;EyeYMax=10.;EyeYMin=-10.;
	Show3DAxisType=2;
	Show3DAxisSize=120;
	CurrentViewState=0;
	ZoomWinFlag=FALSE;
	ResetRView();
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
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
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();	
	GLRender();
    glPopMatrix();
	Draw3DAxis();
	glFinish();       
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
	SetupList();
	CreateFont();
	Create3DAxis();
	TestFunc();
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
    glClearColor(1.,1.,1.,0.);// specify black as clear color
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
 	ObjXMax=xmax;ObjXMin=xmin;
	ObjYMax=ymax;ObjYMin=ymin;
	ObjZMax=zmax;ObjZMin=zmin;
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
	if (FontList>0)
	   glDeleteLists(FontList,256);
	if (AxisList>0)
       glDeleteLists(AxisList,1);
	wglMakeCurrent(NULL,NULL);
}

void OpenGLView::Create3DAxis()
{
    wglMakeCurrent(m_hDC,m_hRC);

	glMatrixMode(GL_PROJECTION);
    glPushMatrix();	
    glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();	
	glLoadIdentity();
    glNewList(AxisList,GL_COMPILE);
	  glBegin(GL_LINES);
		glColor3ubv(AxisXColor);//x axis
        glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(1.0f,0.0f,0.0f);
		glVertex3f(1.0f,0.0f,0.0f);
		glVertex3f(0.9f,0.1f,0.0f);
		glVertex3f(1.0f,0.0f,0.0f);
		glVertex3f(0.9f,-0.1f,0.0f);

		glColor3ubv(AxisYColor);//y axis
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(0.1f,0.9f,0.0f);
		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(-0.1f,0.9f,0.0f);

		glColor3ubv(AxisZColor);//z axis
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.1f,0.9f);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,-0.1f,0.9f);

	  glEnd();
	  GLPrintText(0.,0.,1.,"Z");
	  glColor3ubv(AxisXColor);
	  GLPrintText(1.,0.,0.,"X");
	  glColor3ubv(AxisYColor);
	  GLPrintText(0.,1.,0.,"Y");
	glEndList();
	glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();  
    wglMakeCurrent(NULL,NULL);
}

void OpenGLView::SetupList()
{
	wglMakeCurrent(m_hDC,m_hRC);
	FontList=glGenLists(256);
    AxisList=glGenLists(1);
	wglMakeCurrent(NULL,NULL);
}

void OpenGLView::GLPrintText(double x, double y, double z, const char *const string)
{
    glListBase(FontList);
    glRasterPos3d(x,y,z); 
    glCallLists(strlen(string),GL_UNSIGNED_BYTE,string);
    glListBase(0);
}


void OpenGLView::CreateFont()
{
	wglMakeCurrent(m_hDC,m_hRC);
    SelectObject(m_hDC, GetStockObject (SYSTEM_FONT));  
    wglUseFontBitmaps(m_hDC,0,255,FontList); 
    wglMakeCurrent(NULL,NULL);
}

void OpenGLView::Show3DAxis(int cx, int cy)
{
	glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glViewport((int)(cx-0.5*Show3DAxisSize),(int)(cy-0.5*Show3DAxisSize),Show3DAxisSize,Show3DAxisSize);
	glOrtho(-1.3,1.3,-1.3,1.3,-1.3,1.3);  
    glCallList(AxisList);
    glPopMatrix();
	glViewport(0,0,ScrWidth,ScrHeight);
}

void OpenGLView::Draw3DAxis()
{
	if (Show3DAxisType>0)
	 { int cx,cy;
       glDisable(GL_DEPTH_TEST);
	   switch(Show3DAxisType)
	    { case 1:cx=(int)(ScrWidth-0.5*Show3DAxisSize);
	             cy=(int)(0.5*Show3DAxisSize);
	             Show3DAxis(cx,cy);
   	             break;//右下角
		  case 2:ModelToScreen(0.,0.,0.,cx,cy);
			     Show3DAxis(cx,cy);
			     break;//座標原點
		  case 3:cx=(int)(0.5*ScrWidth);
	             cy=(int)(0.5*ScrHeight);
	             Show3DAxis(cx,cy);
				 break;//螢幕中間
          default:break;
	    }
	   glEnable(GL_DEPTH_TEST);
	 }
}

void OpenGLView::ModelToScreen(double x, double y, double z, int &cx, int &cy)
{
    GLdouble a[16],b[16];
    GLint c[4]; 
    GLdouble wx,wy,wz;
  
    glMatrixMode(GL_MODELVIEW);
    glGetDoublev(GL_MODELVIEW_MATRIX,a);
    glMatrixMode(GL_PROJECTION);
    glGetDoublev(GL_PROJECTION_MATRIX,b); 
    glGetIntegerv(GL_VIEWPORT,c);
    gluProject(x,y,z,a,b,c,&wx,&wy,&wz);
    cx=(int)wx; 
	cy=(int)wy;
}

void OpenGLView::SwitchViewState(int state)
{
    if (CurrentViewState==state)
	   CurrentViewState=0;
    else
       CurrentViewState=state;
}

int OpenGLView::GetViewState()
{
    return CurrentViewState;
}

void OpenGLView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
	switch (CurrentViewState)
	  { case 1:PointToVector(point.x,point.y,ScrWidth,ScrHeight,LastPosition);
	           break;//旋轉
	    case 2:MouseDownPoint=point;
	           break;//移動
	    case 3:MouseDownPoint=point;
		       break;//縮放
	    case 4:MouseCurPoint=point;
		       if (ZoomWinFlag==FALSE)
			    { MouseDownPoint=point;
				  ZoomWinFlag=TRUE; 
                }
			   else 
			    { ZoomWindow();
				  ZoomWinFlag=FALSE;
                }
			   break;//局部放大
	    default:break;
      }
}

void OpenGLView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
	switch (CurrentViewState)
	  { case 1:RecordView();
	           break;//旋轉   
	    case 2:RecordView();
	           break;//移動
	    case 3:RecordView();
		       break;//縮放
	    case 4:
	           break;//局部放大
	   default:break;
      }
}

void OpenGLView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
	switch (CurrentViewState)
     { case 1:if (MK_LBUTTON & nFlags)
	             RotateView(point);
	          break;//旋轉
       case 2:if (MK_LBUTTON & nFlags)
			     MoveView(point);
		  	  break;//移動
	   case 3:if (MK_LBUTTON & nFlags)   
                 ScaleView(point);
		      break;//縮放
	   case 4:if (ZoomWinFlag==TRUE)   //畫框
               { DrawRect(0,MouseDownPoint,MouseCurPoint);    //清除上一次的框
			     MouseCurPoint=point;
			     DrawRect(1,MouseDownPoint,MouseCurPoint);    //畫框
			   } 
		      break;//局部放大
       default:break;
     }
}

void OpenGLView::RotateView(CPoint pt)
{
	double current_position[3],axis[3],dx,dy,dz;
	GLdouble transform[4][4];

    PointToVector(pt.x,pt.y,ScrWidth,ScrHeight,current_position);
    /* calculate the angle to rotate by (directly proportional to the length of the mouse movement */
    dx=current_position[0]-LastPosition[0];
    dy=current_position[1]-LastPosition[1];
    dz=current_position[2]-LastPosition[2];
    double angle=90.0*sqrt(dx*dx+dy*dy+dz*dz);
    /* calculate the axis of rotation (cross product) */
    axis[0]=LastPosition[1]*current_position[2]-LastPosition[2]*current_position[1];
    axis[1]=LastPosition[2]*current_position[0]-LastPosition[0]*current_position[2];
    axis[2]=LastPosition[0]*current_position[1]-LastPosition[1]*current_position[0];
    /* reset for next time */
    LastPosition[0]=current_position[0];
    LastPosition[1]=current_position[1];
    LastPosition[2]=current_position[2];
	wglMakeCurrent(m_hDC,m_hRC);
	glMatrixMode(GL_MODELVIEW);
	glGetDoublev(GL_MODELVIEW_MATRIX, (GLdouble *)transform);
    glLoadIdentity();
    glRotated(angle,axis[0],axis[1],axis[2]);
	glMultMatrixd((GLdouble *)transform);
	wglMakeCurrent(NULL,NULL);
	Invalidate();
}

void OpenGLView::PointToVector(int x, int y, int width, int height, double v[])
{
    double d,a;

    /* project x, y onto a hemi-sphere centered within width, height. */
    v[0] = (2.0 * x - width) / width;
    v[1] = (height - 2.0 * y) / height;
    d = sqrt(v[0] * v[0] + v[1] * v[1]);
    v[2] = cos((3.14159265 / 2.0) * ((d < 1.0) ? d : 1.0));
    a = 1.0 / sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    v[0] *= a;
    v[1] *= a;
    v[2] *= a;
}

void OpenGLView::MoveView(CPoint pt)
{
	double dx,dy,step;

	dx=pt.x-MouseDownPoint.x;
    dy=pt.y-MouseDownPoint.y; 
	MouseDownPoint=pt;
    if (ScrWidth>ScrHeight)
       step=(EyeXMax-EyeXMin)/ScrWidth;
    else
       step=(EyeYMax-EyeYMin)/ScrHeight;
	dx=-dx*step;
    dy=dy*step;
	CreateProjMatrix(EyeXMax+dx,EyeXMin+dx,EyeYMax+dy,EyeYMin+dy);
	Invalidate();
}

void OpenGLView::ScaleView(CPoint pt)
{
    double step,dx,dy,dist;

	dx=pt.x-MouseDownPoint.x;
	dy=pt.y-MouseDownPoint.y;
	if (dx*dy>0)
	   dx=-dy;
	if (fabs(dx)>fabs(dy))
	   dist=-dx;
	else
	   dist=dy;
	MouseDownPoint=pt;
    double max=0.;
    if (EyeXMax-EyeXMin>max)
       max=EyeXMax-EyeXMin;
    if (EyeYMax-EyeYMin>max)
       max=EyeYMax-EyeYMin;
	if (ScrWidth>ScrHeight)
       step=max/ScrWidth;
    else
       step=max/ScrHeight;
    dist=dist*step;
    CreateProjMatrix(EyeXMax+dist,EyeXMin-dist,EyeYMax+dist,EyeYMin-dist); 	      
    Invalidate(); 
}

void OpenGLView::ZoomWindow()
{
    double x1,y1,x2,y2,ymax,ymin,xmax,xmin;
    if (MouseDownPoint.x>MouseCurPoint.x)
     { x1=MouseDownPoint.x;
       x2=MouseCurPoint.x;
     }
    else
     { x2=MouseDownPoint.x;
       x1=MouseCurPoint.x;
     }
    if (MouseDownPoint.y>MouseCurPoint.y)
     { y1=MouseDownPoint.y;
       y2=MouseCurPoint.y;
     }
    else
     { y2=MouseDownPoint.y;
       y1=MouseCurPoint.y;
     }
    xmax=EyeXMin+x1*(EyeXMax-EyeXMin)/ScrWidth;
    xmin=EyeXMin+x2*(EyeXMax-EyeXMin)/ScrWidth;
    ymax=EyeYMax-y2*(EyeYMax-EyeYMin)/ScrHeight;
    ymin=EyeYMax-y1*(EyeYMax-EyeYMin)/ScrHeight;
    CreateProjMatrix(xmax,xmin,ymax,ymin);
	UpdateDrawView();
}

void OpenGLView::DrawRect(int id, CPoint p1, CPoint p2)
{
    CPen *OldPen,Pen;

    if (id==1)
       Pen.CreatePen(PS_SOLID,0,RGB(255,255,255));  //白色
    else
     { Pen.CreatePen(PS_SOLID,1,RGB(255,255,255));  //清除
       m_pDC->SetROP2(R2_XORPEN);  //作XOR運算
     } 
    OldPen=m_pDC->SelectObject(&Pen);
    m_pDC->MoveTo(p1.x,p1.y);
    m_pDC->LineTo(p1.x,p2.y);
    m_pDC->LineTo(p2.x,p2.y);
    m_pDC->LineTo(p2.x,p1.y);
    m_pDC->LineTo(p1.x,p1.y); 
    m_pDC->SelectObject(OldPen);
}

//記錄目前的VIEW
void OpenGLView::RecordView()
{
    int i;
    GLdouble a[16];
    bool same=true;

	wglMakeCurrent(m_hDC,m_hRC);
    glMatrixMode(GL_MODELVIEW);
    glGetDoublev(GL_MODELVIEW_MATRIX,a); 
	wglMakeCurrent(NULL,NULL);
    if (CurrentViewID>=0&&CurrentViewID<MaxViewID)
     { for (i=0;i<16;i++)
	       if (a[i]!=RecordViewXYZ[CurrentViewID][i])
		      same=false;
       if (RecordViewXYZ[CurrentViewID][16]==EyeXMin&&
	       RecordViewXYZ[CurrentViewID][17]==EyeXMax&&
	       RecordViewXYZ[CurrentViewID][18]==EyeYMin&&
	       RecordViewXYZ[CurrentViewID][19]==EyeYMax&&same==true)
	       return;
     }
    CurrentViewID=CurrentViewID+1;
    if (CurrentViewID>MaxViewID-1)
	   CurrentViewID=0;
    for (i=0;i<16;i++)
	   RecordViewXYZ[CurrentViewID][i]=a[i];
    RecordViewXYZ[CurrentViewID][16]=EyeXMin;
    RecordViewXYZ[CurrentViewID][17]=EyeXMax;
    RecordViewXYZ[CurrentViewID][18]=EyeYMin;
    RecordViewXYZ[CurrentViewID][19]=EyeYMax;
    RecordViewF[CurrentViewID]=true;
}

void OpenGLView::ResetRView()
{
    for (int i=0;i<MaxViewID;i++)
	  { RecordViewF[i]=false;
	    for (int j=0;j<20;j++)
		    RecordViewXYZ[i][j]=0.;
      }
    CurrentViewID=-1;
}

void OpenGLView::CallPreView()
{
    int i,id;
    GLdouble a[16];
    bool exit=false;
  
    if (CurrentViewID<0)
	   return;
    id=CurrentViewID;
    do
     { id=id-1;
       if (id==CurrentViewID)
	      exit=true;
	   if (id<0)
	      id=4;
     } while(RecordViewF[id]==false&&exit==false);
    if (exit==true||RecordViewF[id]==false)
	   return;
    CurrentViewID=id;
    for (i=0;i<16;i++)
	    a[i]=RecordViewXYZ[CurrentViewID][i];
    wglMakeCurrent(m_hDC,m_hRC);
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(a);
	wglMakeCurrent(NULL,NULL);
    EyeXMin=RecordViewXYZ[CurrentViewID][16];
    EyeXMax=RecordViewXYZ[CurrentViewID][17];
    EyeYMin=RecordViewXYZ[CurrentViewID][18];
    EyeYMax=RecordViewXYZ[CurrentViewID][19];
	CreateProjMatrix(EyeXMax,EyeXMin,EyeYMax,EyeYMin);
	Invalidate();
}

void OpenGLView::TestFunc()
{
}

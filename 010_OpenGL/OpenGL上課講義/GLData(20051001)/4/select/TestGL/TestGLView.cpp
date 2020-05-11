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
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
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
    CreateLineData();
	SelWinFlag=FALSE;
}

CTestGLView::~CTestGLView()
{
	delete [] LineRecord;
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
    for (int i=0;i<12;i++)
		LineRecord[i].Draw();
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

void CTestGLView::CreateLineData()
{
    LineRecord=new LineData [12];
	LineRecord[0].SetData( 100., 100., 100.,-100., 100., 100.);
	LineRecord[1].SetData(-100., 100., 100.,-100.,-100., 100.);
	LineRecord[2].SetData(-100.,-100., 100., 100.,-100., 100.);
	LineRecord[3].SetData( 100.,-100., 100., 100., 100., 100.);

	LineRecord[4].SetData( 100., 100.,-100.,-100., 100.,-100.);
	LineRecord[5].SetData(-100., 100.,-100.,-100.,-100.,-100.);
	LineRecord[6].SetData(-100.,-100.,-100., 100.,-100.,-100.);
	LineRecord[7].SetData( 100.,-100.,-100., 100., 100.,-100.);

	LineRecord[8].SetData( 100., 100., 100., 100., 100.,-100.);
	LineRecord[9].SetData(-100., 100., 100.,-100., 100.,-100.);
	LineRecord[10].SetData(-100.,-100., 100.,-100.,-100.,-100.);
	LineRecord[11].SetData( 100.,-100., 100., 100.,-100.,-100.);
	SetDataNum(12);
}


void CTestGLView::SelectObjName()
{
   	glInitNames();
    glPushName(0);
    for (int i=0;i<12;i++)
	  { glLoadName(i+1);
	    LineRecord[i].Draw();
	  }
	glLoadName(0);     
}

void CTestGLView::SetSelect(int index, bool selflag)
{
    LineRecord[index].SetSelect(selflag);
}

void CTestGLView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	OpenGLView::OnLButtonDown(nFlags, point);

	bool selflag;
   	if (CurrentViewState==0)
	 { MouseCurPoint=point;
	   if (nFlags&MK_SHIFT)
	      selflag=false;
	   else
	      selflag=true;
	   if (SelWinFlag==FALSE)
	    { if (SelectDraw(point.x,point.y,selflag)==0)
		   { MouseDownPoint=point; 
		     SelWinFlag=TRUE; 
		   }
		}
       else
	    { SelWinFlag=FALSE;
	      SelectDraw(MouseDownPoint.x,MouseDownPoint.y,point.x,point.y,selflag); 
		}
     }
}

void CTestGLView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	OpenGLView::OnMouseMove(nFlags, point);

	if (CurrentViewState==0)
	 { if (SelWinFlag==TRUE)
        { DrawRect(0,MouseDownPoint,MouseCurPoint);    //清除上一次的框
	      MouseCurPoint=point;
		  DrawRect(1,MouseDownPoint,MouseCurPoint);    //畫框
		} 
	 }
}

void CTestGLView::SetDataNum(unsigned long num)
{
    DataNum=num;
}

int CTestGLView::SelectDraw(int cx, int cy, bool selflag)
{
    int size=4;

	GLuint *selectBuff=new GLuint[size];
    int sel=SelectDraw(selectBuff,size,cx,cy,4,4);

	if (sel>0)
	 { SetSelect(selectBuff[3]-1,selflag);
	   Invalidate();
	 }
	delete [] selectBuff;
    return sel;
}

int CTestGLView::SelectDraw(GLuint *selectBuff, int size, int cx, int cy, int wx, int wy)
{
	GLint hits,viewport[4];
	wglMakeCurrent(m_pDC->GetSafeHdc(),m_hRC);
	glSelectBuffer(size,selectBuff);// Setup selection buffer
	glMatrixMode(GL_PROJECTION);// Switch to projection and save the matrix
	glPushMatrix();
	glGetIntegerv(GL_VIEWPORT,viewport);	// Get the viewport  
  	glRenderMode(GL_SELECT);// Change render mode
	glLoadIdentity();
    gluPickMatrix(cx,viewport[3]-cy,wx,wy,viewport);
    glOrtho(EyeXMin,EyeXMax,EyeYMin,EyeYMax,EyeZMin,EyeZMax);

	SelectObjName();

	hits=glRenderMode(GL_RENDER);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
	wglMakeCurrent(NULL,NULL);
    return hits;
}

void CTestGLView::SelectDraw(int x1, int y1, int x2, int y2, bool selflag)
{
    if (DataNum==0)
	   return;
	int size=DataNum*4;
	GLuint *selectBuff=new GLuint[size];

	int cx,cy,wx,wy;

	cx=(x1+x2)/2;
	cy=(y1+y2)/2;
	if (x1>x2)
	   wx=x1-x2;
	else
	   wx=x2-x1;
    if (y1>y2)
	   wy=y1-y2;
	else
	   wy=y2-y1;
    int sel=SelectDraw(selectBuff,size,cx,cy,wx,wy);

	for (int i=0;i<sel;i++)
	    SetSelect(selectBuff[3+i*4]-1,selflag);
	delete [] selectBuff;
	Invalidate();
}


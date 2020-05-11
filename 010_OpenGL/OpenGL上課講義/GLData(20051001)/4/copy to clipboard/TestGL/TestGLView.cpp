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
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
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
    glBegin(GL_LINE_STRIP);
      glVertex3f(100.,100.,100.);
      glVertex3f(-100.,100.,100.);
	  glVertex3f(-100.,-100.,100.);
	  glVertex3f(100.,-100.,100.);
	  glVertex3f(100.,100.,100.);
	glEnd();

	glBegin(GL_LINE_STRIP);
      glVertex3f(100.,100.,-100.);
      glVertex3f(-100.,100.,-100.);
	  glVertex3f(-100.,-100.,-100.);
	  glVertex3f(100.,-100.,-100.);
	  glVertex3f(100.,100.,-100.);
	glEnd();

	glBegin(GL_LINES);
      glVertex3f(100.,100.,100.);
      glVertex3f(100.,100.,-100.);
	glEnd();
	glBegin(GL_LINES);
      glVertex3f(-100.,100.,100.);
      glVertex3f(-100.,100.,-100.);
	glEnd();
	glBegin(GL_LINES);
      glVertex3f(-100.,-100.,100.);
      glVertex3f(-100.,-100.,-100.);
	glEnd();
	glBegin(GL_LINES);
      glVertex3f(100.,-100.,100.);
      glVertex3f(100.,-100.,-100.);
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

void CTestGLView::OnEditCopy() 
{
	// TODO: Add your command handler code here
	wglMakeCurrent(m_hDC,m_hRC);
	BeginWaitCursor(); 

    // Get client geometry 
    CRect rect; 
    GetClientRect(&rect); 
    CSize size(rect.Width(),rect.Height()); 
    //size.cx -= size.cx % 4; 
    // Create a bitmap and select it in the device context 
    // Note that this will never be used ;-) but no matter 
    CBitmap bitmap; 
    CDC *pDC = GetDC(); 
    CDC MemDC; 
    ASSERT(MemDC.CreateCompatibleDC(NULL)); 
    ASSERT(bitmap.CreateCompatibleBitmap(pDC,size.cx,size.cy)); 
    MemDC.SelectObject(&bitmap); 
    // Alloc pixel bytes 
    int NbBytes = 3 * size.cx * size.cy; 
    GLubyte *pPixelData = new GLubyte[NbBytes]; 
    // Copy from OpenGL 
    glReadPixels(0,0,size.cx,size.cy,GL_BGR_EXT,GL_UNSIGNED_BYTE,pPixelData); 
    // Fill header 
    BITMAPINFOHEADER header; 
    header.biWidth = size.cx; 
    header.biHeight = size.cy; 
    header.biSizeImage = NbBytes; 
    header.biSize = sizeof(BITMAPINFOHEADER);
    header.biPlanes = 1; 
    header.biBitCount =  3 * 8; // RGB 
    header.biCompression = 0; 
    header.biXPelsPerMeter = 0; 
    header.biYPelsPerMeter = 0; 
    header.biClrUsed = 0; 
    header.biClrImportant = 0; 
    // Generate handle 
    HANDLE handle = (HANDLE)GlobalAlloc (GHND,sizeof(BITMAPINFOHEADER) + NbBytes); 
    if (handle != NULL) 
     { // Lock handle 
       char *pData = (char *)GlobalLock((HGLOBAL)handle); 
       // Copy header and data 
       memcpy(pData,&header,sizeof(BITMAPINFOHEADER)); 
       memcpy(pData+sizeof(BITMAPINFOHEADER),pPixelData,NbBytes); 
       // Unlock 
       GlobalUnlock((HGLOBAL)handle); 
       // Push DIB in clipboard 
       OpenClipboard(); 
       EmptyClipboard(); 
       SetClipboardData(CF_DIB,handle); 
       CloseClipboard(); 
     }
    // Cleanup 
    MemDC.DeleteDC(); 
    bitmap.DeleteObject(); 
    delete [] pPixelData; 
    EndWaitCursor(); 
	wglMakeCurrent(NULL,NULL);
}

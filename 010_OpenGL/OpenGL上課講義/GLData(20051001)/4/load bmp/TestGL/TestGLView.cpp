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
    BitmapBits=NULL;
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
	if (BitmapBits!=NULL)
	   DrawImage();
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

void CTestGLView::DrawImage()
{
    int wx,wy;

	ModelToScreen(0.,0.,0.,wx,wy);
	glMatrixMode(GL_PROJECTION);
    glPushMatrix(); 
	glViewport(wx,wy,ScrWidth,ScrHeight);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLfloat)ScrWidth,0.0,(GLfloat)ScrHeight);
    glRasterPos3d(0.,0.,0.);
    glPixelZoom(ImageViewScaleX,ImageViewScaleY);
    glDrawPixels(ImageWidth,ImageHeight,GL_BGR_EXT,GL_UNSIGNED_BYTE,BitmapBits);
	glPopMatrix();
	glViewport(0,0,ScrWidth,ScrHeight);
	glMatrixMode(GL_MODELVIEW);
}

GLubyte *CTestGLView::LoadDIBitmap(LPCTSTR filename, BITMAPINFO **info)
{
	FILE             *fp;          // Open file pointer
    GLubyte          *bits;        // Bitmap pixel bits
    unsigned int     bitsize;      // Size of bitmap
    unsigned int     infosize;     // Size of header information
    BITMAPFILEHEADER header;       // File header


    // Try opening the file; use "rb" mode to read this *binary* file.
    if ((fp=fopen(filename,"rb"))==NULL)
       return (NULL);

    // Read the file header and any following bitmap information...
    if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1)
     { // Couldn't read the file header - return NULL...
	   fclose(fp);
       return (NULL);
     }
    if (header.bfType != 'MB')	// Check for BM reversed...
     { // Not a bitmap file - return NULL...
        fclose(fp);
        return (NULL);
     }
    infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
    if ((*info = (BITMAPINFO *)malloc(infosize)) == NULL)
     { // Couldn't allocate memory for bitmap info - return NULL...
       fclose(fp);
       return (NULL);
     }
    if (fread(*info, 1, infosize, fp) < infosize)
     { // Couldn't read the bitmap header - return NULL...
       free(*info);
       fclose(fp);
       return (NULL);
     }
    // Now that we have all the header info read in, allocate memory for
    // the bitmap and read *it* in...                                   
    if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
        bitsize = ((*info)->bmiHeader.biWidth *
                   (*info)->bmiHeader.biBitCount + 7) / 8 *
  	           abs((*info)->bmiHeader.biHeight);

	bits=new GLubyte [bitsize];
    if (bits == NULL)
     { // Couldn't allocate memory - return NULL!
       free(*info);
       fclose(fp);
       return (NULL);
     }

    if (fread(bits, 1, bitsize, fp) < bitsize)
     { // Couldn't read bitmap - free memory and return NULL!
       free(*info);
       free(bits);
       fclose(fp);
       return (NULL);
     }
    // OK, everything went fine - return the allocated bitmap...
    fclose(fp);
    return (bits);
}

bool CTestGLView::LoadImageFile(LPCTSTR filename)
{
	BITMAPINFO *BitmapInfo;

    BitmapBits=LoadDIBitmap(filename,&BitmapInfo);
	if (BitmapBits==NULL)
	   return false;
      
	long xpi,ypi;

    xpi=(long)(BitmapInfo->bmiHeader.biXPelsPerMeter*25.4/1000.);
    ypi=(long)(BitmapInfo->bmiHeader.biYPelsPerMeter*25.4/1000.);
	if (xpi<=0)
       xpi=96;
	if (ypi<=0)
       ypi=96;
	ImageWidth=BitmapInfo->bmiHeader.biWidth;
	ImageHeight=BitmapInfo->bmiHeader.biHeight;
    ImageXMax=25.4*BitmapInfo->bmiHeader.biWidth/xpi;
    ImageYMax=25.4*BitmapInfo->bmiHeader.biHeight/ypi;
    ImagePixelScaleX=ImageXMax/ImageWidth;
    ImagePixelScaleY=ImageYMax/ImageHeight;
	SetObjXYZRange(ImageXMax,0.,ImageYMax,0.,10.,-10.,true);

	free(BitmapInfo);
    return true;
}

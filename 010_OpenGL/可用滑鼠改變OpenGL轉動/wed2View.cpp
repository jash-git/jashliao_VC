// wed2View.cpp : implementation of the CWed2View class
//

#include "stdafx.h"
#include "wed2.h"

#include "wed2Doc.h"
#include "wed2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include <gl/gl.h>
#include <gl/glu.h>


/////////////////////////////////////////////////////////////////////////////
// CWed2View

IMPLEMENT_DYNCREATE(CWed2View, CView)

BEGIN_MESSAGE_MAP(CWed2View, CView)
	//{{AFX_MSG_MAP(CWed2View)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWed2View construction/destruction

CWed2View::CWed2View()
{
	// TODO: add construction code here
	m_xpos = 0.0f;
	m_ypos = 200.0f;
	m_zoom = 1000.0f;
	m_xrot = 0.0f;
	m_yrot = 0.0f;

	m_pDocument = NULL;
}

CWed2View::~CWed2View()
{
}

BOOL CWed2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.lpszClass = ::AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC,
		::LoadCursor(NULL, IDC_ARROW), NULL, NULL);
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
    cs.cx = 800;
    cs.cy = 200;

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWed2View drawing

#define SIZE	400.0f
#define STEP	80.0f

void DrawGrid( void )
{
	float f;

	glColor3f(0.4f, 0.4f, 0.4f);

	glBegin(GL_LINES);
	for(f = -SIZE; f <= SIZE; f+= STEP )
	{
		glVertex3f(f, 0.0f, -SIZE);
		glVertex3f(f, 0.0f, SIZE);
	}
	for(f = -SIZE; f <= SIZE; f+= STEP )
	{
		glVertex3f(SIZE, 0.0f, f);
		glVertex3f(-SIZE, 0.0f, f);
	}
	glEnd();
}

void CWed2View::OnDraw(CDC* pDC)
{
	CWed2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
    CPaintDC dc(this); // Needed 

	// Useful in multidoc templates
	HWND hWnd = GetSafeHwnd();
	HDC hDC = ::GetDC(hWnd);
	wglMakeCurrent(hDC,m_hglrc);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix


	// Position the camera
	glTranslatef( m_xpos, -m_ypos, -m_zoom );

	// Rotate the camera
	glRotatef( m_xrot, 1.0f, 0.0f, 0.0f );
	glRotatef( m_yrot, 0.0f, 1.0f, 0.0f );

	DrawGrid();

	// XYZ axis lines
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();

	if(GetDocument() != NULL )
		GetDocument()->draw();

    SwapBuffers(m_hgldc);
	
}

/////////////////////////////////////////////////////////////////////////////
// CWed2View diagnostics

#ifdef _DEBUG
void CWed2View::AssertValid() const
{
	CView::AssertValid();
}

void CWed2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWed2Doc* CWed2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWed2Doc)));
	return (CWed2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWed2View message handlers

int CWed2View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_hgldc = ::GetDC(m_hWnd);

    if(!SetPixelformat(m_hgldc))
    {
	::MessageBox(::GetFocus(),"SetPixelformat Failed!","Error",MB_OK);
	return -1;
    }

    m_hglrc = wglCreateContext(m_hgldc);
    int i= wglMakeCurrent(m_hgldc,m_hglrc);

	InitGL();

	return 0;
}

void CWed2View::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	if(wglGetCurrentContext() != NULL)
		wglMakeCurrent(NULL,NULL);
	
	if(m_hglrc != NULL)
	{
		wglDeleteContext(m_hglrc);
		m_hglrc = NULL;
	}
	
}

BOOL CWed2View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CView::OnEraseBkgnd(pDC);
	//return TRUE;
}

void CWed2View::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	int width;
	int height;

	width = cx;
	height = cy;

	ReSizeGLScene((int) width, (int) height);
}


BOOL CWed2View::SetPixelformat(HDC hdc)
{

    PIXELFORMATDESCRIPTOR *ppfd; 
    int pixelformat; 
 
    PIXELFORMATDESCRIPTOR pfd = { 
    sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd 
    1,                     // version number 
    PFD_DRAW_TO_WINDOW |   // support window 
    PFD_SUPPORT_OPENGL |   // support OpenGL 
    PFD_GENERIC_FORMAT |
    PFD_DOUBLEBUFFER,      // double buffered 
    PFD_TYPE_RGBA,         // RGBA type 
    32,                    // 24-bit color depth 
    0, 0, 0, 0, 0, 0,      // color bits ignored 
    8,                     // no alpha buffer 
    0,                     // shift bit ignored 
    8,                     // no accumulation buffer 
    0, 0, 0, 0,            // accum bits ignored 
    64,                    // 32-bit z-buffer	 
    8,                     // no stencil buffer 
    8,                     // no auxiliary buffer 
    PFD_MAIN_PLANE,        // main layer 
    0,                     // reserved 
    0, 0, 0                // layer masks ignored 
    }; 

   
    ppfd = &pfd;

 
    if ( (pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0 ) 
    { 
        ::MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK); 
        return FALSE; 
    } 
 
    if (SetPixelFormat(hdc, pixelformat, ppfd) == FALSE) 
    { 
        ::MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK); 
        return FALSE; 
    } 
 
    return TRUE; 

}

void CWed2View::ReSizeGLScene(int width, int height)	// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(60.0f,(float)width/(float)height,1.0f,5000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix

}


int CWed2View::InitGL(void)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.7f, 1.0f, 1.0f, 0.0f);				// Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	return TRUE;										// Initialization Went OK
}





void CWed2View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// Move the camera 

	if ( nFlags & MK_LBUTTON )
	{
		if( nFlags & MK_SHIFT )
		{
			// SHIFT is being
			// pressed. Zoom the camera.
			if ( m_lastMouseY != -1 )
			{
				m_zoom += 10.0f * (point.y - m_lastMouseY);
				// Redraw the viewport.
				OnDraw( NULL );
			}
			m_lastMouseY = point.y;
		}
		else if ( nFlags & MK_CONTROL )
		{
			// CONTROL is being
			// pressed. Pan the camera.
			if ( m_lastMouseX != -1 )
			{
				m_xpos += (point.x - m_lastMouseX) * 5.0f;
				m_ypos += (point.y - m_lastMouseY) * 5.0f;
				// Redraw the viewport.
				OnDraw( NULL );
			}
			m_lastMouseX = point.x;
			m_lastMouseY = point.y;
		}
		else
		{
			// Left mouse button is being
			// pressed. Rotate the camera.
			if ( m_lastMouseX != -1 )
			{
				m_xrot += point.y - m_lastMouseY;
				m_yrot += point.x - m_lastMouseX;
				// Redraw the viewport.
				OnDraw( NULL );
			}
			m_lastMouseX = point.x;
			m_lastMouseY = point.y;
		}
	}
	else
	{
		m_lastMouseX = -1;
		m_lastMouseY = -1;
	}

	CView::OnMouseMove(nFlags, point);
}

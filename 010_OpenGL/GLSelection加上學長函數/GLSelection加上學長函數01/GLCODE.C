// glcode.c
// Put/Port your OpenGL 'C' code here.  You can also include this
// in the C++ source file, but this provides an easy way to isolate
// existing code, or make for plug & play OpenGL samples.

// Requisite headers
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include "glcode.h"


// Easier way to specify color for Windows bigots
#define glRGB(x, y, z)	glColor3ub((GLubyte)x, (GLubyte)y, (GLubyte)z)


// Lighting components
GLfloat  ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  diffuseLight[] = { 0.6f, 0.6f, 0.6f, 1.0f };
GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat	 lightPos[] = { -60.0f, 25.0f, 50.0f, 1.0f };



//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// Do any initialization of the rendering context here, such as
// setting background colors, setting up lighting, or performing
// preliminary calculations.
void GLSetupRC(void *pData)
	{
	HDC hDC;
	HFONT hFont;
	GLYPHMETRICSFLOAT agmf[256]; // Throw away
	LOGFONT logfont;

	logfont.lfHeight = -10;
	logfont.lfWidth = 0;
	logfont.lfEscapement = 0;
	logfont.lfOrientation = 0;
	logfont.lfWeight = FW_BOLD;
	logfont.lfItalic = FALSE;
	logfont.lfUnderline = FALSE;
	logfont.lfStrikeOut = FALSE;
	logfont.lfCharSet = ANSI_CHARSET;
	logfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	logfont.lfQuality = DEFAULT_QUALITY;
	logfont.lfPitchAndFamily = DEFAULT_PITCH;
	strcpy(logfont.lfFaceName,"Arial");



	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glEnable(GL_LIGHT0);


	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR,specular);
	glMateriali(GL_FRONT,GL_SHININESS,100);

	// Blue 3D Text
	glRGB(0, 0, 255);

	hDC = (HDC)pData;
	hFont = CreateFontIndirect(&logfont);
	SelectObject (hDC, hFont); 

	
	//create display lists for glyphs 0 through 255 with 0.1 extrusion 
	// and default deviation. The display list numbering starts at 1000 
	// (it could be any number). 
	wglUseFontOutlines(hDC, 0, 255, 1000, 0.0f, 0.3f, 
				WGL_FONT_POLYGONS, agmf); 

	DeleteObject(hFont);
 	}



//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// Called by Windows when it receives the WM_SIZE message.
// Put any code needed here to recalc the viewing volume and
// viewport info
void GLResize(GLsizei w, GLsizei h)
	{
	GLfloat nRange = 120.0f;

	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	// Set Viewport to window dimensions
    glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	// Reset coordinate system
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
    if (w <= h) 
		glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    else 
		glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

	// Set up transformation to draw the string. 
	glTranslatef(-35.0f, 0.0f, -5.0f) ;
	glScalef(60.0f, 60.0f, 60.0f); 

	glMatrixMode(GL_MODELVIEW);
	}



//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// Render your OpenGL Scene here.
void GLRenderScene(void *pData)
	{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Rotate
	glRotatef(3.0f,0.0f, 0.0f, 1.0f); // Rock Z
	glRotatef(3.0f,1.0f, 0.0f, 0.0f); // Roll X

	// Draw the string
	glListBase(1000);
	glPushMatrix();
	glCallLists (3, GL_UNSIGNED_BYTE, "MFC"); 
	glPopMatrix();

	// Flush drawing commands
	glFlush();
	}



/*
 * F-16 program from Chapter 12.
 *
 * Written by Michael Sweet
 */

#include <GL/glut.h>
#include <math.h>
#ifndef M_PI
#  define M_PI	(double)3.14159265358979323846
#endif /* !M_PI */
#include "texture.h"


/*
 * Globals...
 */

int        Width;             /* Width of window */
int        Height;            /* Height of window */
GLuint     F16Body,           /* F-16 body */
           F16Rolleron[2];    /* F-16 rollerons */
GLuint     F16Texture[2];     /* Camoflage texture objects */
double     LastTime;          /* Last update time */
int	   MouseStartX;       /* Initial mouse X position */
int        MouseStartY;       /* Initial mouse Y position */
int	   MouseX;            /* Mouse X position */
int        MouseY;            /* Mouse Y position */
int        UseTexturing = 1;  /* Use texture mapping? */
GLfloat	   Orientation[3] =   /* Orientation of viewer */
    {
    15.0, 45.0, 30.0
    };


/*
 * Functions...
 */

void   BuildF16(void);
void   APIENTRY glu_vertex(GLdouble *xyz);
double GetClock(void);
void   Idle(void);
void   Keyboard(unsigned char key, int x, int y);
void   Joystick(unsigned state, int x, int y, int z);
void   Motion(int x, int y);
void   Mouse(int button, int state, int x, int y);
void   Redraw(void);
void   Resize(int width, int height);


/*
 * 'main()' - Open a window and display a sphere and cube.
 */

int                /* O - Exit status */
main(int  argc,    /* I - Number of command-line arguments */
     char *argv[]) /* I - Command-line arguments */
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(792, 573);
    glutCreateWindow("F-16 Using Quadrics and GLU Polygons");

    glutDisplayFunc(Redraw);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(Mouse);
    glutMotionFunc(Motion);
    glutReshapeFunc(Resize);
    if (glutDeviceGet(GLUT_HAS_JOYSTICK))
        glutJoystickFunc(Joystick, 100);

    BuildF16();

    glutMainLoop();
    return (0);
    }


/*
 * 'BuildF16()' - Build the F-16 model.
 */

void
BuildF16(void)
    {
    int                i;           /* Looping var */
    GLUquadric         *quadric;    /* Quadric object */
#ifdef GLU_VERSION_1_2
    GLUtesselator      *tess;       /* Tesselator object */
#else
    GLUtriangulatorObj *tess;
#endif /* GLU_VERSION_1_2 */
    static GLdouble    wing[][5] =  /* Main wing points */
        {
	/* { x, y, z, s, t } */
	{  0.25, 0.0, -1.0,  0.125, 0.0 },
	{  0.45, 0.0,  0.0,  0.25,  0.4 },
	{  1.65, 0.0,  0.8,  1.0,   0.8 },
	{  1.65, 0.0,  1.2,  1.0,   1.0 },
	{  0.35, 0.0,  1.2,  0.15,  1.0 },
	{  0.35, 0.0,  2.4,  0.15,  2.0 },
	{  0.25, 0.0,  2.4,  0.125, 2.0 },
	{  0.25, 0.0,  2.0,  0.125, 1.5 },
	{ -0.25, 0.0,  2.0, -0.125, 1.5 },
	{ -0.25, 0.0,  2.4, -0.125, 2.0 },
	{ -0.35, 0.0,  2.4, -0.15,  2.0 },
	{ -0.35, 0.0,  1.2, -0.15,  1.0 },
	{ -1.65, 0.0,  1.2, -1.0,   1.0 },
	{ -1.65, 0.0,  0.8, -1.0,   0.8 },
	{ -0.45, 0.0,  0.0, -0.25,  0.4 },
	{ -0.25, 0.0, -1.0, -0.125, 0.0 }
        };
    static GLdouble    tail[][5] =      /* Tail points */
        {
	/* { x, y, z, s, t } */
	{ 0.0, 0.24, 0.5, 1.5, 0.0 },
	{ 0.0, 0.4,  1.1, 1.2, 0.1 },
	{ 0.0, 1.0,  2.0, 0.4, 1.0 },
	{ 0.0, 1.0,  2.4, 0.05, 1.0 },
	{ 0.0, 0.4,  2.1, 0.2, 0.1 },
	{ 0.0, 0.24, 2.1, 0.2, 0.0 }
	};
    static GLdouble    left_fin[][5] =  /* Left fin points */
        {
	/* { x, y, z, s, t } */
	{ -0.1,  -0.1, 1.1, 0.0, 0.0 },
	{ -0.25, -0.3, 1.2, 1.0, 0.0 },
	{ -0.25, -0.3, 1.5, 1.0, 1.0 },
	{ -0.1,  -0.1, 1.5, 1.0, 0.0 }
	};
    static GLdouble    right_fin[][5] = /* Right fin points */
        {
	/* { x, y, z, s, t } */
	{ 0.1,  -0.1, 1.1, 0.0, 0.0 },
	{ 0.25, -0.3, 1.2, 1.0, 0.0 },
	{ 0.25, -0.3, 1.5, 1.0, 1.0 },
	{ 0.1,  -0.1, 1.5, 1.0, 0.0 }
	};
    static GLdouble    left_rolleron[][5] =  /* Left rolleron points */
        {
	/* { x, y, z, s, t } */
	{ -0.35, 0.0, 1.6, 0.0, 0.0 },
	{ -0.85, 0.0, 2.1, 1.0, 0.5 },
	{ -0.85, 0.0, 2.4, 1.0, 1.0 },
	{ -0.35, 0.0, 2.4, 0.0, 1.0 }
	};
    static GLdouble    right_rolleron[][5] = /* Right rolleron points */
        {
	/* { x, y, z, s, t } */
	{ 0.35, 0.0, 1.6, 0.0, 0.0 },
	{ 0.85, 0.0, 2.1, 1.0, 0.5 },
	{ 0.85, 0.0, 2.4, 1.0, 1.0 },
	{ 0.35, 0.0, 2.4, 0.0, 1.0 }
	};

    /* Load the texture images */
    F16Texture[0] = TextureLoad("camoflage.bmp", GL_FALSE, GL_NEAREST,
                                GL_NEAREST, GL_REPEAT);
    F16Texture[1] = TextureLoad("tail.bmp", GL_FALSE, GL_NEAREST,
                                GL_NEAREST, GL_REPEAT);

    /* Then build the F-16 body */
    F16Body = glGenLists(1);
    glNewList(F16Body, GL_COMPILE);
    glBindTexture(GL_TEXTURE_2D, F16Texture[0]);

    tess = gluNewTess();
    gluTessCallback(tess, GLU_TESS_BEGIN, glBegin);
    gluTessCallback(tess, GLU_TESS_END, glEnd);
    gluTessCallback(tess, GLU_TESS_VERTEX, (void (CALLBACK *)())glu_vertex);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);

    /* Main fuselage */
    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
        glTranslatef(0.0, 0.0, -1.5);
	gluCylinder(quadric, 0.25, 0.25, 3.5, 20, 2);
    glPopMatrix();

    /* Nose */
    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
        glTranslatef(0.0, 0.0, -2.5);
	gluCylinder(quadric, 0.0, 0.25, 1.0, 20, 2);
    glPopMatrix();

    /* Main wing */
    glColor3f(0.8, 0.8, 0.8);
    glNormal3f(0.0, 1.0, 0.0);
    gluTessBeginPolygon(tess, NULL);
#ifdef GL_VERSION_1_2
    gluTessBeginContour(tess);
#endif /* GL_VERSION_1_2 */

    for (i = 0; i < 16; i ++)
        gluTessVertex(tess, wing[i], wing[i]);

#ifdef GL_VERSION_1_2
    gluTessEndContour(tess);
#endif /* GL_VERSION_1_2 */
    gluTessEndPolygon(tess);

    /* Fins */
    glColor3f(0.8, 0.8, 0.8);
    glNormal3f(-1.0, 0.0, 0.0);
    gluTessBeginPolygon(tess, NULL);
#ifdef GL_VERSION_1_2
    gluTessBeginContour(tess);
#endif /* GL_VERSION_1_2 */

    for (i = 0; i < 4; i ++)
        gluTessVertex(tess, left_fin[i], left_fin[i]);

#ifdef GL_VERSION_1_2
    gluTessEndContour(tess);
#endif /* GL_VERSION_1_2 */
    gluTessEndPolygon(tess);

    glColor3f(0.8, 0.8, 0.8);
    glNormal3f(1.0, 0.0, 0.0);
    gluTessBeginPolygon(tess, NULL);
#ifdef GL_VERSION_1_2
    gluTessBeginContour(tess);
#endif /* GL_VERSION_1_2 */

    for (i = 0; i < 4; i ++)
        gluTessVertex(tess, right_fin[i], right_fin[i]);

#ifdef GL_VERSION_1_2
    gluTessEndContour(tess);
#endif /* GL_VERSION_1_2 */
    gluTessEndPolygon(tess);

    /* Tail */
    glBindTexture(GL_TEXTURE_2D, F16Texture[1]);
    glColor3f(0.8, 0.8, 0.8);
    glNormal3f(1.0, 0.0, 0.0);
    gluTessBeginPolygon(tess, NULL);
#ifdef GL_VERSION_1_2
    gluTessBeginContour(tess);
#endif /* GL_VERSION_1_2 */

    for (i = 0; i < 6; i ++)
        gluTessVertex(tess, tail[i], tail[i]);

#ifdef GL_VERSION_1_2
    gluTessEndContour(tess);
#endif /* GL_VERSION_1_2 */
    gluTessEndPolygon(tess);

    /* Don't texture any more of the body... */
    glDisable(GL_TEXTURE_2D);

    /* Canopy */
    glPushMatrix();
        glColor4f(0.5, 0.5, 1.0, 0.75);
        glTranslatef(0.0, 0.2, -1.0);
	glScalef(1.0, 1.0, 0.65 / 0.15); 
	gluSphere(quadric, 0.15, 6, 12);
    glPopMatrix();

    /* Engine */
    glPushMatrix();
        /* Cowling */
        glColor3f(0.1, 0.1, 0.1);
        glTranslatef(0.0, 0.0, 2.0);
	gluCylinder(quadric, 0.25, 0.15, 0.5, 20, 2);
	gluDisk(quadric, 0.0, 0.25, 20, 2);

        /* Exhaust */
	glPushAttrib(GL_LIGHTING_BIT);
	glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
        glColor3f(0.5, 0.5, 1.0);
	gluCylinder(quadric, 0.2, 0.0, 0.3, 10, 2);
        glColor4f(0.25, 0.25, 1.0, 0.75);
	gluCylinder(quadric, 0.2, 0.1, 0.4, 10, 2);
	glPopAttrib();
    glPopMatrix();

    glEndList();

    /* Now the left rolleron */
    F16Rolleron[0] = glGenLists(1);
    glNewList(F16Rolleron[0], GL_COMPILE);

    glBindTexture(GL_TEXTURE_2D, F16Texture[0]);
    glColor3f(0.8, 0.8, 0.8);
    glNormal3f(0.0, 1.0, 0.0);
    gluTessBeginPolygon(tess, NULL);
#ifdef GL_VERSION_1_2
    gluTessBeginContour(tess);
#endif /* GL_VERSION_1_2 */

    for (i = 0; i < 4; i ++)
        gluTessVertex(tess, left_rolleron[i], left_rolleron[i]);

#ifdef GL_VERSION_1_2
    gluTessEndContour(tess);
#endif /* GL_VERSION_1_2 */
    gluTessEndPolygon(tess);

    glEndList();

    /* And the right rolleron */
    F16Rolleron[1] = glGenLists(1);
    glNewList(F16Rolleron[1], GL_COMPILE);

    glBindTexture(GL_TEXTURE_2D, F16Texture[0]);
    glColor3f(0.8, 0.8, 0.8);
    glNormal3f(0.0, 1.0, 0.0);
    gluTessBeginPolygon(tess, NULL);
#ifdef GL_VERSION_1_2
    gluTessBeginContour(tess);
#endif /* GL_VERSION_1_2 */

    for (i = 0; i < 4; i ++)
        gluTessVertex(tess, right_rolleron[i], right_rolleron[i]);

#ifdef GL_VERSION_1_2
    gluTessEndContour(tess);
#endif /* GL_VERSION_1_2 */
    gluTessEndPolygon(tess);

    glEndList();

    gluDeleteQuadric(quadric);
    gluDeleteTess(tess);
    }


/*
 * 'glu_vertex()' - Set a vertex.
 */

void APIENTRY
glu_vertex(GLdouble *xyz)  /* I - XYZ location + ST texture coordinate */
    {
    glTexCoord2dv(xyz + 3);
    glVertex3dv(xyz);
    }


/*
 * 'GetClock()' - Return an increasing clock time in seconds...
 */

double /* O - Time in seconds */
GetClock(void)
    {
#ifdef WIN32
    SYSTEMTIME t;      /* Current time of day */

    GetSystemTime(&t);
    return (((t.wHour * 60.0) + t.wMinute) * 60 + t.wSecond +
            t.wMilliseconds * 0.001);
#else /* UNIX */
    struct timeval t; /* Current time of day */

    gettimeofday(&t, NULL);
    return ((double)t.tv_sec + 0.001 * (double)t.tv_usec);
#endif /* WIN32 */
    }


/*
 * 'Idle()' - Move the viewer and redraw...
 */

void
Idle(void)
    {
    int     i, j;         /* Column and row in terrain */
    GLfloat movex, movey; /* Scaled mouse movement */
    double  curtime;      /* Current time in milliseconds */
    GLfloat distance;     /* Distance to move */

    /* Get the current system time to figure out how far to move. */
    curtime  = GetClock();
    distance = curtime - LastTime;
    LastTime = curtime;

    /*
     * See how far the mouse pointer is from the 'center' (click)
     * position.
     */

    movex = distance * 0.2 * (MouseX - MouseStartX);
    movey = distance * 0.2 * (MouseY - MouseStartY);

    /*
     * Adjust roll, pitch, and heading according to the current
     * mouse inputs and orientation.
     */

    Orientation[0] += movey * cos(Orientation[2] * M_PI / 180.0);
    Orientation[1] += movey * sin(Orientation[2] * M_PI / 180.0);
    Orientation[2] += movex;

    if (Orientation[0] < -90.0)
        {
        Orientation[0] = -180.0 - Orientation[0];
	Orientation[2] += 180.0;
	}
    else if (Orientation[0] > 90.0)
        {
        Orientation[0] = 180.0 - Orientation[0];
	Orientation[2] -= 180.0;
	}

    if (Orientation[1] < 0.0)
        Orientation[1] += 360.0;
    else if (Orientation[1] > 360.0)
        Orientation[1] -= 360.0;

    if (Orientation[2] < -180.0)
        Orientation[2] += 360.0;
    else if (Orientation[2] > 180.0)
        Orientation[2] -= 360.0;

    glutPostRedisplay();
    }


/*
 * 'Joystick6()' - Handle joystick movement.
 */

void
Joystick(unsigned state,       /* I - Button state */
         int      x,           /* I - X position (-1000 to 1000) */
 	 int      y,           /* I - Y position (-1000 to 1000) */
	 int      z)           /* I - Z position (-1000 to 1000) */
    {
    static int last_state = 0; /* Last button state */

    if (last_state != state)
        {
	/* Button changed state; see what the new state is... */
        MouseStartX = MouseX = x / 2;
	MouseStartY = MouseY = y / 2;

	if (state && !last_state)
            {
    	    /* Start flying */
	    LastTime    = GetClock();
            glutIdleFunc(Idle);
	    }
            else if (!state && last_state)
            {
	    /* Stop flying */
            glutIdleFunc((void (*)(void))0);
	    glutPostRedisplay();
	    }

	last_state = state;
	}
    else if (state)
        {
        /* Update the joystick/mouse position */
	MouseX = x / 2;
        MouseY = y / 2;
	}
    }


/*
 * 'Keyboard()' - Handle key presses...
 */

void
Keyboard(unsigned char key, /* I - Key that was pressed */
         int           x,   /* I - Mouse X position */
	 int           y)   /* I - Mouse Y position */
    {
    switch (key)
        {
	case 0x1b :
	    exit(0);
	    break;
	case 't' :
	    UseTexturing = !UseTexturing;
	    break;
	}

    glutPostRedisplay();
    }


/*
 * 'Motion()' - Handle mouse pointer motion.
 */

void
Motion(int x, /* I - Current mouse X position */
       int y) /* I - Current mouse Y position */
    {
    MouseX = x;
    MouseY = y;
    }


/*
 * 'Mouse()' - Handle mouse button events.
 */

void
Mouse(int button, /* I - Button that changed */
      int state,  /* I - Current button states */
      int x,      /* I - Current mouse X position */
      int y)      /* I - Current mouse Y position */
    {
    MouseStartX = MouseX = x;
    MouseStartY = MouseY = y;

    if (state == GLUT_DOWN)
        {
	/* Start flying */
	LastTime    = GetClock();
        glutIdleFunc(Idle);
	}
    else
        {
	/* Stop flying */
        glutIdleFunc((void (*)(void))0);
	glutPostRedisplay();
	}
    }


/*
 * 'Redraw()' - Redraw the window...
 */

void
Redraw(void)
    {
    GLfloat        pitch, roll; /* Pitch and roll control values */
    static GLfloat sunpos[4] = { 0.7071, 0.7071, 0.0, 0.0 };
    static GLfloat suncolor[4] = { 0.5, 0.5, 0.4, 1.0 };
    static GLfloat sunambient[4] = { 0.5, 0.5, 0.4, 1.0 };

    /* Clear the window to light blue... */
    glClearColor(0.75, 0.75, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Setup viewing transformations for the current orientation... */
    glPushMatrix();
    glTranslatef(0.0, 0.0, -15.0);
    glRotatef(Orientation[1], 0.0, -1.0, 0.0);
    glRotatef(Orientation[0], 1.0, 0.0, 0.0);
    glRotatef(Orientation[2], 0.0, 0.0, -1.0);

    /* Setup lighting if needed... */
    glEnable(GL_LIGHTING);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sunambient);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, sunpos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, suncolor);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sunambient);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (UseTexturing)
	glEnable(GL_TEXTURE_2D);
    else
        glDisable(GL_TEXTURE_2D);

    // Draw the main body
    glCallList(F16Body);

    // Draw the rollerons...
    pitch = 0.1 * (MouseY - MouseStartY);
    roll  = 0.1 * (MouseX - MouseStartX);

    if (UseTexturing)
	glEnable(GL_TEXTURE_2D);

    // Left rolleron
    glPushMatrix();
        glTranslatef(0.0, 0.0, 2.0);
	glRotatef(roll - pitch, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -2.0);
	glCallList(F16Rolleron[0]);
    glPopMatrix();

    // Right rolleron
    glPushMatrix();
        glTranslatef(0.0, 0.0, 2.0);
	glRotatef(roll + pitch, -1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -2.0);
	glCallList(F16Rolleron[1]);
    glPopMatrix();

    glPopMatrix();

    /* Finish up */
    glutSwapBuffers();
    }


/*
 * 'Resize()' - Resize the window...
 */

void
Resize(int width,  /* I - Width of window */
       int height) /* I - Height of window */
    {
    /* Save the new width and height */
    Width  = width;
    Height = height;

    /* Reset the viewport... */
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(22.5, (float)width / (float)height, 0.1, 20.0);
    glMatrixMode(GL_MODELVIEW);
    }

/*
 * Motion blur example using the accumulation buffer for Chapter 11.
 *
 * Written by Michael Sweet.
 */

#include <GL/glut.h>
#include <math.h>


/*
 * Globals...
 */

int     Width;           /* Width of window */
int     Height;          /* Height of window */
GLfloat Rotation = 45.0; /* Rotation of objects */


/*
 * Functions...
 */

void Idle(void);
void Redraw(void);
void Resize(int width, int height);


/*
 * 'main()' - Open a window and display an anti-aliased scene.
 */

int                /* O - Exit status */
main(int  argc,    /* I - Number of command-line arguments */
     char *argv[]) /* I - Command-line arguments */
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_ACCUM);
    glutInitWindowSize(792, 573);
    glutCreateWindow("Motion Blur");
    glutReshapeFunc(Resize);
    glutDisplayFunc(Redraw);
    glutIdleFunc(Idle);
    glutMainLoop();
    return (0);
    }


/*
 * 'Idle()' - Rotate the scene...
 */

void
Idle()
    {
    Rotation += 5.0;
    if (Rotation >= 360.0)
      Rotation -= 360.0;

    Redraw();
    }


/*
 * 'Redraw()' - Redraw the window...
 */

void
Redraw(void)
    {
    int            i;
    static GLfloat red_light[4]  = { 1.0, 0.0, 0.0, 1.0 };
    static GLfloat red_pos[4]    = { 1.0, 1.0, 1.0, 0.0 };
    static GLfloat blue_light[4] = { 0.0, 0.0, 1.0, 1.0 };
    static GLfloat blue_pos[4]   = { -1.0, -1.0, -1.0, 0.0 };


    /* Enable drawing features that we need... */
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glShadeModel(GL_SMOOTH);

    /*
     * Draw the cube and sphere in different colors...
     *
     * We have positioned two lights in this scene.  The first is red
     * and located above, to the right, and behind the viewer.  The
     * second is blue and located below, to the left, and in front of
     * the viewer.
     */

    glLightfv(GL_LIGHT0, GL_DIFFUSE, red_light);
    glLightfv(GL_LIGHT0, GL_POSITION, red_pos);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, blue_light);
    glLightfv(GL_LIGHT1, GL_POSITION, blue_pos);

    /* Draw the objects 6 times... */
    for (i = 0; i < 6; i ++)
        {
        /* Clear the color and depth buffers... */
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* Draw the objects */
        glPushMatrix();
        glTranslatef(0.0, 0.0, -20.0);
        glRotatef(Rotation - 5.0 * (float)i, 0.0, 1.0, 0.0);

        glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0);
        glutSolidSphere(1.0, 36, 18);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef(15.0, 0.0, 1.0, 0.0);
        glRotatef(15.0, 0.0, 0.0, 1.0);
        glutSolidCube(2.0);
        glPopMatrix();
        glPopMatrix();

        /* Accumulate the frame... */
        if (i == 0)
          glAccum(GL_LOAD, 0.5);
        else
          glAccum(GL_ACCUM, 0.1);
        }

    /* Copy the accumulated results back to the color buffer... */
    glAccum(GL_RETURN, 1.0);

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
    gluPerspective(22.5, (float)width / (float)height, 0.1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    }

// Shadow.c
// OpenGL SuperBible, Chapter 6
// Demonstrates simple planar shadows
// Program by Richard S. Wright Jr.

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>


// Define a constant for the value of PI
#define GL_PI 3.1415f

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

// These values need to be available globally
// Light values and coordinates
GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat	 lightPos[] = { -75.0f, 150.0f, -50.0f, 0.0f };
GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };

// Transformation matrix to project shadow
GLfloat shadowMat[4][4];


// Reduces a normal vector specified as a set of three coordinates,
// to a unit normal vector of length one.
void ReduceToUnit(float vector[3])
	{
	float length;
	
	// Calculate the length of the vector		
	length = (float)sqrt((vector[0]*vector[0]) + 
						(vector[1]*vector[1]) +
						(vector[2]*vector[2]));

	// Keep the program from blowing up by providing an exceptable
	// value for vectors that may calculated too close to zero.
	if(length == 0.0f)
		length = 1.0f;

	// Dividing each element by the length will result in a
	// unit normal vector.
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
	}


// Points p1, p2, & p3 specified in counter clock-wise order
void calcNormal(float v[3][3], float out[3])
	{
	float v1[3],v2[3];
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;

	// Calculate two vectors from the three points
	v1[x] = v[0][x] - v[1][x];
	v1[y] = v[0][y] - v[1][y];
	v1[z] = v[0][z] - v[1][z];

	v2[x] = v[1][x] - v[2][x];
	v2[y] = v[1][y] - v[2][y];
	v2[z] = v[1][z] - v[2][z];

	// Take the cross product of the two vectors to get
	// the normal vector which will be stored in out
	out[x] = v1[y]*v2[z] - v1[z]*v2[y];
	out[y] = v1[z]*v2[x] - v1[x]*v2[z];
	out[z] = v1[x]*v2[y] - v1[y]*v2[x];

	// Normalize the vector (shorten length to one)
	ReduceToUnit(out);
	}

// Creates a shadow projection matrix out of the plane equation
// coefficients and the position of the light. The return value is stored
// in destMat[][]
void MakeShadowMatrix(GLfloat points[3][3], GLfloat lightPos[4], GLfloat destMat[4][4])
	{
	GLfloat planeCoeff[4];
	GLfloat dot;

	// Find the plane equation coefficients
	// Find the first three coefficients the same way we
	// find a normal.
	calcNormal(points,planeCoeff);

	// Find the last coefficient by back substitutions
	planeCoeff[3] = - (
		(planeCoeff[0]*points[2][0]) + (planeCoeff[1]*points[2][1]) +
		(planeCoeff[2]*points[2][2]));


	// Dot product of plane and light position
	dot = planeCoeff[0] * lightPos[0] +
			planeCoeff[1] * lightPos[1] +
			planeCoeff[2] * lightPos[2] +
			planeCoeff[3] * lightPos[3];

	// Now do the projection
	// First column
    destMat[0][0] = dot - lightPos[0] * planeCoeff[0];
    destMat[1][0] = 0.0f - lightPos[0] * planeCoeff[1];
    destMat[2][0] = 0.0f - lightPos[0] * planeCoeff[2];
    destMat[3][0] = 0.0f - lightPos[0] * planeCoeff[3];

	// Second column
	destMat[0][1] = 0.0f - lightPos[1] * planeCoeff[0];
	destMat[1][1] = dot - lightPos[1] * planeCoeff[1];
	destMat[2][1] = 0.0f - lightPos[1] * planeCoeff[2];
	destMat[3][1] = 0.0f - lightPos[1] * planeCoeff[3];

	// Third Column
	destMat[0][2] = 0.0f - lightPos[2] * planeCoeff[0];
	destMat[1][2] = 0.0f - lightPos[2] * planeCoeff[1];
	destMat[2][2] = dot - lightPos[2] * planeCoeff[2];
	destMat[3][2] = 0.0f - lightPos[2] * planeCoeff[3];

	// Fourth Column
	destMat[0][3] = 0.0f - lightPos[3] * planeCoeff[0];
	destMat[1][3] = 0.0f - lightPos[3] * planeCoeff[1];
	destMat[2][3] = 0.0f - lightPos[3] * planeCoeff[2];
	destMat[3][3] = dot - lightPos[3] * planeCoeff[3];
	}


////////////////////////////////////////////////
// This function just specifically draws the jet
void DrawJet(BOOL bShadow)
	{
	float normal[3];	// Storeage for calculated surface normal

	// Nose Cone /////////////////////////////
	// Set material color, note we only have to set to black
	// for the shadow once
	if(!bShadow)
		glColor3ub(0, 255, 0);
	else
		glColor3ub(0,0,0);


	glBegin(GL_TRIANGLES);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 60.0f);
		glVertex3f(-15.0f, 0.0f, 30.0f);
		glVertex3f(15.0f,0.0f,30.0f);

	    {
	    // Verticies for this panel
	    static float v[3][3] =	{{ 15.0f, 0.0f, 30.0f},
					    { 0.0f, 15.0f, 30.0f},
					    { 0.0f, 0.0f,	60.0f}};

	    // Calculate the normal for the plane
	    calcNormal(v,normal);

	    // Draw the triangle using the plane normal
	    // for all the vertices
		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }	

	    {
	    static float v[3][3] = {{ 0.0f, 0.0f, 60.0f },
					     { 0.0f, 15.0f, 30.0f },
					     { -15.0f, 0.0f, 30.0f }};

	    calcNormal(v,normal);

		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }



	    // Body of the Plane ////////////////////////
	    // light gray
	    if(!bShadow)
		    glColor3ub(192,192,192);
	    {
	    static float v[3][3] = {{ -15.0f,0.0f,30.0f },
				     { 0.0f, 15.0f, 30.0f },
				     { 0.0f, 0.0f, -56.0f }};

	    calcNormal(v,normal);
		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }
	    
	    {
	    static float v[3][3] = {{ 0.0f, 0.0f, -56.0f },
					     { 0.0f, 15.0f, 30.0f },
					     { 15.0f,0.0f,30.0f }};
	    calcNormal(v,normal);
		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);	
	    }
	    
		    
		    glNormal3f(0.0f, -1.0f, 0.0f);
		    glVertex3f(15.0f,0.0f,30.0f);
		    glVertex3f(-15.0f, 0.0f, 30.0f);
		    glVertex3f(0.0f, 0.0f, -56.0f);


	    ///////////////////////////////////////////////
	    // Left wing
	    // Large triangle for bottom of wing
	    // Dark gray

	    // Set drawing color
	    if(!bShadow)
		    glColor3ub(128,128,128);
	    {
	    static float v[3][3] = {{ 0.0f,2.0f,27.0f },
				     { -60.0f, 2.0f, -8.0f },
				     { 60.0f, 2.0f, -8.0f }};

	    // Calculate the normal from the verticies
	    calcNormal(v,normal);

		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }
	    
	    {
	    static float v[3][3] =    {{ 60.0f, 2.0f, -8.0f},
					    {0.0f, 7.0f, -8.0f},
					    {0.0f,2.0f,27.0f }};

	    calcNormal(v,normal);

		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }

	    {
	    static float v[3][3] = {{60.0f, 2.0f, -8.0f},
					    {-60.0f, 2.0f, -8.0f},
					    {0.0f,7.0f,-8.0f }};

	    calcNormal(v,normal);

		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }

	    {
	    static float v[3][3] = {{0.0f,2.0f,27.0f},
					     {0.0f, 7.0f, -8.0f},
					     {-60.0f, 2.0f, -8.0f}};

	    calcNormal(v,normal);
	    
	    // Other wing top section
		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }


	    // Tail section///////////////////////////////
	    // Bottom of back fin
	    if(!bShadow)
		    glColor3ub(255,255,0);
	    
		    glNormal3f(0.0f, -1.0f, 0.0f);
		    glVertex3f(-30.0f, -0.50f, -57.0f);
		    glVertex3f(30.0f, -0.50f, -57.0f);
		    glVertex3f(0.0f,-0.50f,-40.0f);

	    {
	    static float v[3][3] = {{ 0.0f,-0.5f,-40.0f },
					    {30.0f, -0.5f, -57.0f},
					    {0.0f, 4.0f, -57.0f }};

	    calcNormal(v,normal);

	    // top of left side
		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }

	    {
	    static float v[3][3] = {{ 0.0f, 4.0f, -57.0f },
					    { -30.0f, -0.5f, -57.0f },
					    { 0.0f,-0.5f,-40.0f }};

	    calcNormal(v,normal);

	    // top of right side
		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }

	    {
	    static float v[3][3] = {{ 30.0f,-0.5f,-57.0f },
					    { -30.0f, -0.5f, -57.0f },
					    { 0.0f, 4.0f, -57.0f }};

	    calcNormal(v,normal);

	    // back of bottom of tail
		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }

	    {
	    static float v[3][3] = {{ 0.0f,0.5f,-40.0f },
					    { 3.0f, 0.5f, -57.0f },
					    { 0.0f, 25.0f, -65.0f }};

	    calcNormal(v,normal);

	    // Top of Tail section left
	    if(!bShadow)
		    glColor3ub(255,0,0);
	    
		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }

	    {
	    static float v[3][3] = {{ 0.0f, 25.0f, -65.0f },
					    { -3.0f, 0.5f, -57.0f},
					    { 0.0f,0.5f,-40.0f }};

	    calcNormal(v,normal);

		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    }

	    {
	    static float v[3][3] = {{ 3.0f,0.5f,-57.0f },
					    { -3.0f, 0.5f, -57.0f },
					    { 0.0f, 25.0f, -65.0f }};

	    calcNormal(v,normal);

	    // Back of horizontal section
		    glNormal3fv(normal);
		    glVertex3fv(v[0]);
		    glVertex3fv(v[1]);
		    glVertex3fv(v[2]);
	    glEnd();
	    }
	}

// Called to draw scene
void RenderScene(void)
	{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw the ground, we do manual shading to a darker green
	// in the background to give the illusion of depth
	glBegin(GL_QUADS);
		glColor3ub(0,32,0);
		glVertex3f(400.0f, -150.0f, -200.0f);
		glVertex3f(-400.0f, -150.0f, -200.0f);
		glColor3ub(0,255,0);
		glVertex3f(-400.0f, -150.0f, 200.0f);
		glVertex3f(400.0f, -150.0f, 200.0f);
	glEnd();

	// Save the matrix state and do the rotations
	glPushMatrix();

	// Draw jet at new orientation, put light in correct position
	// before rotating the jet
    glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	DrawJet(FALSE);

	// Restore original matrix state
	glPopMatrix();	


	// Get ready to draw the shadow and the ground
	// First disable lighting and save the projection state
    glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glPushMatrix();

	// Multiply by shadow projection matrix
	glMultMatrixf((GLfloat *)shadowMat);

	// Now rotate the jet around in the new flattend space
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	// Pass true to indicate drawing shadow
	DrawJet(TRUE);	

	// Restore the projection to normal
	glPopMatrix();

	// Draw the light source
	glPushMatrix();
	glTranslatef(lightPos[0],lightPos[1], lightPos[2]);
	glColor3ub(255,255,0);
	glutSolidSphere(5.0f,10,10);
	glPopMatrix();

	// Restore lighting state variables
    glEnable(GL_DEPTH_TEST);

	// Display the results
	glutSwapBuffers();
	}

// This function does any needed initialization on the rendering
// context. 
void SetupRC()
	{
	// Any three points on the ground (counter clockwise order)
	GLfloat points[3][3] = {{ -30.0f, -149.0f, -20.0f },
							{ -30.0f, -149.0f, 20.0f },
							{ 40.0f, -149.0f, 20.0f }};

	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
	glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

	// Setup and enable light 0
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	glEnable(GL_LIGHT0);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);
	
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity
	// with a high shine
	glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
	glMateriali(GL_FRONT,GL_SHININESS,128);

	// Light blue background
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f );

	// Calculate projection matrix to draw shadow on the ground
	MakeShadowMatrix(points, lightPos, shadowMat);
	}

void SpecialKeys(int key, int x, int y)
	{
	if(key == GLUT_KEY_UP)
		xRot-= 5.0f;

	if(key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if(key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if(key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if(key > 356.0f)
		xRot = 0.0f;

	if(key < -1.0f)
		xRot = 355.0f;

	if(key > 356.0f)
		yRot = 0.0f;

	if(key < -1.0f)
		yRot = 355.0f;

	// Refresh the Window
	glutPostRedisplay();
	}


void ChangeSize(int w, int h)
	{
	GLfloat nRange = 200.0f;
	GLfloat fAspect;

	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	
	// Set Viewport to window dimensions
    glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	fAspect = (GLfloat)w/(GLfloat)h;

	gluPerspective(60.0f, fAspect, 1.0, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Move out Z axis so we can see everything
	glTranslatef(0.0f, 0.0f, -400.0f);
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	}

int main(int argc, char* argv[])
	{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Shadow");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();

	return 0;
	}

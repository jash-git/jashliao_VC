#ifndef __OPENGLFUN_H__
#define __OPENGLFUN_H__
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
#define GL_PI 3.1415f
bool Line_Side=false;


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

void drawRetc(float W,float L,float H)
{

	if(Line_Side==false)
	{
	float normal[3];
	glBegin(GL_QUADS);
	{
	float v[4][3] =	{{ W/2, L/2, H/2},
					{ -W/2, L/2, H/2},
					{ -W/2,-L/2, H/2},
					{  W/2,-L/2, H/2}};

	// Calculate the normal for the plane
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{ W/2, L/2, H/2},
					{  W/2,-L/2, H/2},
					{  W/2,-L/2,-H/2},
					{  W/2, L/2,-H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{ W/2, L/2, H/2},
					{  W/2, L/2,-H/2},
					{ -W/2, L/2,-H/2},
					{ -W/2, L/2, H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{-W/2, L/2, H/2},
					{ -W/2, L/2,-H/2},
					{ -W/2,-L/2,-H/2},
					{ -W/2,-L/2, H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{-W/2,-L/2, H/2},
					{ -W/2,-L/2,-H/2},
					{  W/2,-L/2,-H/2},
					{  W/2,-L/2, H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{ W/2, L/2,-H/2},
					{  W/2,-L/2,-H/2},
					{ -W/2,-L/2,-H/2},
					{ -W/2, L/2,-H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	glEnd();
	}
	else
	{
	// 邊緣線
	int i;
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	{
		float v[4][3] = {{ W/2, L/2, H/2},
						{ -W/2, L/2, H/2},
						{ -W/2,-L/2, H/2},
						{  W/2,-L/2, H/2}};
		for(i=0; i<5; i++)
			glVertex3fv(v[i%4]);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	{
		float v[4][3] = {{ W/2, L/2,-H/2},
						{ -W/2, L/2,-H/2},
						{ -W/2,-L/2,-H/2},
						{  W/2,-L/2,-H/2}}; 
		for(i=0; i<5; i++)
		glVertex3fv(v[i%4]);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	{
		float v[4][3] = {{-W/2, L/2, H/2},
							{ -W/2,-L/2, H/2},
							{ -W/2,-L/2,-H/2},
							{ -W/2, L/2,-H/2}}; 
		for(i=0; i<5; i++)
		glVertex3fv(v[i%4]);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	{
		float v[4][3] = {{ W/2, L/2, H/2},
						{  W/2,-L/2, H/2},
						{  W/2,-L/2,-H/2},
						{  W/2, L/2,-H/2}}; 
		for(i=0; i<5; i++)
		glVertex3fv(v[i%4]);
	}
	glEnd();
	// 邊緣線(完)
	}
}

void drawTrapezoid(float W_UP, float W_DOWN, float L, float H)
{
	float normal[3];
	glBegin(GL_QUADS);
	{
	float v[4][3] =	{{ W_UP/2, L/2, H/2},
					{ -W_UP/2, L/2, H/2},
					{ -W_UP/2,-L/2, H/2},
					{  W_UP/2,-L/2, H/2}};

	// Calculate the normal for the plane
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{ W_UP/2, L/2, H/2},
					{  W_UP/2,-L/2, H/2},
					{  W_DOWN/2,-L/2,-H/2},
					{  W_DOWN/2, L/2,-H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{ W_UP/2, L/2, H/2},
					{  W_DOWN/2, L/2,-H/2},
					{ -W_DOWN/2, L/2,-H/2},
					{ -W_UP/2, L/2, H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{-W_UP/2, L/2, H/2},
					{ -W_DOWN/2, L/2,-H/2},
					{ -W_DOWN/2,-L/2,-H/2},
					{ -W_UP/2,-L/2, H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{-W_UP/2,-L/2, H/2},
					{ -W_DOWN/2,-L/2,-H/2},
					{  W_DOWN/2,-L/2,-H/2},
					{  W_UP/2,-L/2, H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	{
	float v[4][3] = {{ W_DOWN/2, L/2,-H/2},
					{  W_DOWN/2,-L/2,-H/2},
					{ -W_DOWN/2,-L/2,-H/2},
					{ -W_DOWN/2, L/2,-H/2}};   
	calcNormal(v,normal);
	glNormal3fv(normal);
	glVertex3fv(v[0]);
	glVertex3fv(v[1]);
	glVertex3fv(v[2]);
	glVertex3fv(v[3]);
	}
	glEnd();
}

void drawCir(float radius, float L, int segment)
{
	float angle[2];
	float normal[3];
	if(Line_Side==false)
	{
	glBegin(GL_QUADS);
	{
		for(angle[0]=0.0f, angle[1]=0.0f; angle[0]< (2.0f*GL_PI); angle[0]+=((2.0f*GL_PI)/segment))
		{
			float r[4][3] = {{radius*(float)cos(angle[1]), radius*(float)sin(angle[1]), L/2}, 
							{ radius*(float)cos(angle[1]), radius*(float)sin(angle[1]),-L/2},  
							{ radius*(float)cos(angle[0]), radius*(float)sin(angle[0]),-L/2},
							{ radius*(float)cos(angle[0]), radius*(float)sin(angle[0]), L/2}};
			calcNormal(r,normal);
			glNormal3fv(normal);
			glVertex3fv(r[0]);
			glVertex3fv(r[1]);
			glVertex3fv(r[2]);
			glVertex3fv(r[3]);
			angle[1]=angle[0];
		}
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3f(0.0f, 0.0f, L/2);
		for (angle[1]=0.0f, angle[0]=0.0f; angle[1]<=(2.0f*GL_PI); angle[0]+=((2.0f*GL_PI)/segment))
		{
			float x=radius*(float)cos(angle[0]);
			float y=radius*(float)sin(angle[0]);

			float v[3][3] = {{0.0f                , 0.0f                , L/2},
							{ radius*(float)cos(angle[1]), radius*(float)sin(angle[1]), L/2},   
							{ radius*(float)cos(angle[0]), radius*(float)sin(angle[0]), L/2}};
			calcNormal(v,normal);
			glNormal3fv(normal);
			glVertex3f(x, y, L/2);
			angle[1]=angle[0];
		}
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3f(0.0f, 0.0f,-L/2);
		for (angle[1]=0.0f, angle[0]=0.0f; angle[1]<= (2.0f*GL_PI); angle[0]+=((2.0f*GL_PI)/segment))
		{
			float x=radius*(float)cos(angle[0]);
			float y=radius*(float)sin(angle[0]);		
			float v[3][3] = {{0.0f                , 0.0f                ,-L/2},
							{ radius*(float)cos(angle[0]), radius*(float)sin(angle[0]),-L/2},   
							{ radius*(float)cos(angle[1]), radius*(float)sin(angle[1]),-L/2}};
			calcNormal(v,normal);
			glNormal3fv(normal);
			glVertex3f(x, y,-L/2);
			angle[1]=angle[0];
		}
	}
	glEnd();
	}
	else
	{
// 線條邊緣
	
	float start_point[16][3];
	float end_point[16][3];
	int k=0;
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	{
		float angle,x,y,z;
		for (angle=0.0f; angle <= (2.0f*GL_PI); angle+=((2.0f*GL_PI)/segment))
		{
			x = radius*(float)cos(angle);
			y = radius*(float)sin(angle);
			start_point[k][0]=x;
			start_point[k][1]=y;
			z = L/2;
			start_point[k][2]=z;
			k+=1;
			glVertex3f(x, y, z);
		}
	}
	glEnd();
	k=0;
	glBegin(GL_LINE_STRIP);
	{
		float angle,x,y,z;
		for (angle=0.0f; angle <= (2.0f*GL_PI); angle+=((2.0f*GL_PI)/segment))
		{
			x = radius*(float)cos(angle);
			y = radius*(float)sin(angle);
			end_point[k][0]=x;
			end_point[k][1]=y;
			z = -L/2;
			end_point[k][2]=z;
			k+=1;
			glVertex3f(x, y, z);
		}
	}
	glEnd();
	for(int i=0;i<16;i++)
	{
		glBegin(GL_LINES);
		{
			glVertex3f(start_point[i][0], start_point[i][1], start_point[i][2]);
			glVertex3f(end_point[i][0], end_point[i][1], end_point[i][2]);
		}
		glEnd();
	}
	}
}
#endif
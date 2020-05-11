/* FILE: model.c
 *		Reads animated model files and renders them
 *
 * Monstrous Software (c) 2000-2001
 * http://home.planet.nl/~monstrous
 *
 * MS3D file format loading based on MSViewer by Mete Ciragan, MilkShape3D
 *
 * Defines classes: Vec, Shape, Material, Bone and Model
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <assert.h>

#include "model.h" 
#include "tga.h" 
#include "Matrix.h"


// Vector x Matrix (based on Brett Porter's Vector class)
//
void Vec::transform( const Matrix& m )
{
	double vector[4];
	const float *matrix = m.getMatrix();

	vector[0] = x*matrix[0]+y*matrix[4]+z*matrix[8]+matrix[12];
	vector[1] = x*matrix[1]+y*matrix[5]+z*matrix[9]+matrix[13];
	vector[2] = x*matrix[2]+y*matrix[6]+z*matrix[10]+matrix[14];
	vector[3] = x*matrix[3]+y*matrix[7]+z*matrix[11]+matrix[15];

	x = ( float )( vector[0] );
	y = ( float )( vector[1] );
	z = ( float )( vector[2] );
	w = ( float )( vector[3] );
}

void Vec::transform3( const Matrix& m )
{
	double vector[3];
	const float *matrix = m.getMatrix();

	vector[0] = x*matrix[0]+y*matrix[4]+z*matrix[8];
	vector[1] = x*matrix[1]+y*matrix[5]+z*matrix[9];
	vector[2] = x*matrix[2]+y*matrix[6]+z*matrix[10];

	x = ( float )( vector[0] );
	y = ( float )( vector[1] );
	z = ( float )( vector[2] );
}

/*
 * Shape 
 */

Shape::Shape()
{
	num_vertices = 0;
	vertices = NULL;
	num_triangles = 0;
	triangles = NULL;
	num_normals = 0;
	normals = NULL;
}

Shape::~Shape()
{
	if(vertices != NULL)
		delete[] vertices;	
	if(triangles != NULL)
		delete[] triangles;
	if(normals != NULL)
		delete[] normals;
}


bool Shape::loadFromFile( const char *filename )
{
	FILE	*fp;
	int	i;

	fp = fopen(filename, "r");
	if(fp == NULL)
		return false;

	fscanf(fp, "%d\n", &num_vertices );

	vertices = new Vec[num_vertices];

	for(i = 0 ; i < num_vertices; i++)
	{
		fscanf(fp, "%f %f %f %f %f\n", 
				&vertices[i].x,
				&vertices[i].y,
				&vertices[i].z,
				&vertices[i].u,
				&vertices[i].v );
	}

	fscanf(fp, "%d\n", &num_triangles );

	triangles = new Tri[num_triangles];
	for(i = 0 ; i < num_triangles; i++)
	{
		fscanf(fp, "%d %d %d\n",
				&triangles[i].v[0],
				&triangles[i].v[1],
				&triangles[i].v[2] );
	}

	fclose(fp);
	
	return true;
}

bool Shape::saveToFile( const char *filename )
{
	FILE	*fp;
	int	i;

	fp = fopen(filename, "w");
	if(fp == NULL)
		return false;

	fprintf(fp, "%d\n", num_vertices );

	for(i = 0 ; i < num_vertices; i++)
	{
		fprintf(fp, "%f %f %f %f %f\n", 
				vertices[i].x,
				vertices[i].y,
				vertices[i].z,
				vertices[i].u,
				vertices[i].v );
	}

	fprintf(fp, "%d\n", num_triangles );

	for(i = 0 ; i < num_triangles; i++)
	{
		fprintf(fp, "%d %d %d\n",
				triangles[i].v[0],
				triangles[i].v[1],
				triangles[i].v[2] );
	}
	fclose(fp);
	return true;
}


void Shape::render( void )
{
	int	i,j;
	Tri	*tri;
	Vec	*vec;
	Normal *N;

//	glEnable(GL_LIGHTING);
	glBegin(GL_TRIANGLES);
	for(i = 0; i < num_triangles; i++)	// for each triangle
	{
		tri = triangles + i;				// pointer to triangle

		for(j = 0; j < 3; j++)	// 3 vertices of the triangle
		{
			N = normals + tri->n[j];
			glNormal3f(N->x, N->y, N->z);	// set normal vector  (object space)

			vec = vertices + tri->v[j];		// pointer to vertex
			glTexCoord2f (vec->u, vec->v);			// texture coordinate

			glVertex3f( vec->x, vec->y, vec->z );	// 3d coordinate (object space)
		}
	}
	glEnd();
}



bool Shape::loadFromMs3dAsciiSegment( FILE *file )
{
    bool bError = false;
    char szLine[256];
    int nFlags, nIndex, j;


                //
                // vertices
                //
                if (!fgets (szLine, 256, file))
                {
					return false;
                }

                if (sscanf (szLine, "%d", &num_vertices) != 1)
                {
					return false;
                }
				vertices = new Vec[num_vertices];

                for (j = 0; j < num_vertices; j++)
                {
                    if (!fgets (szLine, 256, file))
                    {
						return false;
		            }
                    if (sscanf (szLine, "%d %f %f %f %f %f %d",
                        &nFlags,
                        &vertices[j].x, &vertices[j].y, &vertices[j].z,
                        &vertices[j].u, &vertices[j].v,
                        &vertices[j].bone
                        ) != 7)
                   {
 					return false;
                   }
					// adjust the y direction of the texture coordinate
					vertices[j].v = 1.0f - vertices[j].v;
                }

                //
                // normals
                //
                if (!fgets (szLine, 256, file))
                {
					return false;
                }

                if (sscanf (szLine, "%d", &num_normals) != 1)
                {
 					return false;
                }
				normals = new Normal[num_normals];

                for (j = 0; j < num_normals; j++)
                {
                    if (!fgets (szLine, 256, file))
                    {
					return false;
                    }

                    if (sscanf (szLine, "%f %f %f", 
						&normals[j].x, &normals[j].y, &normals[j].z) != 3)
                    {
 					return false;
                   }
                }
                //
                // triangles
                //
                if (!fgets (szLine, 256, file))
                {
					return false;
                }

                if (sscanf (szLine, "%d", &num_triangles) != 1)
                {
 					return false;
               }
				triangles = new Tri[num_triangles];

                for (j = 0; j < num_triangles; j++)
                {
                    if (!fgets (szLine, 256, file))
                    {
 					return false;
                    }

                    if (sscanf (szLine, "%d %d %d %d %d %d %d %d",
                        &nFlags,
                        &triangles[j].v[0], &triangles[j].v[1], &triangles[j].v[2],
                        &triangles[j].n[0], &triangles[j].n[1], &triangles[j].n[2],
                        &nIndex
                        ) != 8)
                    {
 					return false;
                    }
					assert(triangles[j].v[0] >= 0);
					assert(triangles[j].v[0] < num_vertices);
					assert(triangles[j].v[1] >= 0);
					assert(triangles[j].v[1] < num_vertices);
					assert(triangles[j].v[2] >= 0);
					assert(triangles[j].v[2] < num_vertices);
				}

	return true;
}

/*
 * Material 
 */

Material::Material()	
{
}

Material::~Material()	
{
}

void Material::activate( void )
{
	glMaterialfv( GL_FRONT, GL_AMBIENT, Ambient );
	glMaterialfv( GL_FRONT, GL_DIFFUSE, Diffuse );
	glMaterialfv( GL_FRONT, GL_SPECULAR, Specular );
	glMaterialfv( GL_FRONT, GL_EMISSION, Emissive );
	glMaterialf( GL_FRONT, GL_SHININESS, Shininess );

	if ( texture > 0 )
	{
		glBindTexture( GL_TEXTURE_2D, texture );
		glEnable( GL_TEXTURE_2D );
	}
	else
		glDisable( GL_TEXTURE_2D );
}

bool Material::loadFromMs3dAsciiSegment( FILE *file )
{
    char szLine[256];

    // name
    if (!fgets (szLine, 256, file))
		return false;
    if (sscanf (szLine, "\"%[^\"]\"", Name) != 1)
		return false;

	// ambient
    if (!fgets (szLine, 256, file))
		return false;

	if (sscanf (szLine, "%f %f %f %f", &Ambient[0], &Ambient[1], &Ambient[2], &Ambient[3]) != 4)
		return false;

    // diffuse
    if (!fgets (szLine, 256, file))
		return false;
    if (sscanf (szLine, "%f %f %f %f", &Diffuse[0], &Diffuse[1], &Diffuse[2], &Diffuse[3]) != 4)
		return false;

    // specular
    if (!fgets (szLine, 256, file))
		return false;
    if (sscanf (szLine, "%f %f %f %f", &Specular[0], &Specular[1], &Specular[2], &Specular[3]) != 4)
		return false;

    // emissive
    if (!fgets (szLine, 256, file))
		return false;
    if (sscanf (szLine, "%f %f %f %f", &Emissive[0], &Emissive[1], &Emissive[2], &Emissive[3]) != 4)
		return false;

    // shininess
    if (!fgets (szLine, 256, file))
		return false;
    if (sscanf (szLine, "%f", &Shininess) != 1)
		return false;

    // transparency
    if (!fgets (szLine, 256, file))
		return false;
    if (sscanf (szLine, "%f", &Transparency) != 1)
		return false;

    // diffuse texture
    if (!fgets (szLine, 256, file))
		return false;
	strcpy(DiffuseTexture, "");
    sscanf (szLine, "\"%[^\"]\"", DiffuseTexture);

    // alpha texture
    if (!fgets (szLine, 256, file))
		return false;
	strcpy(AlphaTexture, "");
    sscanf (szLine, "\"%[^\"]\"", AlphaTexture);

	reloadTexture();

	return true;
}

void Material::reloadTexture( void )
{
	if( strlen(DiffuseTexture) > 0 )
		loadTargaTexture(DiffuseTexture, &texture);
	else
		texture = 0;
}


Bone::Bone()	
{
}

Bone::~Bone()	
{
	if(PositionKeyFrames != NULL)
	{
		delete[] PositionKeyFrames;
		PositionKeyFrames = NULL;
	}

	if(RotationKeyFrames != NULL)
	{
		delete[] RotationKeyFrames;
		RotationKeyFrames = NULL;
	}
}

void Bone::render( void )
{
	Vec	vector;
	Vec	parentvector;

	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	vector.w = 1;
	vector.transform( m_final );

	if( Parent != NULL )
	{
		parentvector.x = 0;
		parentvector.y = 0;
		parentvector.z = 0;
		parentvector.w = 1;
		parentvector.transform( Parent->m_final );
	}

	glDisable( GL_TEXTURE_2D );
//	glDisable(GL_LIGHTING);

	// render bone as a line
	glLineWidth(1.0);
	glColor3f(1.0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f( vector.x, vector.y, vector.z );
	if(Parent != NULL)
		glVertex3f( parentvector.x, parentvector.y, parentvector.z );	
	else
		glVertex3f( vector.x, vector.y, vector.z );
	glEnd();

	// render bone-ends as fat points
	glPointSize(2.0);
	glColor3f(1.0, 0, 1.0);
	glBegin(GL_POINTS);
	glVertex3f( vector.x, vector.y, vector.z );
	if(Parent != NULL)
		glVertex3f( parentvector.x, parentvector.y, parentvector.z );	
	glEnd();
	glColor3f(1.0, 1.0, 1.0);

}

bool Bone::loadFromMs3dAsciiSegment( FILE *file )
{
    char szLine[256];
	int	 j;
	int	 nFlags;

    // name
    if (!fgets (szLine, 256, file))
		return false;

    if (sscanf (szLine, "\"%[^\"]\"", Name) != 1)
		return false;

    // parent name
    if (!fgets (szLine, 256, file))
		return false;
    strcpy (ParentName, "");
    sscanf (szLine, "\"%[^\"]\"", ParentName);


	if (!fgets (szLine, 256, file))
		return false;
    if (sscanf (szLine, "%d %f %f %f %f %f %f",
                    &nFlags,
                    &startPosition[0], &startPosition[1], &startPosition[2],
                    &startRotation[0], &startRotation[1], &startRotation[2]) != 7)
		return false;
 
 
    // position key count
    if (!fgets (szLine, 256, file))
		return false;
    if (sscanf (szLine, "%d", &NumPositionKeys) != 1)
		return false;

	PositionKeyFrames = new KeyFrame[NumPositionKeys];
    for (j = 0; j < NumPositionKeys; j++)
    {
		if (!fgets (szLine, 256, file))
			return false;
        if (sscanf (szLine, "%f %f %f %f", &PositionKeyFrames[j].Time,
			&PositionKeyFrames[j].Value[0],
			&PositionKeyFrames[j].Value[1],
			&PositionKeyFrames[j].Value[2] ) != 4)
 			return false;
    }

    // rotation key count
    if (!fgets (szLine, 256, file))
		return false;
    if (sscanf (szLine, "%d", &NumRotationKeys) != 1)
		return false;

	RotationKeyFrames = new KeyFrame[NumRotationKeys];
    for (j = 0; j < NumRotationKeys; j++)
    {
		if (!fgets (szLine, 256, file))
			return false;
        if (sscanf (szLine, "%f %f %f %f", &RotationKeyFrames[j].Time,
			&RotationKeyFrames[j].Value[0],
			&RotationKeyFrames[j].Value[1],
			&RotationKeyFrames[j].Value[2] ) != 4)
  			return false;
    }
	
	return true;
}

void Bone::initialize( void )
{
	Matrix m_rel;

	// Create a transformation matrix from the position and rotation 
	m_rel.setRotationRadians( startRotation );
	m_rel.setTranslation( startPosition );

	// Each bone's final matrix is its relative matrix concatenated onto its 
	// parent's final matrix (which in turn is ....)
	//
	if ( Parent == NULL )
		m_final.set( m_rel.getMatrix());
	else
	{
		m_final.set( Parent->m_final.getMatrix());
		m_final.postMultiply( m_rel );
	}
}

void Bone::advanceTo( float CurrentTime )
{
	int		i;
	float	deltaTime;
	float	fraction;
	float	Position[3];
	float	Rotation[3];


	/* 
	 * Position
	 */

	// Find appropriate position key frame
	i = 0;
	while( i < NumPositionKeys-1 && PositionKeyFrames[i].Time < CurrentTime )
		i++;

	assert(i < NumPositionKeys);

	if( i > 0 && i < NumPositionKeys-1 )
	{
		// Interpolate between 2 key frames

		// time between the 2 key frames
		deltaTime = PositionKeyFrames[i].Time - PositionKeyFrames[i-1].Time;

		assert( deltaTime > 0 );

		// relative position of interpolation point to the keyframes [0..1]
		fraction = (CurrentTime - PositionKeyFrames[i-1].Time) / deltaTime;

		assert( fraction > 0 );
		assert( fraction < 1.0 );

		Position[0] = PositionKeyFrames[i-1].Value[0] + fraction * (PositionKeyFrames[i].Value[0] - PositionKeyFrames[i-1].Value[0]);
		Position[1] = PositionKeyFrames[i-1].Value[1] + fraction * (PositionKeyFrames[i].Value[1] - PositionKeyFrames[i-1].Value[1]);
		Position[2] = PositionKeyFrames[i-1].Value[2] + fraction * (PositionKeyFrames[i].Value[2] - PositionKeyFrames[i-1].Value[2]);
	}
	else
	{
		memcpy(Position, PositionKeyFrames[i].Value, 3*sizeof(float) );
	}

	/* 
	 * Rotation
	 */

	// Find appropriate rotation key frame
	i = 0;
	while( i < NumRotationKeys-1 && RotationKeyFrames[i].Time < CurrentTime )
		i++;

	assert(i < NumRotationKeys);

	if( i > 0 && i < NumRotationKeys-1 )
	{
		// Interpolate between 2 key frames

		// time between the 2 key frames
		deltaTime = RotationKeyFrames[i].Time - RotationKeyFrames[i-1].Time;
		assert( deltaTime > 0 );

		// relative position of interpolation point to the keyframes [0..1]
		fraction = (CurrentTime - RotationKeyFrames[i-1].Time) / deltaTime;
		assert( fraction > 0 );
		assert( fraction < 1.0 );

		Rotation[0] = RotationKeyFrames[i-1].Value[0] + fraction * (RotationKeyFrames[i].Value[0] - RotationKeyFrames[i-1].Value[0]);
		Rotation[1] = RotationKeyFrames[i-1].Value[1] + fraction * (RotationKeyFrames[i].Value[1] - RotationKeyFrames[i-1].Value[1]);
		Rotation[2] = RotationKeyFrames[i-1].Value[2] + fraction * (RotationKeyFrames[i].Value[2] - RotationKeyFrames[i-1].Value[2]);
	}
	else
	{
		memcpy(Rotation, RotationKeyFrames[i].Value, 3*sizeof(float) );
	}

	// Now we know the position and rotation for this animation frame.
	// Let's calculate the transformation matrix (m_final) for this bone...

	Matrix m_rel;
	Matrix m_frame;

	// Create a transformation matrix from the position and rotation of this
	// joint in the rest position
	m_rel.setRotationRadians( startRotation );
	m_rel.setTranslation( startPosition );

	// Create a transformation matrix from the position and rotation 
	// m_frame: additional transformation for this frame of the animation 
	m_frame.setRotationRadians( Rotation );
	m_frame.setTranslation( Position );

	// Add the animation state to the rest position
	m_rel.postMultiply( m_frame );

	// 
	if ( Parent == NULL )					// this is the root node
		m_final.set( m_rel.getMatrix());	// m_final := m_rel
	else									// not the root node
	{
		// m_final := parent's m_final * m_rel (matrix concatenation)

		m_final.set( Parent->m_final.getMatrix());
		m_final.postMultiply( m_rel );
	}
}

/*
 * Model 
 */

Model::Model()
{
	num_shapes = 0;
	shapes = NULL;
	num_materials = 0;
	materials = NULL;
}

Model::~Model()
{

	if(shapes != NULL)
	{
		delete[] shapes;
		shapes = NULL;
	}
	if(materials != NULL)
	{
		delete[] materials;
		materials = NULL;
	}
	if(material_indices != NULL)
	{
		delete[] material_indices;
		material_indices = NULL;
	}
}

bool Model::loadFromMs3dAsciiFile( const char *filename )
{
	float	StartTime;
    bool	bError = false;
    char	szLine[256];
    int		nFlags, nIndex, i;

	FILE *file = fopen (filename, "rt");
	if (!file)
		return false;

	CurrentTime = 0;
	num_shapes = -1;

    while (fgets (szLine, 256, file) != NULL  && !bError)
    {
        if (!strncmp (szLine, "//", 2))
            continue;


        int nFrame;
        if (sscanf (szLine, "Frames: %d", &nFrame) == 1)
        {
			MaxTime = 1.0f * nFrame;		// length of animation 
            continue;
        }
        if (sscanf (szLine, "Frame: %d", &nFrame) == 1)
        {
			StartTime = 1.0f * nFrame;
            continue;
        }


        if (sscanf (szLine, "Meshes: %d", &num_shapes) == 1)
        {
			char	szName[MS_MAX_NAME];
	
			shapes = new Shape[num_shapes];
			material_indices = new int[num_shapes];

            for (i = 0; i < num_shapes && !bError; i++)
            {

                if (!fgets (szLine, 256, file))
                {
                    bError = true;
                    break;
                }

                // mesh: name, flags, material index
                if (sscanf (szLine, "\"%[^\"]\" %d %d",szName, &nFlags, &nIndex) != 3)
                {
                    bError = true;
                    break;
                }
				material_indices[i] = nIndex;

				if( ! shapes[i].loadFromMs3dAsciiSegment(file) )
                {
                    bError = true;
                    break;
                }
			}
            continue;
		}

        //
        // materials
        //
        if (sscanf (szLine, "Materials: %d", &num_materials) == 1)
        {
            int i;

			materials = new Material[num_materials];

            for (i = 0; i < num_materials && !bError; i++)
            {
 				if( ! materials[i].loadFromMs3dAsciiSegment(file) )
                {
                    bError = true;
                    break;
                }
			}
            continue;
        }

		
        //
        // bones
        //
        if (sscanf (szLine, "Bones: %d", &num_bones) == 1)
        {
            int i;

			bones = new Bone[num_bones];

            for (i = 0; i < num_bones && !bError; i++)
            {
				if( ! bones[i].loadFromMs3dAsciiSegment(file) )
                {
                    bError = true;
                    break;
                }
            }
            continue;
        }
    }

	fclose (file);

	if(bError || num_shapes <= 0)
		return false;

	if( !linkBones() )
		return false;
	initializeBones();
	attachSkin();
	advanceAnimation( StartTime );
	return true;
}

bool Model::linkBones( void )
{
	// The relationship between child and parent bones are defined
	// by each child bone providing the name of its parent bone.
	// This function builds corresponding pointers for faster lookup.
	//
	int i, j;

	// Link children to parent
	//

    for (i = 0; i < num_bones; i++)            
	{
		bones[i].Parent = NULL;

		if( strlen(bones[i].ParentName) >  0 )	// does bone have parent?
		{
			for (j = 0; j < num_bones; j++)	// search for parent
			{
				if( stricmp(bones[j].Name, bones[i].ParentName) == 0)	// j is parent of i
				{
					bones[i].Parent = &bones[j];
					break;
				}
			}
			if ( bones[i].Parent == NULL) // Unable to find parent bone 
				return false;
        }
    }
	
	return true;
}

void Model::initializeBones( void )
{
	int i;

    for (i = 0; i < num_bones; i++)            
	{
		bones[i].initialize();
    }
}

// TODO: Uses private members from various classes (temporarily made public). Clean up!
//
void Model::attachSkin( void )
{
	int		i, j;
	int		bone;
	Matrix	*matrix;
	float	v[3];


	// Make vertex vector relative to the bone it's attached to

	for( i = 0; i < num_shapes; i++)	// for all shapes
	{	
		for(j = 0; j < shapes[i].num_vertices; j++ )	// for all vertices
		{
			bone = shapes[i].vertices[j].bone;

			if( bone != -1 )	// if vertex attached to a bone
			{
				matrix = & bones[bone].m_final;

				// make relative to bone position and orientation
				// modifies vertex x,y,z 

				v[0] = shapes[i].vertices[j].x;
				v[1] = shapes[i].vertices[j].y;
				v[2] = shapes[i].vertices[j].z;
				matrix->inverseTranslateVect( v );
				matrix->inverseRotateVect( v );
				shapes[i].vertices[j].x = v[0];
				shapes[i].vertices[j].y = v[1];
				shapes[i].vertices[j].z = v[2];
			}

		}
	}
}

void Model::renderBones( void )
{
	int	i;

	for(i = 0; i < num_bones; i++)	// for each bone
	{
		bones[i].render();	
	}
}



void Model::reloadTextures( void )
{
	int	i;

	for(i = 0; i < num_materials; i++)	// for each shape
	{
		materials[i].reloadTexture();
	}
}

#if 0
void Model::render( void )
{
	int	i;

	for(i = 0; i < num_shapes; i++)	// for each shape
	{
		int materialIndex = material_indices[i];
		if ( materialIndex >= 0 )
		{
			materials[materialIndex].activate();
		}
		else
		{
			// Material properties?
			glDisable( GL_TEXTURE_2D );
		}
		shapes[i].render();
	}
}
#endif

// renderShadow - renders a horizontal "shadow" at a given height
//					(only works if the shadow is projected onto a flat horizontal surface)
//
void Model::renderShadow( float height )
{
	int	k;
	int	i, j;
	Tri	*tri;
	Vec	*vec;
	Normal *N;
	Bone *bone;
	float	v[4];
	Matrix	*matrix;

	glDisable( GL_TEXTURE_2D );
	glDisable(GL_LIGHTING);
    glColor3f(0, 0, 0);	       

	for(k = 0; k < num_shapes; k++)	// for each shape
	{
		glBegin(GL_TRIANGLES);
		for(i = 0; i < shapes[k].num_triangles; i++)	// for each triangle
		{
			tri = shapes[k].triangles + i;				// pointer to triangle

			for(j = 0; j < 3; j++)	// 3 vertices of the triangle
			{
			vec = shapes[k].vertices + tri->v[j];		// pointer to vertex
			if( vec->bone == -1 )
			{
				glVertex3f( vec->x, height, vec->z );	// project onto shadow plane
			}
			else
			{
				
				bone = &bones[vec->bone];
				matrix = & bone->m_final;
			
				v[0] = vec->x;
				v[1] = vec->y;
				v[2] = vec->z;
				matrix->rotateVect( v );
				matrix->translateVect( v ); 
				v[1] = height;							// project onto shadow plane
				glVertex3f( v[0], v[1], v[2] );	
			}
			}
		}
		glEnd();
	}
}



void Model::render( void )
{
	int	k;
	int	i, j;
	Tri	*tri;
	Vec	*vec;
	Normal *N;
	Bone *bone;
	float	v[3];
	Matrix	*matrix;

    glColor3f(1.0, 1.0, 1.0);	// white       

	for(k = 0; k < num_shapes; k++)	// for each shape
	{
		int materialIndex = material_indices[k];
		if ( materialIndex >= 0 )
		{
			materials[materialIndex].activate();
		}
		else
		{
			// Material properties?
			glDisable( GL_TEXTURE_2D );
		}
		//shapes[i].render();



		glBegin(GL_TRIANGLES);
		for(i = 0; i < shapes[k].num_triangles; i++)	// for each triangle
		{
			tri = shapes[k].triangles + i;				// pointer to triangle

			for(j = 0; j < 3; j++)	// 3 vertices of the triangle
			{
			N = shapes[k].normals + tri->n[j];
			glNormal3f(N->x, N->y, N->z);	// set normal vector  (object space)

			vec = shapes[k].vertices + tri->v[j];		// pointer to vertex
			glTexCoord2f (vec->u, vec->v);			// texture coordinate

			if( vec->bone == -1 )
			{
				glVertex3f( vec->x, vec->y, vec->z );	
			}
			else
			{
				bone = &bones[vec->bone];
				matrix = & bone->m_final;
			
				v[0] = vec->x;
				v[1] = vec->y;
				v[2] = vec->z;
				matrix->rotateVect( v );
				matrix->translateVect( v );
				glVertex3fv( v );	
			}
			}
		}
		glEnd();
	}
}

void Model::advanceAnimation( float deltaTime )
{
	int	i;

	CurrentTime += deltaTime;
	if( CurrentTime > MaxTime )	// this is a looped animation!
		CurrentTime = 1.0;		// N.B. time starts at 1, not at 0!

    for (i = 0; i < num_bones; i++)            
	{
		bones[i].advanceTo( CurrentTime );
	}
}


	

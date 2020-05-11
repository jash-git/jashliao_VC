/* FILE: model.h
 *		Read shape files and render using AllegroGL
 *
 * C++ version
 *
 * Monstrous Software (c) 2001
 */
#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include "Matrix.h"

/* MilkShape constants */
#define MS_MAX_NAME             32
#define MS_MAX_PATH             256


class Vec
{
public:
	void	transform( const Matrix& m );
	void	transform3( const Matrix& m );

	float	x,y,z;
	float	w;		// 4th homogenous coordinate 
	float	u,v;	// texture position
	int		bone;	// index into Model bones array
};

class Tri
{
public:
	int		v[3];	// indices into vertices[]
	int		n[3];	// indices into normals[], normal per vertex
};

class Normal
{
public:
	float	x,y,z;
};
	

class Shape 
{
	public:
		/*	Constructor. */
		Shape();

		/*	Destructor. */
		~Shape();

		bool	loadFromFile( const char *filename );
		bool    loadFromMs3dAsciiSegment( FILE *file );

		bool	saveToFile( const char *filename );
		void	render( void );

//	private:
		int	num_vertices;
		Vec	*vertices;

		int	num_triangles;
		Tri	*triangles;

		int	num_normals;
		Normal	*normals;


};


class Material
{
public:
	Material();
	~Material();
	bool loadFromMs3dAsciiSegment( FILE *file );
	void activate( void );
	void reloadTexture( void );

private:
	char  Name[MS_MAX_NAME];
	float Ambient[4];
	float Diffuse[4];
	float Specular[4];
	float Emissive[4];
	float Shininess;
	float Transparency;
	char  DiffuseTexture[MS_MAX_NAME];
	char  AlphaTexture[MS_MAX_NAME];
	GLuint texture;
};

class KeyFrame
{
	public:
		float	Time;
		float	Value[3];
};

class Bone
{
	public:
		Bone();
		~Bone();
		bool	loadFromMs3dAsciiSegment( FILE *file );
		void	render( void );
		void	fixup( void );
		void	advanceTo( float time );
		void	initialize( void );
//	private:
		char	Name[MS_MAX_NAME];
		char	ParentName[MS_MAX_NAME];
		Bone	*Parent;						// pointer to parent bone (or NULL)
		float	startPosition[3];
		float	startRotation[3];
		Matrix	m_relative;				// fixed transformation matrix relative to parent 
		Matrix	m_final;				// absolute in accordance to animation
		int		NumPositionKeys;
		KeyFrame *PositionKeyFrames;
		int		NumRotationKeys;
		KeyFrame *RotationKeyFrames;
};

class Model
{
	public:
		Model();
		~Model();

		bool    loadFromMs3dAsciiFile( const char *filename );

		void	reloadTextures( void );
		void	render( void );
		void	renderShadow( float height );
		void	renderBones( void );
		bool	linkBones( void );
		void	initializeBones( void );
		void	advanceAnimation( float deltaTime );
		void	attachSkin( void );
	private:
		float	MaxTime;		// length of animation (= Frames)
		float	CurrentTime;	// advancement within animation

		int		num_shapes;
		Shape	*shapes;
		int		*material_indices;

		int		num_materials;
		Material *materials;

		int		num_bones;
		Bone	*bones;
};

	
#endif
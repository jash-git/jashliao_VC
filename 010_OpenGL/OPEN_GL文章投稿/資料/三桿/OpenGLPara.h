#ifndef __OPENGLPARA_H__
#define __OPENGLPARA_H__
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
//=========	系統參數設定 =========//

// 旋轉參數
static GLfloat xRot = 0.0f;		// X軸視角旋轉參數
static GLfloat yRot = 0.0f;		// Y軸視角旋轉參數
static GLfloat zRot = 0.0f;		// Z軸視角旋轉參數
bool Line_Flag=false;

static	GLfloat nRange = 420.0f;//空間大小

// 燈光參數
static GLfloat  ambientLight[]	= { 0.8f, 0.8f, 1.0f, 1.0f };	
static GLfloat  diffuseLight[]	= { 0.7f, 0.7f, 0.7f, 1.0f };
static GLfloat  specular[]		= { 0.7f, 0.7f, 0.7f, 1.0f };	//燈光性質
static GLfloat  specref []		= { 0.5f, 0.5f, 0.2f, 1.0f };	//反射性質
static GLfloat	lightPos[]		= { 1000.0f, 1000.0f, 1000.0f, 1.0f}; 

// 旗標參數
//static BOOL Line_flag = FALSE;
static BOOL View_lock = TRUE;
int View_flag = 5;						// 參數(預設為立體視角)
#define Up_View    1				// 上視圖
#define Front_View 2				// 前視圖
#define Back_View  3				// 後視圖
#define Right_View 4				// 右視圖
#define Left_View  5				// 左視圖
#define Orign_View 6				// 立體圖
#endif
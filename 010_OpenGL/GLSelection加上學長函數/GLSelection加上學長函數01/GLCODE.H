// glcode.h
// Declarations for external OpenGL module.  These functions are
// defined in glcode.c and are called appropriately by the CView
// derived classes.
#ifndef __GLCODE__
#define __GLCODE__

#ifdef __cplusplus

extern "C" {

#endif

	void GLSetupRC(void *pData);
	void GLRenderScene(void *pData);
	void GLResize(GLsizei h, GLsizei w);

#ifdef __cplusplus
	}
#endif


#endif // Include/Define
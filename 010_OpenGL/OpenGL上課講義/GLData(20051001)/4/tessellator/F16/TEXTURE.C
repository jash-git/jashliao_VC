/*
 * Texture image routines from Chapter 8.
 *
 * Written by Michael Sweet
 */

/*
 * Include necessary headers.
 */

#include "texture.h"


/*
 * 'TextureLoad()' - Load a bitmap file and define it as a 1D or 2D texture.
 *
 * Returns 0 on success or -1 on error.
 */

GLuint                           /* O - Texture object or 0 on error */
TextureLoad(char      *filename, /* I - Bitmap file to load */
            GLboolean alpha,     /* I - Generate alpha for bitmap */
            GLenum    minfilter, /* I - Minification filter */
	    GLenum    magfilter, /* I - Magnification filter */
	    GLenum    wrap)      /* I - Repeat or clamp */
    {
    int         i;               /* Looping var */
    BITMAPINFO	*info;           /* Bitmap information */
    GLubyte	*bits;           /* Bitmap RGB pixels */
    GLubyte     *ptr;            /* Pointer into bit buffer */
    GLubyte     temp;            /* Swapping variable */
    GLenum      type;            /* Texture type */
    GLuint      texture;         /* Texture object */

    /* Try loading the bitmap file... */
    bits = LoadDIBitmap(filename, &info);
    if (bits == NULL)
        return (0);

    /*
     * Convert the bitmap data from BGR to RGB. Since texture images
     * must be a power of two, and since we can figure that we won't
     * have a texture image as small as 2x2 pixels, we ignore any
     * alignment concerns...
     */

    for (i = info->bmiHeader.biWidth * info->bmiHeader.biHeight, ptr = bits;
         i > 0;
	 i --, ptr += 3)
        {
	/* Swap red and blue */
	temp   = ptr[0];
	ptr[0] = ptr[2];
	ptr[2] = temp;
	}

    /* Figure out the type of texture... */
    if (info->bmiHeader.biHeight == 1)
        type = GL_TEXTURE_1D;
    else
        type = GL_TEXTURE_2D;

    /* Create and bind a texture object */
    glGenTextures(1, &texture);
    glBindTexture(type, texture);

    /* Set texture parameters */
    glTexParameteri(type, GL_TEXTURE_MAG_FILTER, magfilter);
    glTexParameteri(type, GL_TEXTURE_MIN_FILTER, minfilter);
    glTexParameteri(type, GL_TEXTURE_WRAP_S, wrap);
    glTexParameteri(type, GL_TEXTURE_WRAP_T, wrap);
    glTexEnvi(type, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    /*
     * Set texture image; if the minification filter uses mip-mapping
     * then use gluBuild2D/1DMipmaps() to load the texture...
     */

    if (minfilter == GL_LINEAR || minfilter == GL_NEAREST)
        glTexImage2D(type, 0, 3, info->bmiHeader.biWidth,
                     info->bmiHeader.biHeight, 0, GL_RGB,
                     GL_UNSIGNED_BYTE, bits);
    else if (type == GL_TEXTURE_1D)
        gluBuild1DMipmaps(type, 3, info->bmiHeader.biWidth,
                          GL_RGB, GL_UNSIGNED_BYTE, bits);
    else
        gluBuild2DMipmaps(type, 3, info->bmiHeader.biWidth,
                          info->bmiHeader.biHeight, GL_RGB,
                          GL_UNSIGNED_BYTE, bits);

    /* Free the bitmap and return... */
    free(info);
    free(bits);

    return (texture);
    }

// TGA.CPP - TGA image loading

#include <stdio.h>
#include "tga.h"
#include "message.h"



typedef struct												// Create A Structure
{
	GLubyte	*imageData;										// Image Data (Up To 32 Bits)
	GLuint	bpp;											// Image Color Depth In Bits Per Pixel.
	GLuint	width;											// Image Width
	GLuint	height;											// Image Height
	GLuint	texID;											// Texture ID Used To Select A Texture
} TextureImage;	

static TextureImage the_texture;

GLubyte uTGAcompare[12] = {0,0,2, 0,0,0,0,0,0,0,0,0};	// Uncompressed TGA Header
GLubyte cTGAcompare[12] = {0,0,10,0,0,0,0,0,0,0,0,0};	// Compressed TGA Header


bool loadUncompressedTGA(TextureImage *texture, GLubyte *header, FILE *file)
{
	GLuint		bytesPerPixel;								// Holds Number Of Bytes Per Pixel Used In The TGA File
	GLuint		imageSize;									// Used To Store The Image Size When Setting Aside Ram
	GLuint		temp;										// Temporary Variable

	texture->width  = header[1] * 256 + header[0];			// Determine The TGA Width	(highbyte*256+lowbyte)
	texture->height = header[3] * 256 + header[2];			// Determine The TGA Height	(highbyte*256+lowbyte)
    
 	if(	texture->width	<=0	||								// Is The Width Less Than Or Equal To Zero
		texture->height	<=0	||								// Is The Height Less Than Or Equal To Zero
		(header[4]!=24 && header[4]!=32))					// Is The TGA 24 or 32 Bit?
	{
		fclose(file);										// If Anything Failed, Close The File
		message ("Error loading texture bitmap");
		return false;
	}

	texture->bpp	= header[4];							// Grab The TGA's Bits Per Pixel (24 or 32)
	bytesPerPixel	= texture->bpp/8;						// Divide By 8 To Get The Bytes Per Pixel
	imageSize		= texture->width*texture->height*bytesPerPixel;	// Calculate The Memory Required For The TGA Data

	texture->imageData=(GLubyte *)malloc(imageSize);		// Reserve Memory To Hold The TGA Data

	if(	texture->imageData==NULL ||							// Does The Storage Memory Exist?
		fread(texture->imageData, 1, imageSize, file)!=imageSize)	// Does The Image Size Match The Memory Reserved?
	{
		if(texture->imageData!=NULL)						// Was Image Data Loaded
			free(texture->imageData);						// If So, Release The Image Data

		fclose(file);										// Close The File
		message ("Error loading texture bitmap");
		return false;
	}

	for(int i=0; i<(int)imageSize; i+=bytesPerPixel)		// Loop Through The Image Data
	{														// Swaps The 1st And 3rd Bytes ('R'ed and 'B'lue)
		temp=texture->imageData[i];							// Temporarily Store The Value At Image Data 'i'
		texture->imageData[i] = texture->imageData[i + 2];	// Set The 1st Byte To The Value Of The 3rd Byte
		texture->imageData[i + 2] = temp;					// Set The 3rd Byte To The Value In 'temp' (1st Byte Value)
	}

	fclose (file);											// Close The File
	return true;
}



bool loadCompressedTGA(TextureImage *texture, GLubyte *header, FILE *file)
{
	GLuint		bytesPerPixel;								// Holds Number Of Bytes Per Pixel Used In The TGA File
	GLuint		imageSize;									// Used To Store The Image Size When Setting Aside Ram

	texture->width  = header[1] * 256 + header[0];			// Determine The TGA Width	(highbyte*256+lowbyte)
	texture->height = header[3] * 256 + header[2];			// Determine The TGA Height	(highbyte*256+lowbyte)
	texture->bpp	= header[4];							// Grab The TGA's Bits Per Pixel (24 or 32)
    
 	if(	texture->width	<=0	||								// Is The Width Less Than Or Equal To Zero
		texture->height	<=0	||								// Is The Height Less Than Or Equal To Zero
		(texture->bpp !=24 && texture->bpp !=32))					// Is The TGA 24 or 32 Bit?
	{
		fclose(file);										// If Anything Failed, Close The File
		message ("Error loading texture bitmap");
		exit (1);
	}

	bytesPerPixel	= texture->bpp/8;						// Divide By 8 To Get The Bytes Per Pixel
	imageSize		= texture->width*texture->height*bytesPerPixel;	// Calculate The Memory Required For The TGA Data

	texture->imageData=(GLubyte *)malloc(imageSize);		// Reserve Memory To Hold The TGA Data
	if(	texture->imageData==NULL )							// Does The Storage Memory Exist?
	{
		fclose(file);										// Close The File
		message ("Error loading texture bitmap");
		exit (1);
	}


	GLuint pixelcount	= texture->height * texture->width;							// Nuber of pixels in the image
	GLuint currentpixel	= 0;												// Current pixel being read
	GLuint currentbyte	= 0;												// Current byte 
	GLubyte * colorbuffer = (GLubyte *)malloc(bytesPerPixel);			// Storage for 1 pixel
	do
	{
		GLubyte chunkheader = 0;											// Storage for "chunk" header
		if(fread(&chunkheader, sizeof(GLubyte), 1, file) == 0)				// Read in the 1 byte header
		{
			message ("Error loading texture bitmap");
			if(file != NULL)												// If file is open
			{
				fclose(file);												// Close file
			}
			if(texture->imageData != NULL)									// If there is stored image data
			{
				free(texture->imageData);									// Delete image data
			}
			return false;													// Return failed
		}
		if(chunkheader < 128)												// If the ehader is < 128, it means the that is the number of RAW color packets minus 1
		{																	// that follow the header
			chunkheader++;													// add 1 to get number of following color values
			for(short counter = 0; counter < chunkheader; counter++)		// Read RAW color values
			{
				if(fread(colorbuffer, 1, bytesPerPixel, file) != bytesPerPixel) // Try to read 1 pixel
				{
					message ("Error loading texture bitmap");
					if(file != NULL)													// See if file is open
					{
						fclose(file);													// If so, close file
					}
					if(colorbuffer != NULL)												// See if colorbuffer has data in it
					{
						free(colorbuffer);												// If so, delete it
					}
					if(texture->imageData != NULL)										// See if there is stored Image data
					{
						free(texture->imageData);										// If so, delete it too
					}
					return false;														// Return failed
				}
																						// write to memory
				texture->imageData[currentbyte		] = colorbuffer[2];				    // Flip R and B vcolor values around in the process 
				texture->imageData[currentbyte + 1	] = colorbuffer[1];
				texture->imageData[currentbyte + 2	] = colorbuffer[0];
				if(bytesPerPixel == 4)												// if its a 32 bpp image
				{
					texture->imageData[currentbyte + 3] = colorbuffer[3];				// copy the 4th byte
				}
				currentbyte += bytesPerPixel;										// Increase thecurrent byte by the number of bytes per pixel
				currentpixel++;															// Increase current pixel by 1
				if(currentpixel > pixelcount)											// Make sure we havent read too many pixels
				{
					message ("Error loading texture bitmap");
					if(file != NULL)													// If there is a file open
					{
						fclose(file);													// Close file
					}	
					if(colorbuffer != NULL)												// If there is data in colorbuffer
					{
						free(colorbuffer);												// Delete it
					}
					if(texture->imageData != NULL)										// If there is Image data
					{
						free(texture->imageData);										// delete it
					}
					return false;														// Return failed
				}
			}
		}
		else																			// chunkheader > 128 RLE data, next color reapeated chunkheader - 127 times
		{
			chunkheader -= 127;															// Subteact 127 to get rid of the ID bit
			if(fread(colorbuffer, 1, bytesPerPixel, file) != bytesPerPixel)		// Attempt to read following color values
			{	
				message ("Error loading texture bitmap");
				if(file != NULL)														// If thereis a file open
				{
					fclose(file);														// Close it
				}
				if(colorbuffer != NULL)													// If there is data in the colorbuffer
				{
					free(colorbuffer);													// delete it
				}
				if(texture->imageData != NULL)											// If thereis image data
				{
					free(texture->imageData);											// delete it
				}
				return false;															// return failed
			}
			for(short counter = 0; counter < chunkheader; counter++)					// copy the color into the image data as many times as dictated 
			{																			// by the header
				texture->imageData[currentbyte		] = colorbuffer[2];					// switch R and B bytes areound while copying
				texture->imageData[currentbyte + 1	] = colorbuffer[1];
				texture->imageData[currentbyte + 2	] = colorbuffer[0];
				if(bytesPerPixel == 4)												// If TGA images is 32 bpp
				{
					texture->imageData[currentbyte + 3] = colorbuffer[3];				// Copy 4th byte
				}
				currentbyte += bytesPerPixel;										// Increase current byte by the number of bytes per pixel
				currentpixel++;															// Increase pixel count by 1
				if(currentpixel > pixelcount)											// Make sure we havent written too many pixels
				{
					message ("Error loading texture bitmap");
					if(file != NULL)													// If there is a file open
					{
						fclose(file);													// Close file
					}	
					if(colorbuffer != NULL)												// If there is data in colorbuffer
					{
						free(colorbuffer);												// Delete it
					}
					if(texture->imageData != NULL)										// If there is Image data
					{
						free(texture->imageData);										// delete it
					}
					return false;														// Return failed
				}
			}
		}
	}
	while(currentpixel < pixelcount);													// Loop while there are still pixels left


	fclose (file);											// Close The File
	return true;																		// return success
}

int loadTargaTexture(char *filename,  GLuint *ptex)			// Loads A TGA File Into Memory
{    
	GLubyte		TGAcompare[12];								// Used To Compare TGA Header
	GLubyte		header[6];									// First 6 Useful Bytes From The Header
	GLuint		type=GL_RGBA;								// Set The Default GL Mode To RBGA (32 BPP)
	TextureImage	*texture;
	FILE *file;

	file = fopen(filename, "rb");						// Open The TGA File

	texture = &the_texture;

	if(	file==NULL )										// Does File Even Exist?
	{
		message2 ("Cannot open texture file", filename);
		exit (1);
	}

	if(	fread(TGAcompare,1,sizeof(TGAcompare),file)!=sizeof(TGAcompare) )	// Are There 12 Bytes To Read?
	{
		fclose(file);										// If Anything Failed, Close The File
		message2 ("Error loading texture bitmap", filename);
		exit (1);
	}

	if(	fread(header,1,sizeof(header),file)!=sizeof(header))				// If So Read Next 6 Header Bytes
	{
		fclose(file);										// If Anything Failed, Close The File
		message2 ("Error loading texture bitmap", filename);
		exit (1);
	}

	if(memcmp(uTGAcompare, &TGAcompare, sizeof(TGAcompare)) == 0)				// See if header matches the predefined header of 
	{																		// an Uncompressed TGA image
		loadUncompressedTGA(texture, header, file);						// If so, jump to Uncompressed TGA loading code
	}
	else if(memcmp(cTGAcompare, &TGAcompare, sizeof(TGAcompare)) == 0)		// See if header matches the predefined header of
	{																		// an RLE compressed TGA image
		loadCompressedTGA(texture, header, file);					  // If so, jump to Compressed TGA loading code
	}



	// Build A Texture From The Data
	glGenTextures(1, &texture->texID);					// Generate OpenGL texture IDs

	glBindTexture(GL_TEXTURE_2D, texture->texID);			// Bind Our Texture
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtered
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// Linear Filtered
	
	if (texture->bpp==24)									// Was The TGA 24 Bits
	{
		type=GL_RGB;										// If So Set The 'type' To GL_RGB
	}

	glTexImage2D(GL_TEXTURE_2D, 0, type, texture->width, texture->height, 0, type, GL_UNSIGNED_BYTE, texture->imageData);

	*ptex = texture->texID;

	return 1;											// Texture Building Went Ok, Return True
}

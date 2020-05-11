// StrXorEncoder.h: interface for the CStrXorEncoder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRXORENCODER_H__BE1F991B_2B11_45DB_8D1E_E7572A101F99__INCLUDED_)
#define AFX_STRXORENCODER_H__BE1F991B_2B11_45DB_8D1E_E7572A101F99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStrXorEncoder  
{
public:
	CStrXorEncoder();
	/*
		char gchrxor[]="what is a c/p programmer?";
		input:	char *chrS	char	¡uchrDecoder[1000]		int len¡v
		output:	¡uintEncoder[1000]	XorEncoderªº¦^¶Ç­È¡v	char chrDecoder[1000]	
	*/
	int intEncoder[1000];//Encoder output
	int intDecoder[1000];//Decoder input
	char chrDecoder[1000];//Decoder output
	int XorEncoder(char *chrS);
	void XorDecoder(int len);
	virtual ~CStrXorEncoder();

};

#endif // !defined(AFX_STRXORENCODER_H__BE1F991B_2B11_45DB_8D1E_E7572A101F99__INCLUDED_)

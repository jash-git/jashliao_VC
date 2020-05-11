// matrix1to2to1.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "matrix1to2to1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CMatrix1to2to1App
void EXPORTED_DLL_FUNCTION GetValue1(long *p,long x,long y)
{
	int i,j,k,l;
	FILE *pf;
	pf=fopen("text.txt","w");
	image_in = new int*[x];
	for(i=0;i<x;i++)
		image_in[i] = new int[y];
	
	k=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			l=p[k];
			*(*(image_in+i)+j)=0;
			*(*(image_in+i)+j) = p[k];
			fprintf(pf,"%d\n",*(*(image_in+i)+j));
			k++;
		}
	}
	fclose(pf);
	lngSize=x*y;
	gx=x;
	gy=y;
}
void EXPORTED_DLL_FUNCTION SetValue1(long *p)
{
	p[0]=lngSize;
}
void EXPORTED_DLL_FUNCTION SetValue2(long *p)
{
	int i,j,l,k;
	k=0;
	for(i=0;i<gx;i++)
	{
		for(j=0;j<gy;j++)
		{
			l=*(*(image_in+i)+j);
			p[k]=l;
			k++;
		}
	}
}
void EXPORTED_DLL_FUNCTION DeleteArray()
{
	int i;
	for(i=0;i<gx;i++)
	{
		delete [] image_in[i];
	}
	delete [] image_in;
}
BEGIN_MESSAGE_MAP(CMatrix1to2to1App, CWinApp)
	//{{AFX_MSG_MAP(CMatrix1to2to1App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMatrix1to2to1App construction

CMatrix1to2to1App::CMatrix1to2to1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMatrix1to2to1App object

CMatrix1to2to1App theApp;

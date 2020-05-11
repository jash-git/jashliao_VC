#include <string.h>
#include <stdio.h>
#include <windows.h>
////////////////////////////////////////////////////////////////
//linux
/*
//http://linux.die.net/man/3/dlopen
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int main(int argc, char **argv) {
    void *handle;
    double (*cosine)(double);
    char *error;
    handle = dlopen ("libm.so", RTLD_LAZY);
    if (!handle) {
        fprintf (stderr, "%s\n", dlerror());
        exit(1);
    }
    dlerror();    //Clear any existing error
    cosine = dlsym(handle, "cos");
    if ((error = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", error);
        exit(1);
    }
    printf ("%f\n", (*cosine)(2.0));
    dlclose(handle);
    return 0;
}
*/
//dlopen代替Loadlibrary 
//dlsym代替GetProcAddress
//dlclose代替FreeLibrary
////////////////////////////////////////////////////////////////
//GetProcAddresses
//Argument1: hLibrary - Handle for the Library Loaded
//Argument2: lpszLibrary - Library to Load
//Argument3: nCount - Number of functions to load
//[Arguments Format]
//Argument4: Function Address - Function address we want to store
//Argument5: Function Name -  Name of the function we want
//[Repeat Format]
//
//Returns: FALSE if failure
//Returns: TRUE if successful
BOOL GetProcAddresses( HINSTANCE *hLibrary, 
       LPCSTR lpszLibrary, INT nCount, ... )
{
	 va_list va;
	 va_start( va, nCount );
	 if ( ( *hLibrary = LoadLibrary( lpszLibrary ) ) 
	  != NULL )
	 {
		  FARPROC * lpfProcFunction = NULL;
		  LPSTR lpszFuncName = NULL;
		  INT nIdxCount = 0;
		while ( nIdxCount < nCount )
		{
		   lpfProcFunction = va_arg( va, FARPROC* );
		   lpszFuncName = va_arg( va, LPSTR );
		   if ( ( *lpfProcFunction = GetProcAddress( *hLibrary, lpszFuncName ) ) == NULL )
		   {
				lpfProcFunction = NULL;
				return FALSE;
		   }
		   nIdxCount++;
		}
	 }
	 else
	 {
		  va_end( va );
		  return FALSE;
	 }
	 va_end( va );
	 return TRUE;
}
 
typedef int ( WINAPI *MESSAGEBOX )  ( HWND , LPCSTR, LPCSTR, DWORD );
typedef int ( WINAPI *MESSAGEBOXEX )( HWND , LPCSTR, LPCSTR, DWORD , WORD );
typedef BOOL(WINAPI *ISCHARUPPER) (TCHAR );
typedef LPTSTR ( WINAPI *CHARUPPER )( LPTSTR );

void main(void)
{
	 
	 MESSAGEBOX  lpfMsgBox = NULL;
	 MESSAGEBOXEX lpfMsgBoxEx = NULL;
	 CHARUPPER lpfCharUpper = NULL;
	 ISCHARUPPER lpfIsCharUpper = NULL;
	 HINSTANCE hLib;
	 if(GetProcAddresses( &hLib, "User32.dll", 4, 
	  &lpfMsgBox, "MessageBoxA",
	  &lpfMsgBoxEx, "MessageBoxExA" ,
	  &lpfCharUpper, "CharUpperA",
	  &lpfIsCharUpper, "IsCharUpperA")) //參考depends,以序號方式載入，
	 {
		  lpfMsgBox( 0, "Test1", "Test1", MB_OK );
		  lpfMsgBoxEx( 0, "Test2", "Test2", MB_OK, MAKELANGID( LANG_ENGLISH, SUBLANG_ENGLISH_US ) );
		  char aa[120] = "aB";
		  printf("result = %s\n", aa);
		  BOOL b = IsCharUpper( 'A');
		  b = lpfIsCharUpper( 'b');
		  CharLowerA(aa);
		  printf("result = %s\n", aa); 	
		  lpfCharUpper(aa);
		  printf("result = %s\n", aa); 		  
	 }
	 if ( hLib != NULL )
	  FreeLibrary( hLib );
 
}

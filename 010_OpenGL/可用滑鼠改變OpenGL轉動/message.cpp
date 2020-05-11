

#include <windows.h>		// Header File For Windows


void message( char * str )
{
		MessageBox( NULL, str, "Error", MB_OK | MB_ICONERROR );
}

void message2( char * str, char *s2 )
{
	char	line[256];

	strcpy(line, str);
	strcat(line, ": ");
	strcat(line, s2);

	MessageBox( NULL, line, "Error", MB_OK | MB_ICONERROR );
}
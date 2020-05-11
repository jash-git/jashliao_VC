//GlobalVarApp2View.h
long glngViewWide;
long glngViewhigh;
char MAP_NAME0[20]=	"spacesoft1 corp0.";
char MAP_NAME1[20]=	"spacesoft1 corp1.";
char MAP_NAME2[20]=	"spacesoft1 corp2.";
char MAP_NAME3[20]=	"spacesoft1 corp3.";
#define	MAP_LENGTH	8
HANDLE hFileMap[4] ={NULL,NULL,NULL,NULL} ;
static char szOldData[MAP_LENGTH] = "" ;
LPVOID mapView[4];

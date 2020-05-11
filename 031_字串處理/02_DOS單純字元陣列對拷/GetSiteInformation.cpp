#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct SiteInformation
{
	long lngNO;
	char strSiteName[100];
	long lngX;
	long lngY;
};
FILE *pfdata=NULL;
struct SiteInformation *pSiteInformation;
void main(void)
{
	long lngMarrValue=0;
	long lngBufer=0;
	long lngNO;
	char strSiteName[100];
	long lngX;
	long lngY; 
	pfdata=fopen("規劃資料.txt","r");
	while(fscanf(pfdata,"%ld%s%ld%ld",&lngNO,strSiteName,&lngX,&lngY)!=EOF)
		lngMarrValue++;
	fclose(pfdata);
	cout<<lngMarrValue<<"\n";
	pSiteInformation=new SiteInformation[lngMarrValue];
	pfdata=fopen("規劃資料.txt","r");
	lngBufer=0;
	while(fscanf(pfdata,"%ld%s%ld%ld",&lngNO,strSiteName,&lngX,&lngY)!=EOF)
	{
		pSiteInformation[lngBufer].lngNO=lngNO;
		strcpy(pSiteInformation[lngBufer].strSiteName,strSiteName); 
		pSiteInformation[lngBufer].lngX=lngX;
		pSiteInformation[lngBufer].lngY=lngY; 
		cout<<pSiteInformation[lngBufer].lngNO <<"\t";
		cout<<pSiteInformation[lngBufer].strSiteName <<"\t";
		cout<<pSiteInformation[lngBufer].lngX <<"\t";
		cout<<pSiteInformation[lngBufer].lngY <<"\n";
		lngBufer++;
	}
	fclose(pfdata);
}
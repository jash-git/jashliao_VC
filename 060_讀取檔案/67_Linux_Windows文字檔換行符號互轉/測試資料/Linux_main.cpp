// place your code here
#include <QCoreApplication>
#include <QTextCodec>
#include<QDateTime>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
<HTML>
<HEAD>
<!-- -->
<FRAMESET rows="25%,*"><!-- 產生2列 -->
  <FRAME src="top.htm" NAME="Top"/><!-- 第一列 只有一個頁面 -->
  <FRAMESET cols="20%,*"><!--第二列 產生兩行 -->
    <FRAME src="" NAME="Left"/>
    <FRAME src="" NAME="Main"/>
  </FRAMESET>
</FRAMESET>
</HEAD>
</HTML>
 */
int main(int argc, char *argv[])
{
	//QCoreApplication app(argc, argv);
	QTextCodec ::setCodecForTr(QTextCodec ::codecForName("UTF-8"));
	QTextCodec ::setCodecForCStrings(QTextCodec ::codecForName("UTF-8"));
	//========
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	QDateTime dateTime = QDateTime::currentDateTime();
	//========
	printf("Content-type:text/html\r\n\r\n");
	
	//========
	printf("<HTML>\r\n\r\n");
	printf("<HEAD>\r\n\r\n");
	printf("<!-- -->\r\n\r\n");
	printf("\t<FRAMESET rows=\"25%,*\"><!-- 產生2列 -->\r\n\r\n");
	printf("\t\t<FRAME src=\"/cgi-bin/top.cgi\" NAME=\"Top\"/><!-- 第一列 只有一個頁面 -->\r\n\r\n");
	printf("\t\t<FRAMESET cols=\"20%,*\"><!--第二列 產生兩行 -->\r\n\r\n");
    printf("\t\t\t<FRAME src=\"\" NAME=\"Left\"/>\r\n\r\n");
    printf("\t\t\t<FRAME src=\"\" NAME=\"Main\"/>\r\n\r\n");
	printf("\t<\t/FRAMESET>\r\n\r\n");
	printf("\t</FRAMESET>\r\n\r\n");
	printf("</HEAD>\r\n\r\n");
	printf("</HTML>\r\n\r\n");	
	//========
	FILE *pf;
	char *postdata='\0';
	pf=fopen("lasttime.log","w");
	fprintf(pf,"Now Time: %d-%d-%d %d:%d:%d",(now->tm_year + 1900),(now->tm_mon + 1),now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
	postdata = getenv("QUERY_STRING"); 
	if(postdata !='\0')
	{
		fprintf(pf,"\tdata=%s",postdata);
	}
	fclose(pf);	
	//======== 
	return 0;
	//return app.exec();
}
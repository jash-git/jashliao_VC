#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void KeepSession(char *chrUrl)
{
    char chrData[256];
    chrData[0]='\0';
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(chrData,"wget --keep-session-cookies --save-cookies cookie.txt \"%s?date=%d%d%d%d%d%d\" -O KeepSession.html",chrUrl, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	//printf("%s\n",chrData);
	system(chrData);
}
void TouchAD(char *chrUrl)
{
    char chrData[256];
    chrData[0]='\0';
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(chrData,"wget --keep-session-cookies --load-cookies cookie.txt \"%s&date=%d%d%d%d%d%d\" -O TouchAD.html",chrUrl, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	//printf("%s\n",chrData);
	system(chrData);
}
int main()
{
    KeepSession("http://www.nownews.com");
    int i=0;
    for(i=0;i<10;i++)
    {
        system("ping 127.0.0.1");
    }
    TouchAD("http://ad1.nownews.com/adclick.php?ownerid=176&bannerid=29146");
    printf("Hello world!\n");
    return 0;
}

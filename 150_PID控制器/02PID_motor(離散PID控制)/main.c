#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
PID控制器驗證（C++）
//離散方式所以沒有取樣時間參數
資料來源: http://blog.sina.com.cn/s/blog_408540af0100as56.html

*/
typedef struct PID{
	double Command; //輸入指令
	double Proportion;  //比例係數
	double Integral;   //積分係數
	double Derivative;  //微分係數
	double preErr;    //前一拍誤差
	double sumErr;    //誤差累積
}PID;

double PIDCale(PID *p,double feedback)
{
	double dErr,Err;
	Err=p->Command-feedback;  //當前誤差
	p->sumErr+=Err;      //誤差累加
	dErr=Err-p->preErr;   //誤差微分
	p->preErr=Err;
	return(p->Proportion*Err  //比例項
	+p->Derivative*dErr   //微分項
	+p->Integral*p->sumErr);  //積分項
}
void PIDInit(PID *p)
{
	memset(p,0,sizeof(PID));  //初始化
}
typedef struct motor{
	double lastY;
	double preY;
	double lastU;
	double preU;
}motor;
void motorInit(motor *m)
{
	memset(m,0,sizeof(motor));
}
double motorCal(motor *m,double u)
{
	double y=1.9753*m->lastY-0.9753*m->preY+0.00003284*u+0.00006568*m->lastU+0.00003284*m->preU;//二階系統
	m->preY=m->lastY;
	m->lastY=y;
	m->preU=m->lastU;
	m->lastU=u;
	return y;
}
void main()
{
	FILE *fp=fopen("data.txt","w+");
	PID sPID;
	double u;
	double y=0;
	PIDInit(&sPID);
	sPID.Proportion=2;//Kp
	sPID.Derivative=10;//Kd
	sPID.Integral=0.00001;//Ki
	sPID.Command=10;//setpoint
	motor m_motor;//受控體
	motorInit(&m_motor);
	int k=0;
	while(k<=1000)
	{
		fprintf(fp,"%f %f\n",y,sPID.Command);
		u=PIDCale(&sPID,y);
		y=motorCal(&m_motor,u);
		k++;
	}
	printf("%f\n",y);
	fclose(fp);
}

